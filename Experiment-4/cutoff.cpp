#include <bits/stdc++.h>
using namespace std;

int main() {
    int K, N;
    cin >> K >> N;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < N; i++) {
        int score;
        cin >> score;

        if (minHeap.size() < K) {
            minHeap.push(score);
            if (minHeap.size() < K)
                cout << -1 << endl;
            else
                cout << minHeap.top() << endl;
        }
        else {
            if (score > minHeap.top()) {
                minHeap.pop();
                minHeap.push(score);
            }
            cout << minHeap.top() << endl;
        }
    }

    return 0;
}
