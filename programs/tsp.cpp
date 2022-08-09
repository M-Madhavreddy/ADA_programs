#include <iostream>
using namespace std;

int g[10][10], n, v[10], d[10], cost_op = 0, cost_app = 0;

int opleastcity(int city)
{
    int min = 999, u = 999, kmin = 999;
    for (int i = 1; i <= n; i++)
    {
        if (g[city][i] != 0 && v[i] == 0)
            if (g[city][i] < min)
            {
                min = g[city][i] + g[i][1];
                kmin = g[city][i];
                u = i;
            }
    }
    if (min != 999)
        cost_op += kmin;
    return u;
}

void op_cost(int city)
{

    int ncity;
    v[city] = 1;
    cout << city << "-->";
    ncity = opleastcity(city);
    if (ncity == 999)
    {
        ncity = 1;
        cout << ncity << "\n";
        cost_op += g[city][ncity];
        return;
    }
    op_cost(ncity);
}

int appleastcity(int city)
{
    int min = 999, u = 999, kmin = 999;
    for (int i = 1; i <= n; i++)
    {
        if (g[city][i] != 0 && v[i] == 0)
            if (g[city][i] < kmin)
            {
                min = g[city][i] + g[i][1];
                kmin = g[city][i];
                u = i;
            }
    }
    if (min != 999)
        cost_app += kmin;
    return u;
}

void app_cost(int city)
{
    int ncity;
    v[city] = 1;
    cout << city << "-->";
    ncity = appleastcity(city);
    if (ncity == 999)
    {
        ncity = 1;
        cout << ncity << "\n";
        cost_app += g[city][ncity];
        return;
    }
    app_cost(ncity);
}

int main()
{
    cout << "enter the number of vertices\n";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> g[i][j];
        }
    }

    cout << "optimal soln >> \n";
    for (int i = 1; i <= n; i++)
    {
        v[i] = 0;
    }
    op_cost(1);

    cout << cost_op<<" \n";

    for (int i = 1; i <= n; i++)
    {
        v[i] = 0;
    }
    app_cost(1);

    cout << cost_app;
}