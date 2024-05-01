#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;
vector<vector<int>> graph;
vector<int> dist;
void bfs(int source) {
    queue<int> q;
    q.push(source);
    dist[source] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (dist[v] ==-1) {
                dist[v] = dist[u] + 1;
                q.push(v); } } }}
int main() {
    int n, m;
    cin >> n >> m;
    graph.resize(n);
    dist.resize(n,-1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); }
    bfs(0);
    for (int i = 0; i < n; i++) {
        if (dist[i] ==-1) {
            cout <<-1 << " ";
        } else {
            cout << dist[i] << " "; } }
    return 0;
}