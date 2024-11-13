#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the 0/1 Knapsack problem
int knapSackRecursive(vector<int> &values, vector<int> &weights, int W, int n)
{
   if (n == 0 || W == 0)
   {
      return 0;
   }

   if (weights[n - 1] <= W)
   {
      // Return max of including or excluding the current item
      return max(
          values[n - 1] + knapSackRecursive(values, weights, W - weights[n - 1], n - 1),
          knapSackRecursive(values, weights, W, n - 1));
   }

   // If weight is greater than W, exclude the item
   return knapSackRecursive(values, weights, W, n - 1);
}

int main()
{
   int n, W;
   cout << "Enter the number of items: ";
   cin >> n;

   cout << "Enter the maximum weight of the knapsack: ";
   cin >> W;

   vector<int> values(n);
   vector<int> weights(n);

   for (int i = 0; i < n; i++)
   {
      cout << "Enter value and weight for item " << i + 1 << ": ";
      cin >> values[i] >> weights[i];
   }

   int maxValue = knapSackRecursive(values, weights, W, n);
   cout << "The maximum value achievable is " << maxValue;

   return 0;
}
