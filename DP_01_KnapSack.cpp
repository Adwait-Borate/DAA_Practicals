#include <bits/stdc++.h>

using namespace std;

int dp[102][1002];
class Solution {
public:
   int O1Knapsack(vector<int>value,vector<int>weight,int W,int n) {
      if(n==0 || W==0){
         return 0;
      }
      if(dp[n][W]!=-1){
         return dp[n][W];
      }

      if(weight[n-1]<=W){
         return dp[n][W] =  max(value[n-1]+O1Knapsack(value,weight,W-weight[n-1],n-1),O1Knapsack(value,weight,W,n-1));
      }
      
         return dp[n][W] = O1Knapsack(value,weight,W,n-1);
   }
};

int main() {
   memset(dp,-1,sizeof(dp));
   int n, W;
   cout << "Enter the number of items: ";
   cin >> n;

   cout << "Enter the maximum weight of the knapsack: ";
   cin >> W;

   vector<int> value;
   vector<int> weight;

   for (int i = 0; i < n; i++) {
      int val, wt;
      cout << "Enter value and weight for item " << i + 1 << ": ";
      cin >> val >> wt;
      value.emplace_back(val);
      weight.emplace_back(wt);
   }

   Solution obj;
   double ans = obj.O1Knapsack(value, weight,W,n);
   cout << "The maximum value is " << ans;
   return 0;
}
