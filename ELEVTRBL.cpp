#include<bits/stdc++.h>
#define ll long long
using namespace std;

main()
{
    int f,s,e,u,d; cin>>f>>s>>e>>u>>d;
    vector<int> g[f+1];
    for(int i=1;i<=f;++i)
    {
        if(i+u <= f)
        {
            g[i].emplace_back(i+u);
        }
        if(i-d>0) g[i].emplace_back(i-d);
    }
    vector<ll> height(f+1,-1);
    vector<bool> visit(f+1,false);
    queue<int> q;
    q.push(s);
    height[s]=0;
    visit[s]=1;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        for(auto i : g[temp])
        {
            if(!visit[i])
            {
                height[i]=height[temp]+1;
                q.push(i);
                visit[i]=1;
            }
        }
    }
    if( height[e]>=0 ) cout<<height[e];
    else cout<<"use the stairs";
}
