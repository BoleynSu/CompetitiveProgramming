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

void login()
{
	cerr<<"login()"<<endl;
	string buffer;
	CURL *curl=curl_easy_init();
	curl_easy_setopt(curl,CURLOPT_URL,"http://acm.hdu.edu.cn/userloginex.php?action=login");
	curl_easy_setopt(curl,CURLOPT_POST,1);
	curl_easy_setopt(curl,CURLOPT_COOKIEFILE,"cookie.txt");
	curl_easy_setopt(curl,CURLOPT_COOKIEJAR,"cookie.txt");
	str post="username="+USER+"&userpass="+PASS+"&login=Sign+In";
    curl_easy_setopt(curl,CURLOPT_POSTFIELDS,post.c_str());
	curl_easy_setopt(curl,CURLOPT_FOLLOWLOCATION,1);
	curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_data);
	curl_easy_setopt(curl,CURLOPT_WRITEDATA,&buffer);
	curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	cerr<<"/login()"<<endl;
}

str page_url;
str page_content;
size_t page_count;
str file_url;
str file_content;
void save_file()
{
	cerr<<"save()"<<endl;
	static const str getid("showproblem.php?pid=");
	static const str begincode("<textarea id=usercode style=\"display:none;text-align:left;\">");
	static const str endcode("</textarea>");
	str id=file_content.substr(file_content.find(getid)+sz(getid),4);
	str type;
	if (file_content.find("Language : Java&nbsp;")!=str::npos) type=".java";
	else if (file_content.find("Language : C&nbsp;")!=str::npos) type=".c";
	else if (file_content.find("Language : Pascal&nbsp;")!=str::npos) type=".pas";
	else type=".cpp";
	if (!boost::filesystem::exists(id+".java")
		&&!boost::filesystem::exists(id+".c")
		&&!boost::filesystem::exists(id+".pas")
		&&!boost::filesystem::exists(id+".cpp"))
	{
		str output;
		size_t p=file_content.find(begincode)+sz(begincode);
		size_t q=file_content.find(endcode);
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
	curl_easy_setopt(curl,CURLOPT_COOKIEFILE,"cookie.txt");
	curl_easy_setopt(curl,CURLOPT_COOKIEJAR,"cookie.txt");
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
	size_t p=0;
	lp
	{
		p=page_content.find("\"/viewcode.php?rid=",p);
		if (p==str::npos) break;
		p++;
		size_t q=page_content.find('"',p);
		file_url="http://acm.hdu.edu.cn"+page_content.substr(p,q-p);
		download_file();
	}
}

void download_page()
{
	cerr<<"Page "<<++page_count<<": "<<page_url<<endl;
	cerr<<"download_page()"<<endl;
	string buffer;
	CURL *curl=curl_easy_init();
	curl_easy_setopt(curl,CURLOPT_URL,page_url.c_str());
	curl_easy_setopt(curl,CURLOPT_COOKIEFILE,"cookie.txt");
	curl_easy_setopt(curl,CURLOPT_COOKIEJAR,"cookie.txt");
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
	size_t p=page_content.find("Next Page");
	if (p==str::npos) rtn false;
	whl(page_content[p]!='<') p--;
	p=page_content.find("href=",p);
	whl(page_content[p++]!='"');
	size_t q=page_content.find('>',p)-1;
	page_url="http://acm.hdu.edu.cn"+page_content.substr(p,q-p);
	rtn true;
}

int main()
{
	cout<<"Username:"<<flush;
	cin>>USER;
	cout<<"PASSWORD:"<<flush;
	cin>>PASS;
	curl_global_init(CURL_GLOBAL_ALL);
	login();
	page_url="http://acm.hdu.edu.cn/status.php?first=&pid=&user="+USER+"&lang=0&status=5";
	do download_page();
	whl(has_next_page());
	cout<<"Enter 'q' to quit."<<endl<<flush;;
	whl(cin.get()!='q');
}
