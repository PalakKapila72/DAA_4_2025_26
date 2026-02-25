#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unionSet(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(px == py) return;

        if(rank[px] < rank[py])
            parent[px] = py;
        else if(rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }

    int spanningTree(int V, vector<vector<int>>& edges) {
        parent.resize(V);
        rank.resize(V, 0);

        for(int i = 0; i < V; i++)
            parent[i] = i;

        sort(edges.begin(), edges.end(),
            [](vector<int>& a, vector<int>& b){
                return a[2] < b[2];
            });

        int mstWeight = 0;
        int edgesUsed = 0;

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if(find(u) != find(v)) {
                unionSet(u, v);
                mstWeight += w;
                edgesUsed++;

                if(edgesUsed == V-1)
                    break;
            }
        }

        return mstWeight;
    }
};
