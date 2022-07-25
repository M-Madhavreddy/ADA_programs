#include<iostream>
using namespace std;

int main()
{   int n,k=0,min,temp;
    cout<<"enter your array size >> ";
    cin>>n;
    int *arr=(int*)malloc(n*sizeof(int));
   
    cout<<"enter the array elements>> \n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

  for(int j=0;j<n-1;j++)
  { 
     min=arr[j];
    for(int i=j+1;i<n;i++)
    {
      if(arr[i]<min)
      {
        min=arr[i];
         k=i;
      }
    }

    for(int u=0;u<((k-j+1)/2);u++)
    {   
         temp=arr[j+u];
        arr[j+u]=arr[k-u];
        arr[k-u]=temp;
    }
  }

     cout<<"Array after reverse sorting :\n";

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}