#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> inDegree(V, 0);
    queue<int> q;
    vector<int> result;

    // Calculate in-degree of each vertex
    for(int i = 0; i < V; i++) {
        for(auto it : adj[i]) {
            inDegree[it]++;
        }
    }

    // Enqueue vertices with in-degree 0
    for(int i = 0; i < V; i++) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        // Reduce the in-degree of adjacent vertices
        for(auto it : adj[node]) {
            inDegree[it]--;
            if(inDegree[it] == 0) {
                q.push(it);
            }
        }
    }

    return result;
}

int main() {
    int V = 6; // Number of vertices
    vector<int> adj[V];

    // Adding edges to the graph
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> result = topoSort(V, adj);
    cout << "Topological Sort: ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
