#include <iostream>
using namespace std;

int g[10][10],p[10];

int find(int i)
{
    while(p[i])
    {
      i=p[i];
    }
    return i;
}

int uni(int i ,int j)
{
    if(i!=j)
    {
        p[j]=i;
        return 1;
    }
    return 0;
}

void krushkal(int n)
{
    int a,b,u,V,ne=1,cost;
   // v[0] = 1;
  while(ne<n)
  { int min=999;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            
                if(g[i][j]<min)
                {
                    min=g[i][j];
                a=u=i;
                b=V=j; 
                }
            
        }
    }

    u=find(u);
    V=find(V);
    if(uni(u,V))
    {
        cout<<ne++<<"st edge --> "<<a<<" to "<<b<<" "<< g[a][b]<<endl;
        cost+=g[a][b];
    }
    g[a][b]=g[b][a]=999;

}
cout<<cost;
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
            p[i] = 0;
        }
    }

    krushkal(n);
}