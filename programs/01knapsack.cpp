#include <iostream>
using namespace std;

void knapsack(int v[], int w[], int n, int W)
{
    int k[100][100];

    cout << "enter your values and weights\n";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i] >> w[i];
    }

    int i, j;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= W; j++)
        {

            if (i == 0 || j == 0)
            {
                k[i][j] = 0;
            }
            else if (j < w[i])
            {
                k[i][j] = k[i - 1][j];
            }
            else
            {
                if (k[i - 1][j] > k[i - 1][j - w[i]] + v[i])
                {
                    k[i][j] = k[i - 1][j];
                }
                else
                {
                    k[i][j] = k[i - 1][j - w[i]] + v[i];
                }
            }
        }
    }
    
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <=W; j++)
        {
            cout<<k[i][j]<<" ";
        }
        cout<<"\n";
    }
    
}

int main()
{
    int n;
    cout << "enter the number of objects";
    cin >> n;

    int W;
    cout << "enter the maximum weight \n";
    cin >> W;

    int *v = (int *)malloc(n * sizeof(int));
    int *w = (int *)malloc(n * sizeof(int));

    knapsack(v, w, n, W);
}