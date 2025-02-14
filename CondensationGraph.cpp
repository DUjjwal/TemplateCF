#include<bits/stdc++.h>
#define int long long
#define pp pair<int,int>
#define all(a) a.begin(),a.end()
#define rall(a) a.end(),a.begin()
using namespace std;
vector <vector <int>> graph,graphT;
vector <int> order;
vector <bool> vis;
void dfs(int node) {
    vis[node]=true;
    for(auto neigh:graph[node]) {
        if(!vis[neigh])
            dfs(neigh);
    }
    order.push_back(node);
}
void dfs2(int node,vector <int> &cc) {
    vis[node]=true;
    cc.push_back(node);
    for(auto neigh:graphT[node]) {
        if(!vis[neigh]) {
            dfs2(neigh,cc);
        }
    }
}
void solve()
{
    int n,m;cin>>n>>m;
    graph.resize(n+1);
    graphT.resize(n+1);
    while(m--) {
        int a,b;cin>>a>>b;
        graph[a].push_back(b);
        graphT[b].push_back(a);
    }
    vis.resize(n+1);
    for(int i=1;i<=n;i++) {
        if(!vis[i])
            dfs(i);
    }
    vis.clear();
    vis.resize(n+1,false);
    vector <vector <int>> condensed(n+1);
    vector <int> idd(n+1);
    vector <int> newNode;
    for(int i=n-1;i>=0;i--) {
        int node=order[i];
        if(!vis[node]) {
            vector <int> cc;
            dfs2(node,cc);
            int root=*min_element(all(cc));
            for(auto i:cc)
                idd[i]=root;
            newNode.push_back(root);
        }
    }
    for(int i=1;i<=n;i++) {
        for(auto neigh:graph[i]) {
            if(idd[i]!=idd[neigh]) {
                condensed[idd[i]].push_back(idd[neigh]);
            }
        }
    }
    //now i have the condensed graph and newNodes contains the root of each SCC
    //condensed newNodes 
    //idd contains to root of SCC in which node lies
    

}
signed main()
{
    cin.tie()->sync_with_stdio(false);
    solve();
}
