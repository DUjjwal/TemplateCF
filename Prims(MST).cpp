#include<bits/stdc++.h>
#define pp pair<int,int>
using namespace std;
vector <list<pp>> graph;
int prims(int src,int n)
{
    priority_queue <pp,vector <pp>,greater<pp>> pq;
    unordered_set <int> vis;
    vector <int> par(n+1,0);
    unordered_map <int,int> mp;
    for(int i=1;i<=n;i++)mp[i]=INT_MAX;
    pq.push({0,src});
    mp[src]=0;
    int total_cnt=0;
    int ans=0;
    while(total_cnt < n && !pq.empty()) {
        pp curr=pq.top();
        if(vis.count(curr.second)) { //already visited
            pq.pop();
            continue;
        }
        vis.insert(curr.second);
        total_cnt++;
        ans+=curr.first;
        pq.pop();
        for(auto neigh:graph[curr.second]) {
            if(!vis.count(neigh.first) && mp[neigh.first] > neigh.second) {
                pq.push({neigh.second,neigh.first});
                par[neigh.first]=curr.second;
                mp[neigh.first]=neigh.second;
            }
        }
        
    }
    return ans;


}
int main()
{
    int n,m;cin>>n>>m;
    graph.resize(n+1,list<pp> ());
    while(m--) {
        int a,b,c;cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    int src;cin>>src;
    cout<<prims(src,n)<<endl;
}
