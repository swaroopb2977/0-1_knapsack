/*
   given the values and the weight of items 
   find out the maximum value that can be 
   obtained using the bag whose maximum 
   capacity is w  
*/


#include<bits/stdc++.h>
using namespace std;


// Recursive solution
/*
int knapsack(int wt[], int val[],int w,int n)
{
    if(n==0||w==0)
    {
        return 0;
    }

    if(wt[n-1]<=w)
    {
        return max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
    }
    else if(wt[n-1]>w)
    {
        return knapsack(wt,val,w,n-1);
    }
}
*/


// Memorizartion
/*
int knapsack(int wt[], int val[],int w,int n,int dp[8][4])
{
    if(w==0||n==0)
    {
        return 0;
    }

    if(dp[n][w]!=-1)
    {
        return dp[n][w];
    }

    else if (wt[n-1]<=w)
    {
         dp[n][w]= max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1,dp),knapsack(wt,val,w,n-1,dp));
          return dp[n][w];
    }

    else if(wt[n-1]>w)
    {
        dp[n][w]= knapsack(wt,val,w,n-1,dp);
        return dp[n][w];
    }
}
*/



int main()
{
    int wt[]={1,3,4,5};
    int val[]={1,4,5,7};
    int dp[5][9];
    memset(dp,-1,sizeof(dp));
    // Dynamic soln:-

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(j==0||i==0)
            {
                dp[i][j]=0;
            }
        }
    }

    for(int i=1;i<5;i++)
    {
        for(int j=1;j<9;j++)
        {
            if(wt[i-1]<=j)
            {
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    cout<<dp[4][8];

   // cout<<knapsack(wt,val,8,4,dp);

}