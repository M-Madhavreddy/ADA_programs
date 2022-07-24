#include<iostream>
using namespace std;


int g[10][10],q[10],v[10],n;

void BFS(int src)
{
    int r=-1,f=0,u;
  v[src]=1;
  q[++r]=src;
  
  while(r>=f)
  {
    u=q[f++];
  for(int i=0;i<n;i++)
   {
    if(g[u][i]==1&&v[i]==0)
    {
      q[++r]=i;
    }
   }
  }

}

int main()
{ 
    cout<<"enter the number of nodes \n";
  cin>>n;
  for(int i=0;i<n;i++)
  {
   for(int j=0;j<n;j++)
    {
      cout<<"Enter the 1 if edge from "<<i<<j<<" is present >>";
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
 
 BFS(0);

  for(int i=0;i<n;i++)
{
    cout<<q[i]<<" ";
}
}