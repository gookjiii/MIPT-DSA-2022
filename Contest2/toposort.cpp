#include<bits/stdc++.h>
using namespace std;
const int N = 2002;

int n, m;
vector<int> adj[N + 1];

void DFS(int u, bool visited[], stack<int>& Stack)
{
    visited[u] = true;
    for (auto v : adj[u])
        if(!visited[v]) {
            DFS(v, visited, Stack);;
        }
    Stack.push(u);
}

int main() 
{
    cin >> n >> m;
    stack<int> Stack;
    bool visited[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int j = 0; j < n; j++)
            visited[j] = false;
    for (int i = 0; i < n; i++)
        if (!visited[i]) {
            DFS(i, visited, Stack);
    }
    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    return 0;
}
