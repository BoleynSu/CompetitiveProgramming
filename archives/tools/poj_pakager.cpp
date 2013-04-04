#include <Core>

#include <boost/program_options/detail/utf8_codecvt_facet.hpp>
#include <boost/filesystem.hpp>
using namespace boost::filesystem;

str poj_org("poj.org");

path new_path(const path& old_path)
{
	str p=old_path.string();
	str prefix,infix,suffix;
	prefix=p.substr(0,p.find(poj_org)+sz(poj_org));
	infix=p.substr(p.find(poj_org)+sz(poj_org)+1,4);
	if (p.substr(sz(p)-4,4)=="java") suffix="java";
	else suffix="cpp";
	rtn path(prefix+"/"+infix+"."+suffix);
}

int main()
{
	directory_iterator it(current_path()),end;
	whl(it!=end)
	{
		if (is_directory(it->path()))
		{
			directory_iterator jt(it->path());
			whl(jt!=end)
			{
				string p=jt->path().string();
				if (p.find("AC")!=str::npos) prt(jt->path());
				rename(jt->path(),new_path(jt->path()));
				jt++;
			}
		}
		it++;
	}
}
