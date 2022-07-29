#include<iostream>
using namespace std;


void merge(int a[],int l,int m,int h)
{
  int i,j,k;
  int n1=m-l+1;
  int n2=h-m;

    int *la=(int*)malloc(n1*sizeof(int));
    int *ra=(int*)malloc(n2*sizeof(int));
    for(int i=0;i<n1;i++)
    {
        la[i]=a[l+i];
    }

    for(int j=0;j<n2;j++)
    {
        ra[j]=a[m+1+j];
    }
    
  i=0;j=0;k=l;
    while(i<n1 && j<n2)
    {
        if(la[i]<ra[j])
          {
            a[k++]=la[i++];
          }
          else
          {
            a[k++]=ra[j++];
          }
    }

    while(i<n1){
            a[k++]=la[i++];
    }

    while(j<n2){
            a[k++]=ra[j++];
    }


}

void mergesort(int a[],int l,int h)
{   
    if(h > l){
        
        int mid=l+(h-l)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,h);
        merge(a,l,mid,h);

    }
    else{
        return ;
    }

}

int main()
{
    int n;
    
    cout<<"enter the number of elements in array \n";
    cin>>n;

    int *a=(int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    
    mergesort(a,0,n-1);

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    
}