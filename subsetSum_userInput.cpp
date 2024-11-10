#include <iostream>
#include <vector>
using namespace std;

// Function to find and print all subsets that sum to M
void findSubsetsWithSum(const vector<int>& weights, int target, vector<int>& current, int index, int currentSum) {
    if (currentSum == target) {  // Base case: if current sum matches the target
        cout << "{ ";
        for (int num : current) {
            cout << num << " ";
        }
        cout << "}" << endl;
        return;
    }

    if (index >= weights.size() || currentSum > target) {  // Stop if out of bounds or sum exceeded - OBSE
        return;
    }

    // Take the element
    current.push_back(weights[index]);
    findSubsetsWithSum(weights, target, current, index + 1, currentSum + weights[index]);
    current.pop_back();  // Backtrack

    // Not take the element
    findSubsetsWithSum(weights, target, current, index + 1, currentSum);
}

int main() {
    int target_sum;  // Target sum
    int n;  // Number of weights

    // Prompt user for input
    cout << "Enter the number of weights: ";
    cin >> n;

    vector<int> weights(n); // Vector to hold weights
    cout << "Enter the weights: ";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i]; // Input weights
    }

    cout << "Enter the target sum: ";
    cin >> target_sum;  // Input target sum

    // Print subsets that sum to M
    cout << "Subsets with sum " << target_sum << " found:\n";
    vector<int> current;  // Vector to hold the current subset
    findSubsetsWithSum(weights, target_sum, current, 0, 0);  // Start backtracking

    return 0;
}
