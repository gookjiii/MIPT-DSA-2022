#include <iostream>
#include <vector>
#include <queue>
#define II std::pair<int, int>

const int N = 2e3 + 2;
const int INF = 1e9;

void Dijsktra(int n, int m, int s, int f, std::vector<int> adj[N]) {
    int dist[n + 1];
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[s] = 0;
    std::priority_queue<II, std::vector<II>, std::greater<II>> pq;
    pq.push({0,s});
    while (!pq.empty())
    {
        int u = pq.top().second, du = pq.top().first;
        pq.pop();
        for (auto v : adj[u])
        {
            if (dist[v] > du + 1)
            {
                dist[v] = du + 1;
                pq.push({dist[v],v});
            }
        }
    }
    std::cout << (dist[f] != INF ? dist[f] : -1) << std::endl;
}

int main() {
    int n, m;
    std::vector<int> adj[N];
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
    }
    int s, v;
    std::cin >> s >> v;
    Dijsktra(n, m, s, v, adj);
    return 0;
}
