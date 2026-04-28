#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Item {
    string name;
    int weight;
    int value;
};

int knapsack(vector<Item>& items, int capacity, vector<vector<int>>& dp) {
    int n = items.size();

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            dp[i][w] = dp[i-1][w];
            if (items[i-1].weight <= w)
                dp[i][w] = max(dp[i][w], dp[i-1][w - items[i-1].weight] + items[i-1].value);
        }
    }

    return dp[n][capacity];
}

vector<Item> getSelectedItems(vector<Item>& items, vector<vector<int>>& dp, int capacity) {
    vector<Item> selected;
    int n = items.size();
    int w = capacity;

    for (int i = n; i >= 1; i--) {
        if (dp[i][w] != dp[i-1][w]) {
            selected.push_back(items[i-1]);
            w -= items[i-1].weight;
        }
    }

    return selected;
}

int main() {
    vector<Item> items = {
        {"Item1", 2, 6},
        {"Item2", 2, 10},
        {"Item3", 3, 12},
        {"Item4", 5, 15},
        {"Item5", 4, 8}
    };

    int capacity = 7;
    int n = items.size();

    cout << "===== 0/1 Knapsack Problem (Dynamic Programming) =====\n\n";

    cout << "Knapsack Capacity: " << capacity << "\n\n";

    cout << "Input Items:\n";
    cout << left << setw(10) << "Item" << setw(10) << "Weight" << setw(10) << "Value\n";
    cout << string(30, '-') << "\n";
    for (const auto& item : items)
        cout << setw(10) << item.name << setw(10) << item.weight << setw(10) << item.value << "\n";

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    int maxValue = knapsack(items, capacity, dp);

    cout << "\nDP Table:\n";
    cout << setw(6) << "";
    for (int w = 0; w <= capacity; w++)
        cout << setw(4) << w;
    cout << "\n" << string(6 + (capacity + 1) * 4, '-') << "\n";

    for (int i = 0; i <= n; i++) {
        if (i == 0)
            cout << setw(6) << "0";
        else
            cout << setw(6) << items[i-1].name;
        for (int w = 0; w <= capacity; w++)
            cout << setw(4) << dp[i][w];
        cout << "\n";
    }

    vector<Item> selected = getSelectedItems(items, dp, capacity);

    int totalWeight = 0;
    for (const auto& item : selected)
        totalWeight += item.weight;

    cout << "\nSelected Items:\n";
    cout << left << setw(10) << "Item" << setw(10) << "Weight" << setw(10) << "Value\n";
    cout << string(30, '-') << "\n";
    for (const auto& item : selected)
        cout << setw(10) << item.name << setw(10) << item.weight << setw(10) << item.value << "\n";

    cout << string(30, '-') << "\n";
    cout << setw(10) << "Total" << setw(10) << totalWeight << setw(10) << maxValue << "\n";
    cout << "\nMaximum Value : " << maxValue << "\n";
    cout << "Total Weight  : " << totalWeight << " / " << capacity << "\n";

    return 0;
}
