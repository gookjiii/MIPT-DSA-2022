#include<bits/stdc++.h>
using namespace std;
const int N = 20002;

int n, m;
bool visited[N];
vector<int> adj[N + 1];

void DFS(int u)
{
    for (auto v : adj[u])
        if(!visited[v]) {
            visited[v] = true;
            DFS(v);
            visited[v] = false;
        }
        else {
            cout << "YES";
            exit(0);
        }
}

int main() 
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int j = 1; j <= n; j++)
            visited[j] = false;
    for (int i = 1; i <= n; i++){
        visited[i] = true;
        DFS(i);
        visited[i] = false;
    }
    cout << "NO";
    return 0;
}
