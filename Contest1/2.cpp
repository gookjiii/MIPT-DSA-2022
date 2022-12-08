#include <iostream>
#include <vector>
#include <queue>
#define II std::pair<int, int>
#define III std::pair<int, II>

const int N = 2002;
const int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
const int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
const int INF = 1e9;

bool check(int x, int y) {
    return x >= 1 && x <= 8 && y >= 1 && y <= 8;
}

void BFS(int x, int y, int p, int q)
{
    int dist[9][9];
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++)
            dist[i][j] = INF;
    }
    dist[x][y] = 0;
    std::queue<III> qu;
    qu.push({0,{x,y}});
    while(!qu.empty())
    {
        int u = qu.front().second.first, du = qu.front().first, v = qu.front().second.second;
        qu.pop();
        if (u == p && v == q)
            break;
        for (int i = 0; i < 8; i++) {
            if (check(u + dx[i], v + dy[i]) && dist[u + dx[i]][v + dy[i]] > du + 1)
            {
                dist[u + dx[i]][v + dy[i]] = du + 1;
                qu.push({dist[u + dx[i]][v + dy[i]],{u + dx[i], v + dy[i]}});
            }
        }
    }
    std::cout << dist[p][q];
}

int main()
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    BFS(a,b, c, d);
    return 0;
}
