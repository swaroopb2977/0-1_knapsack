// check whether subsets of equal sum is there 
// or not in given array 

#include<bits/stdc++.h>
using namespace std;


bool ispresent(int a[],int sum,int n)
{
    bool dp[n+1][sum+1];

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
            if(a[i-1] > j)
            {
                dp[i][j]=dp[i-1][j];
            }

            else
            {
                dp[i][j]=dp[i-1][j-a[i-1]]||dp[i-1][j];
            }
        }
    }


    return dp[n][sum];

}


int main()
{
    int a[]={1,5,11,5};
    int count=0;
    for(int i=0;i<4;i++)
    {
        count=count+a[i];
    }

    if(count%2!=0)
    {
        cout<<"Not Possible:";
    }

    else
    {
        if(ispresent(a,count/2,4))
        {
            cout<<"Possible:";
        }

        else
        {
            cout<<"Not Possible:";
        }
    }
}