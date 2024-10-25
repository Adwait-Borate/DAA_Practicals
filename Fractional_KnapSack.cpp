#include <bits/stdc++.h>

using namespace std;

class Item {
public:
   int value;
   int weight;

   Item(int value, int weight) {
      this->value = value;
      this->weight = weight;
   }
};

class Solution {
public:
   static bool comp(Item a, Item b) {
      double r1 = (double) a.value / (double) a.weight;
      double r2 = (double) b.value / (double) b.weight;
      return r1 > r2;
   }

   // function to return fractional weights
   double fractionalKnapsack(int W, vector<Item>& arr, int n) {
      sort(arr.begin(), arr.end(), comp);

      int curWeight = 0;
      double finalvalue = 0.0;

      for (int i = 0; i < n; i++) {
         if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
         } else {
            int remain = W - curWeight;
            finalvalue += (arr[i].value / (double) arr[i].weight) * (double) remain;
            break;
         }
      }

      return finalvalue;
   }
};

int main() {
   int n, weight;
   cout << "Enter the number of items: ";
   cin >> n;

   cout << "Enter the maximum weight of the knapsack: ";
   cin >> weight;

   vector<Item> arr;
   for (int i = 0; i < n; i++) {
      int value, wt;
      cout << "Enter value and weight for item " << i + 1 << ": ";
      cin >> value >> wt;
      arr.emplace_back(value, wt);
   }

   Solution obj;
   double ans = obj.fractionalKnapsack(weight, arr, n);
   cout << "The maximum value is " << setprecision(2) << fixed << ans;
   return 0;
}
