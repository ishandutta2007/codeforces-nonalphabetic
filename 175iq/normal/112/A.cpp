#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s1;
	string s2;
	
	getline(cin,s1);
	getline(cin,s2);
	
	transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
	transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
	
	for (int i = 0 ; i <s1.size() ; i++)
	{
		if(s1[i]<s2[i])
		{
			cout<<"-1"<<endl;
			return 0;
		}
		else if(s1[i]>s2[i])
		{
			cout<<"1"<<endl;
			return 0;
		}
		else
		{}		
	}
	cout<<"0"<<endl;
	return 0;
}