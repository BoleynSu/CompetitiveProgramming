//============================================================================
// Name        : test.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	string s;
	while (cin>>s)
	{
		map<string,int> cnt;
		for (int i=0;i<14;i++) cnt[s.substr(i*2,2)]++;
		bool pairs=true;
		for (map<string,int>::iterator it=cnt.begin();it!=cnt.end();it++)
		{
			if (it->second!=2) pairs=false;
		}
		if (pairs)
		{
			cout<<"Seven Pairs"<<endl;
			continue;
		}for (map<string,int>::iterator it=cnt.begin();it!=cnt.end();it++)
		{
			if (it->second==2) pairs=true;
		}
		if (pairs&&cnt["1p"]&&cnt["9p"]&&cnt["1s"]&&cnt["9s"]&&cnt["1m"]&&cnt["9m"]&&cnt["1z"]&&cnt["2z"]&&cnt["3z"]&&cnt["4z"]&&cnt["5z"]&&cnt["6z"]&&cnt["7z"])
		{
			cout<<"Thirteen Orphans"<<endl;
			continue;
		}
		cout<<"Neither!"<<endl;
	}
}
