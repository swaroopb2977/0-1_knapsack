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


int main()
{
    int wt[]={1,3,4,5};
    int val[]={1,4,5,7};
    int dp[8][4];
    memset(dp,-1,sizeof(dp));
    cout<<knapsack(wt,val,8,4,dp);

}