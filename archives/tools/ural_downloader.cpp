#include <Core>

#include <boost/filesystem.hpp>

#include <curl/curl.h>
#include <curl/easy.h>

str USER,USERID,PASS;

size_t write_data(char *data,size_t size,size_t num,string* buffer)
{
    buffer->append(data,size*num);
    return size*num;
}

str page_url;
str page_content;
size_t page_count;
str file_url;
str file_content;
str contest_url;
str contest_content;
void save_file(str filename)
{
	cerr<<"save()"<<endl;
	str id=filename;
	str type=file_url.substr(file_url.find_last_of('.'),sz(file_url)-(file_url.find_last_of('.')));
	if (!boost::filesystem::exists(id+".java")
		&&!boost::filesystem::exists(id+".c")
		&&!boost::filesystem::exists(id+".pas")
		&&!boost::filesystem::exists(id+".cpp"))
	{
		str output;
		rep(i,sz(file_content)) if (file_content[i]!='\r') output.pb(file_content[i]);
		ofstream file(id+type);
		file<<output;
	}
	cerr<<"/save()"<<endl;
}
void download_file(str filename)
{
	cerr<<"download_file()"<<endl;
	string buffer;
	CURL *curl=curl_easy_init();
	curl_easy_setopt(curl,CURLOPT_URL,file_url.c_str());
	curl_easy_setopt(curl,CURLOPT_POST,1);
	str post="Action=getsubmit&JudgeID="+USER+"&Password="+PASS;
    curl_easy_setopt(curl,CURLOPT_POSTFIELDS,post.c_str());
	curl_easy_setopt(curl,CURLOPT_FOLLOWLOCATION,1);
	curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_data);
	curl_easy_setopt(curl,CURLOPT_WRITEDATA,&buffer);
	curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	buffer.swap(file_content);
	save_file(filename);
	cerr<<"/download_file()"<<endl;
}
void get_contest_filename(str& filename)
{
	cerr<<"get_contest_filename()"<<endl;
	string buffer;
	CURL *curl=curl_easy_init();
	curl_easy_setopt(curl,CURLOPT_URL,contest_url.c_str());
	curl_easy_setopt(curl,CURLOPT_FOLLOWLOCATION,1);
	curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_data);
	curl_easy_setopt(curl,CURLOPT_WRITEDATA,&buffer);
	curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	buffer.swap(contest_content);
	size_t p=contest_content.find("To submit the solution for this problem go to the Problem set:");
	p=contest_content.find("<nobr>",p)+sz(str("<nobr>"));
	size_t q=contest_content.find(".",p);
	filename=contest_content.substr(p,q-p);
	cerr<<"/get_contest_filename()"<<endl;
}
void get_file_url()
{
	size_t p=0;
	lp
	{
		p=page_content.find("getsubmit.aspx/",p);
		if (p==str::npos) break;
		size_t q=page_content.find('"',p);
		file_url="http://acm.timus.ru/"+page_content.substr(p,q-p);
		q=page_content.find("<SPAN CLASS=\"problemname\">",p);
		p=q;
		whl(page_content[p-1]!='>') p--;
		str filename=page_content.substr(p,q-p);
		bool isNumber=true;
		rep(i,sz(filename)) if (filename[i]>'9'||filename[i]<'0') isNumber=false;
		if (!isNumber)
		{
			q=p-2;
			p=q;
			whl(page_content[p-1]!='"') p--;
			str suffix=page_content.substr(p,q-p);
			whl(suffix.find("amp;")!=str::npos)
				suffix.erase(suffix.find("amp;"),sz(str("amp;")));
			contest_url="http://acm.timus.ru/"+suffix;
			get_contest_filename(filename);
		}
		download_file(filename);
	}
}
void download_page()
{
	cerr<<"Page "<<++page_count<<": "<<page_url<<endl;
	cerr<<"download_page()"<<endl;
	string buffer;
	CURL *curl=curl_easy_init();
	curl_easy_setopt(curl,CURLOPT_URL,page_url.c_str());
	curl_easy_setopt(curl,CURLOPT_FOLLOWLOCATION,1);
	curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_data);
	curl_easy_setopt(curl,CURLOPT_WRITEDATA,&buffer);
	curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	buffer.swap(page_content);
	get_file_url();
	cerr<<"/download_page()"<<endl;
}
bool has_next_page()
{
	size_t p=page_content.find("Next 10");
	if (p==str::npos) rtn false;
	size_t q=page_content.find("\">Next 10</A>");
	p=q;
	whl(page_content[p-1]!='"') p--;
	str suffix=page_content.substr(p,q-p);
	whl(suffix.find("amp;")!=str::npos)
		suffix.erase(suffix.find("amp;"),sz(str("amp;")));
	page_url="http://acm.timus.ru/"+suffix;
	rtn true;
}

int main()
{
	cout<<"Username:"<<flush;
	cin>>USER;
	cout<<"PASSWORD:"<<flush;
	cin>>PASS;
	curl_global_init(CURL_GLOBAL_ALL);
	stringstream sin(USER);
	int getuserid;
	sin>>getuserid;
	stringstream sout;
	sout<<getuserid;
	USERID=sout.str();
	page_url="http://acm.timus.ru/status.aspx?author="+USERID+"&status=accepted";
	do download_page();
	whl(has_next_page());
	cout<<"Enter 'q' to quit."<<endl<<flush;;
	whl(cin.get()!='q');
}
