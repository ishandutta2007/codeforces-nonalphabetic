#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n,t;
    cin>>n>>t;
    if(t==10&&n==1)
    {
        cout<<-1<<endl;
        return 0;
    }
    if(t==10)
    {
        cout<<t;
        for(int i=2;i<n;i++)cout<<0;
        cout<<endl;
    }
    else
    {
        cout<<t;
        for(int i=1;i<n;i++)cout<<0;
        cout<<endl;
    }
    return 0;
}