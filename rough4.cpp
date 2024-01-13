//Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int fact(int n)
{
    int i,f=1;
    for(i=1;i<=n;i++)
    {
        f*=i;
    }
    return f;
}
int main()
{
    vector<int> v={1,2,3};
    sort(v.begin(),v.end());
    int n=v.size(),m=fact(n),repeat,i,j,idx1,idx2,temp,k;
    for(i=0;i<n;i++)
    {
        repeat=1;
        while(v[i]==v[i+1])
        {
            repeat++;
            i++;
        }
        m=m/fact(repeat);
    }
    vector<vector<int>> a(m,vector<int>(n));
    //first permutation
    for(j=0;j<n;j++)
    a[0][j]=v[j];
for(k=1;k<m;k++)
{
    //pivot
    for(i=n-2;i>=0;i--)
    {
        if(v[i]<v[i+1])
        {
            idx1=i;
            break;
        }
    }
    //sort after pivot
    sort(v.begin()+idx1+1,v.end());
    //idx2;
    for(i=idx1+1;i<n;i++)
    {
        if(v[i]>v[idx1])
        {
            idx2=i;
            break;
        }
    }
    //change
    temp=v[idx1];
    v[idx1]=v[idx2];
    v[idx2]=temp;
    //enter in a
    for(i=0;i<n;i++)
    a[k][i]=v[i];
}
//print
for(i=0;i<m;i++)
{
    for(j=0;j<n;j++)
    cout<<a[i][j]<<" ";
cout<<endl;
}

    
}