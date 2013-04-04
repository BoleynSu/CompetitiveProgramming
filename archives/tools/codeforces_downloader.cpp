#include <Core>

#include <boost/filesystem.hpp>

#include <curl/curl.h>
#include <curl/easy.h>

str USER,PASS;

size_t write_data(char *data,size_t size,size_t num,string* buffer)
{
    buffer->append(data,size*num);
    return size*num;
}

str page_url;
str page_content;
size_t page_count;
str contest;
str file_url;
str file_content;
void save_file()
{
	cerr<<"save()"<<endl;
	const str getid("\"/contest/"+contest+"/problem/");
	static const str begincode("<pre class=\"prettyprint\" style=\"padding:0.5em;\">");
	static const str endcode("</pre>");

	str id=contest+file_content.substr(file_content.find(getid)+sz(getid),1);

	size_t p=file_content.find(getid);
	p=file_content.find("<td>",p);
	size_t q=file_content.find("</td>",p);
	str lang=file_content.substr(p,q-p);

	str type;
	if (lang.find("C++")!=str::npos) type=".cpp";
	else if (file_content.find("Java")!=str::npos) type=".java";
	else if (file_content.find("PHP")!=str::npos) type=".php";
	else type=".txt";
	if (!boost::filesystem::exists(id+".java")
		&&!boost::filesystem::exists(id+".cpp")
		&&!boost::filesystem::exists(id+".txt")
		&&!boost::filesystem::exists(id+".php"))
	{
		str output;
		size_t p=file_content.find(begincode)+sz(begincode);
		size_t q=file_content.find(endcode,p);
		repf(i,p,q) if (file_content[i]!='\r') output.pb(file_content[i]);
		output.pb('\n');
		ofstream file(id+type);
		rep(i,sz(output))
		{
			if (output[i]!='&') file<<output[i];
			else
			{
				int j=i;
				whl(output[++j]!=';') ;
				if (output[i+1]=='a') file<<'&';
				else if (output[i+1]=='q') file<<'\"';
				else if (output[i+1]=='l') file<<'<';
				else if (output[i+1]=='g') file<<'>';
				i=j;
			}
		}
	}
	cerr<<"/save()"<<endl;
}
void download_file()
{
	cerr<<"download_file()"<<endl;
	string buffer;
	CURL *curl=curl_easy_init();
	curl_easy_setopt(curl,CURLOPT_URL,file_url.c_str());
	curl_easy_setopt(curl,CURLOPT_FOLLOWLOCATION,1);
	curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_data);
	curl_easy_setopt(curl,CURLOPT_WRITEDATA,&buffer);
	curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	buffer.swap(file_content);
	save_file();
	cerr<<"/download_file()"<<endl;
}
void get_file_url()
{
	static const str subbegin(" data-submission-id=\""),subend("\"");
	static const str idbegin("<a href=\"/problemset/problem/"),idend("/");
	static const str gym("<a href=\"/problemset/gymProblem");

	size_t p=0;
	lp
	{
		p=page_content.find(subbegin,p);
		if (p==str::npos) break;
		p+=sz(subbegin);
		size_t q=page_content.find(subend,p);
		str sub=page_content.substr(p,q-p);
		if (page_content.find(idbegin,p)>=page_content.find(gym,p)) continue;
		p=page_content.find(idbegin,p)+sz(idbegin);
		q=page_content.find(idend,p);
		contest=page_content.substr(p,q-p);
		file_url="http://codeforces.com/contest/"+contest+"/submission/"+sub;

		size_t x=page_content.find(subbegin,p);
		size_t y=page_content.find("<span class='verdict-accepted'>Accepted</span>",p);
		if (y<x) download_file();
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
	static const str beginpage("href=\""),endpage("\"");
	size_t p=page_content.find("page-index",page_content.find("page-index active")+1);
	if (p==str::npos) rtn false;
	p=page_content.find(beginpage,p)+sz(beginpage);
	size_t q=page_content.find(endpage,p);
	page_url="http://codeforces.com"+page_content.substr(p,q-p);
	rtn true;
}

int main()
{
	cout<<"Username:"<<flush;
	cin>>USER;
	curl_global_init(CURL_GLOBAL_ALL);
	page_url="http://codeforces.com/submissions/"+USER+"/page/1";
	do download_page();
	whl(has_next_page());
	cout<<"Enter 'q' to quit."<<endl<<flush;
	whl(cin.get()!='q');
}
