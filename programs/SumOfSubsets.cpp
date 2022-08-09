#include <iostream>
#include <vector>
using namespace std;

void combination(int ind, int max, int n, int a[], vector<int> &dp)
{
    if (max == 0)
    {
        for (int i = 0; i < dp.size(); i++)
        {
            cout << dp[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    else
    {
        for (int i = ind; i < n; i++)
        {
            if (a[i] > max)
            {
                break;
            }
            dp.emplace_back(a[i]);
            combination(i+1,max-a[i],n,a,dp);
            dp.pop_back();
        }
    }
}

int main()
{
    int n, max;
    cout << "enter the number of elements in subset \n";
    cin >> n;
    cin >> max;
    int *set = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        cin >> set[i];
    }

    vector<int> dp;

    combination(0, max, n, set, dp);
}