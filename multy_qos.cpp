#include <iostream>
using namespace std;
void dijkstra();
int e[10][10];
int vis[10];
int dis[10];
int n, m;
int min1 = 99999999;
int u = 0;
int main()
{
    cin >> n >> m;
    // 初始化邻接表
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                e[i][j] = 0;
            }
            else
            {
                e[i][j] = 99999999;
            }
        }
    }
    // 填充数据
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        e[a][b] = c;
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = e[1][i];
    }
    vis[1] = 1;

    dijkstra();

    for (int i = 1; i <= n; i++)
    {
        cout << dis[i];
    }

    system("pause");
    return 0;
}
void dijkstra()
{
    for (int i = 1; i <= n - 1; i++)
    {
        min1 = 99999999;
        // 寻找权值最小的点u
        for (int j = 1; j <= n; j++)
        {
            if (vis[j] == 0 && dis[j] < min1)
            {
                min1 = dis[j];
                u = j;
            }
        }

        vis[u] = 1;

        for (int v = 1; v <= n; v++)
        {
            // 对于每个u可达的v来说
            if (e[u][v] < 99999999)
            {
                // 如果当前的dis[v]不满足三角形不等式，那么进行松弛操作
                if (dis[v] > dis[u] + e[u][v])
                {
                    dis[v] = dis[u] + e[u][v];
                }
            }
        }
    }
}
