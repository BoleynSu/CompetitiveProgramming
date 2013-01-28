#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main()
{
	vector<string> vs;
	string s;
	while (getline(cin,s)) vs.push_back(s);
	vector<string> output;
	bool newline=true;
	for (int i=0;i<vs.size();i++)
	{
		int j=vs[i].find_first_of('#');
		bool amplifying=(j!=string::npos);
		for (int k=0;k<j;k++)
			if (vs[i][k]!=' ')
			{
				amplifying=false;
			}
		if (amplifying)
		{
			output.push_back(vs[i]);
			newline=true;
		}
		else
		{
			if (newline)
			{
				newline=false;
				output.push_back(string());
			}
			for (int k=0;k<vs[i].size();k++)
				if (vs[i][k]!=' '&&vs[i][k]!='\n') output.back().push_back(vs[i][k]);
		}
	}
	for (int i=0;i<output.size();i++)
		cout<<output[i]<<endl;
}

