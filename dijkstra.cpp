#include<bits/stdc++.h>
#define pp pair<int,int>
using namespace std;
vector <list<pp>> graph;
int dijkstra(int src,int n)
{
    priority_queue<pp,vector <pp>,greater<pp>> pq;
    map <int,int> dist,via;
    for(int i=0;i<n;i++)dist[i]=INT_MAX;
    pq.push({0,src});//distance - node
    dist[src]=0;
    while(pq.size()) {
        pp curr=pq.top();
        if(dist[curr.second]<curr.first) {
            pq.pop();
            continue;
        }
        pq.pop();
        for(auto neigh:graph[curr.second]) {
            if(neigh.second+dist[curr.second] < dist[neigh.first]) {
                pq.push({neigh.second+dist[curr.second],neigh.first});
                dist[neigh.first]=neigh.second+dist[curr.second];
                via[neigh.first]=curr.second;
            }
        }
    }
    for(int i=0;i<n;i++)
    cout<<dist[i]<<" ";
}
int main()
{
    int n,m;cin>>n>>m;
    graph.resize(n,list <pp> ());
    while(m--) {
        int a,b,c;cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    dijkstra(0,n);
}