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

    if (index >= weights.size() || currentSum > target) {  // Stop if out of bounds or sum exceeded
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
    int M = 35;  // Target sum
    int choice;

    // Prompt user for input
    cout << "Select the test case:\n";
    cout << "1. w = {5, 7, 10, 12, 15, 18, 20}\n";
    cout << "2. w = {20, 18, 15, 12, 10, 7, 5}\n";
    cout << "3. w = {15, 7, 20, 5, 18, 10, 12}\n";
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    vector<int> weights; // Vector to hold selected weights

    // Using switch-case to assign weights based on user choice
    switch (choice) {
        case 1: weights = {5, 7, 10, 12, 15, 18, 20}; break;
        case 2: weights = {20, 18, 15, 12, 10, 7, 5}; break;
        case 3: weights = {15, 7, 20, 5, 18, 10, 12}; break;
        default: cout << "Invalid choice!" << endl; return 0;
    }

    // Print subsets that sum to M
    cout << "Subsets with sum " << M << " found:\n";
    vector<int> current;  // Vector to hold the current subset
    findSubsetsWithSum(weights, M, current, 0, 0);  // Start backtracking

    return 0;
}
