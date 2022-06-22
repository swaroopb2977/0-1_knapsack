#include<bits/stdc++.h>
using namespace std;

// Brute force
/*
bool ispresent(int a[],int val,int n)
{
    if(n<0 && val!=0)
    {
        return false;
    }

    if(val==0)
    {
        return true;
    }

    else if(a[n]<=val)
    {
        if(ispresent(a,val-a[n],n-1))
        {
            return ispresent(a,val-a[n],n-1);
        }
        else
        {
            return ispresent(a,val,n-1);
        }
    }

    else if(a[n]>val)
    {
          return ispresent(a,val,n-1);
    }
}
*/

//Memorization
/*

int  dp[15][15];

int ispresent(int a[],int sum,int n)
{
    if(n<=0 && sum!=0)
    {
        return 0;
    }

    if(sum==0)
    {
        return 1;
    }

    if(dp[n-1][sum] !=-1)
    {
        return dp[n-1][sum];
    }

    if(a[n-1] > sum)
    {
        return dp[n-1][sum] = ispresent(a,sum,n-1);
    }

    else
    {
        return dp[n-1][sum]=ispresent(a,sum,n-1)||ispresent(a,sum-a[n-1],n-1);
    }
}
*/

// Real DP

bool ispresent(int a[],int n,int sum)
{
    bool dp[6][10];

    for(int j=0;j<=sum;j++)
    {
        dp[0][j]=false;
    }

    for(int i=0;i<=n;i++)
    {
        dp[i][0]=true;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(a[i-1] <= j)
            {
                dp[i][j]=dp[i-1][j]||dp[i-1][j-a[i-1]];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
}
int main()
{
    int a[]={2,3,7,8,10};
   // memset(dp,-1,sizeof(dp));
   
    if(ispresent(a,5,9))
    {
        cout<<"Present:";
    }

    else
    {
        cout<<"Absent:";
    }



}
