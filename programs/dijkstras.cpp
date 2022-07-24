#include<iostream>
using namespace std;

int g[100][100];
 int v[10],d[10],u; 

void dijkstras(int n,int src)
{
   int  min=999;
  for(int i=0;i<n;i++)
  {
    v[i]=0;
    d[i]=g[src][i];
  }
  v[src]=1;
  d[src]=0;
  for(int j=1;j<n;j++)
  {
  for(int i=0;i<n;i++)
    {
        if(v[i]==0)
        {   
            if( d[i]<min)
            {
                min=d[i];
                u=i;
            }
        }
    }
    v[u]=1;
  for(int k=0;k<n;k++)
    {
      if(v[k]==0&&g[u][k]!=999)
      {
        if(d[k]>d[u]+g[u][k])
        {
            d[k]=d[u]+g[u][k];
        }
      }
    }
  }
}

int main()
{
  
  int n,src;
  cout<<"enter the number of nodes \n";
  cin>>n;
  for(int i=0;i<n;i++)
  {
   for(int j=0;j<n;j++)
    {
      cout<<"Enter the weight of node "<<i<<j<<">>";
      cin>>g[i][j];
    }
  }
  cout<<"your adjacency matrix\n";
  for(int i=0;i<n;i++)
  {
   for(int j=0;j<n;j++)
    {
      cout<<g[i][j]<<" ";
    }
    cout<<"\n";
  }

  cout<<"enter the source node >>";
  cin>>src;

  dijkstras(n,src);
  for(int i=0;i<n;i++)
  { 
    if(i!=src)
     {
       cout<<"shortest path distance from "<<src<<" to "<<i<<" >>"<<d[i];
     }
  }
}