#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
vector<vector<int>> graph;
vector<bool> visited;
int numComponents;
void dfs(int u) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    graph.resize(n);
    visited.resize(n, false);
    numComponents = 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            numComponents++;
        }
    }
    cout << numComponents << endl;
    return 0;
}