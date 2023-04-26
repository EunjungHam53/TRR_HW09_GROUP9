#include <iostream>
#include <cstring>
using namespace std;

bool visited[100];
bool a[100][100];

void input(int n)
{

    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
}

// Duyet het cac dinh neu do thi lien thong
void DFS(int u, int n)
{
    visited[u] = true;
    // Duyet dinh ke u
    for (int v = 1; v <= n; v++)
    {
        if (a[u][v] == 1)
        {
            if (!visited[v]) DFS(v, n);
        }
    }
}

// Ham check so canh bang n-1 khong
bool Check_num_edge(int n)
{
    int num_edge = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            if (a[i][j]) num_edge++;
        }
    }
    if (num_edge == n-1) return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    input(n);
    DFS(1, n);

    bool lien_thong = true;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            lien_thong = false;
            break;
        }
    }
    bool check_edge = Check_num_edge(n);

    // Do thi la cay neu va chi neu do thi lien thong va co n-1 canh
    if (lien_thong && check_edge) cout << "Do thi da cho la cay";
    else cout << "Ko phai la cay";
    return 0;
}
