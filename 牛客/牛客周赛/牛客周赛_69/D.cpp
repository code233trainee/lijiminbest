#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    vector<string>mp1(n+1);
    vector<vector<string>>mp2(q+1,vector<string>(n+1));
    for(int i=1;i<=n;i++)
    {
        cin>>mp1[i];
        mp1[i]='&'+mp1[i];
    }
    for(int i=1;i<=q;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>mp2[i][j];
            mp2[i][j]='%'+mp2[i][j];
        }
    }
    vector<int>res;
    for(int i=0;i<10;i++) 
    {
        res.push_back(1);
    }
    for(int i=0;i<=(1ll<<q);i++)
    {
        vector<vector<char>>temp(n+1,vector<char>(m+1,'0'));
        vector<bool>choose(q+1,false);
        for(int j=0;j<q;j++)
        {
            if((i>>j)&1)
            {
                choose[j+1]=true;
                for(int x=1;x<=n;x++)
                {
                    for(int y=1;y<=m;y++)
                    {
                        if(mp2[j+1][x][y]=='1')
                        {
                            temp[x][y]='1';
                        }
                    }
                }
            }
        }
        bool ok=true;
        for(int x=1;x<=n;x++)
        {
            for(int y=1;y<=m;y++)
            {
                if(mp1[x][y]==temp[x][y])
                {
                    ok=false;
                    break;
                }
            }
            if(!ok) break;
        }
        if(ok){
             
            vector<int>ans;
            for(int j=1;j<=q;j++)
            {
                if(choose[j]){
                    ans.push_back(j);
                }
            }
            if(res.size()>ans.size())
            {
                swap(res,ans);
            }
        }
    }
    if(res.size()==10)
    {
        cout<<"-1";
    }else
    {
        cout<<res.size()<<"\n";
        for(auto t:res)
        {
            cout<<t<<" ";
        }
    }
}