#include<iostream>
using namespace std;

int partition(int a[],int l,int h)
{   int pivot=l;
    int i=l;
    int j=h;
  while(i<j)
  {
    do{
        i++;
    }while(a[i]<pivot);

    do{
        j--;
    }while(a[j]>pivot);

    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
  }
  int temp=a[l];
    a[l]=a[j];
    a[j]=temp;

    return j;
}


void quicksort(int a[],int l,int h)
{
  int j;
  if(l<h)
  {
    j= partition(a,l,h);
    quicksort(a,l,j);
    quicksort(a,j+1,h);
  }

}

int main()
{
    int n;
    cin>>n;
    int a[10];

    for(int i=0;i<n;i++)
    {   
       cin>>a[i];    
    }

    quicksort(a,0,n);
 
   for(int i=0;i<n;i++)
    {   
       cout<<a[i]<<" ";    
    }

}