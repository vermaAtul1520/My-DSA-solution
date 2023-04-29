//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int i,vector<bool> &vis,vector<int> adj[]){
        queue<pair<int,int>>q;
        vis[i]=1;
        q.push({i,-1});
        while(q.size()){
            int t=q.size();
            while(t--){
                pair<int,int> p=q.front();
                q.pop();
                for(auto x:adj[p.first]){
                    if(vis[x]==0){
                        vis[x]=1;
                        q.push({x,p.first});
                    }
                    else if(p.second!=x){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>vis(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                if(bfs(i,vis,adj)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends