#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    
    int spanningTree(int V, vector<vector<int>>& edges)
    {
        // Step 1: Convert edge list to adjacency list
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        // Step 2: Prim's Algorithm
        priority_queue<pair<int,int>, 
                       vector<pair<int,int>>, 
                       greater<pair<int,int>>> pq;
        
        vector<int> visited(V, 0);
        int mstWeight = 0;
        
        pq.push({0, 0}); // {weight, node}
        
        while(!pq.empty())
        {
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(visited[node]) continue;
            
            visited[node] = 1;
            mstWeight += weight;
            
            for(auto &it : adj[node])
            {
                int adjNode = it.first;
                int edgeWeight = it.second;
                
                if(!visited[adjNode])
                {
                    pq.push({edgeWeight, adjNode});
                }
            }
        }
        
        return mstWeight;
    }
};
