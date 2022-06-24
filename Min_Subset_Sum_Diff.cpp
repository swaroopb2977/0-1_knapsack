// FIND MINIMUM SUBSET DIFFERENCE 

#include<bits/stdc++.h>
using namespace std;


int  countSubset(int a[],int n,int sum)
{
    bool dp[n+1][sum+1];

    for(int j=1;j<=sum;j++)
    {
        dp[0][j]=false;
    }

    for(int i=0;i<=n;i++)
    {
        dp[i][sum]=true;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(a[i-1] > j)
            {
                dp[i][j]=dp[i-1][j];
            }

            else
            {
                dp[i][j]=dp[i-1][j]||dp[i-1][j-a[i-1]];
            }
        }
    }

   // int min=
   vector<int>v;
    for(int i=0;i<=(sum/2);i++)
    {
        if(dp[n][i])
        {
            v.push_back(i);
        }

    }

    return v[v.size()-1];
}

int main()
{
    int a[]={1,2,3,5};
    int n=4;
    int sum=11;
    cout<<"MIN diff between subsets :   "<<sum-(2*countSubset(a,n,sum));
}