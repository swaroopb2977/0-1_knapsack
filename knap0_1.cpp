/*
   given the values and the weight of items 
   find out the maximum value that can be 
   obtained using the bag whose maximum 
   capacity is w  
*/


#include<bits/stdc++.h>
using namespace std;


// Recursive solution

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



int main()
{
    int wt[]={1,3,4,5};
    int val[]={1,4,5,7};
    cout<<knapsack(wt,val,8,4);

}