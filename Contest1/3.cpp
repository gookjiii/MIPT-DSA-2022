#include <iostream>
#include <vector>
#include <queue>
#define II std::pair<int, int>
#define III std::pair<int, II>

const int N = 6000;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int matrix[N + 1][N + 1];
int n;

bool check(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

void BFS(int x, int y, int p, int q)
{
    bool visited[n + 1][n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            visited[i][j] = false;
    }
    visited[x][y] = true;
    II path[n + 5][n + 5];
    path[x][y] = {x,y};
    std::queue<II> qu;
    qu.push({x,y});
    while(!qu.empty()) {
        int u = qu.front().first, v = qu.front().second;
        qu.pop();
        if (u == p && v == q)
            break;
        for (int i = 0; i < 4; i++) {
            if (check(u + dx[i], v + dy[i]) && matrix[u + dx[i]][v + dy[i]] == 1 && !visited[u + dx[i]][v + dy[i]]) {
                visited[u + dx[i]][v + dy[i]] = true;
                path[u + dx[i]][v + dy[i]] = II(u, v);
                qu.push({u + dx[i], v + dy[i]});
            }
        }
    }
    std::deque<II> res;
    if (visited[p][q]) {
        int u = p, v = q;
        while (path[u][v] != II(u,v) ) {
            res.push_front(II(u,v));
            II next_step = path[u][v];
            u = next_step.first;
            v = next_step.second;
        }
        res.push_front({x,y});
        while (!res.empty()){
            std::cout << res.front().first << " " << res.front().second << std::endl;
            res.pop_front();
        }
    }
    else
        std::cout << -1;
}

int main()
{
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            std::cin >> matrix[i][j];
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    BFS(a,b, c, d);
    return 0;
}
