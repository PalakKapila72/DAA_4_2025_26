#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<char> attendance(N);
    for (int i = 0; i < N; i++) {
        cin >> attendance[i];
    }

    unordered_map<int, int> mp;
    int sum = 0;
    int maxLen = 0;

    // Base case
    mp[0] = -1;

    for (int i = 0; i < N; i++) {
        if (attendance[i] == 'P')
            sum += 1;
        else
            sum -= 1;

        if (mp.find(sum) != mp.end()) {
            maxLen = max(maxLen, i - mp[sum]);
        } else {
            mp[sum] = i;
        }
    }

    cout << maxLen;
    return 0;
}
