#include <iostream>
using namespace std;

int g[10][10], v[10], d[10], p[10];

void prims(int n)
{
    int u;
    for (int i = 0; i < n; i++)
    {
        v[i] = 0;
        p[i] = 0;
        d[i] = 99;
    }
    d[0] = 0;

    for (int k = 0; k < n - 1; k++)
    {
        int min = 99;
        for (int i = 0; i < n; i++)
        {
            if (d[i]<min && v[i]==0)
            {
                min=d[i];
                u=i;
            }
        }
        v[u]=1;
        for (int j = 0; j < n; j++)
        {
            if (v[j] == 0 && g[u][j] && d[j] > g[u][j])
            {
                d[j] = g[u][j];
                p[j]=u;
            }
        }
    }
    int cost=0;
    for(int i=1;i<n;i++)
    {
        cout<<p[i]<<" --> "<<i<<" "<<g[p[i]][i]<<endl;
        cost+=g[p[i]][i];
    }
   cout<< cost;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }

    prims(n);
}