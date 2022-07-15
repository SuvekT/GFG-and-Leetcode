// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
   int knapack(int W,int wt[],int val[],int n,vector<vector<int>> &t){
             if(W==0 || n==0)
       return 0;
       if(t[n][W]!=-1)
       return t[n][W];
       if(wt[n-1]<=W){
           int take= val[n-1]+knapack(W-wt[n-1],wt,val,n-1,t);
           int nottake= knapack(W,wt,val,n-1,t);
           return t[n][W]=max(take,nottake);
       }
       else{
           return t[n][W]= knapack(W,wt,val,n-1,t);
       }
   }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
        vector<vector<int>> t(n+1,vector<int>(W+1,-1));
        return knapack(W,wt,val,n,t);
 
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends