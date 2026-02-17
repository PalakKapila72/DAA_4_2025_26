class Solution {
public:
    bool canPaint(vector<int>& arr, int k, long long maxTime) {
        int painters = 1;
        long long currentSum = 0;

        for (int board : arr) {

            if (board > maxTime)
                return false;

            if (currentSum + board <= maxTime) {
                currentSum += board;
            }
            else {
                painters++;
                currentSum = board;

                if (painters > k)
                    return false;
            }
        }

        return true;
    }

    long long minTime(vector<int>& arr, int k) {

        long long low = *max_element(arr.begin(), arr.end());
        long long high = 0;

        for (int x : arr)
            high += x;

        long long answer = high;

        while (low <= high) {

            long long mid = low + (high - low) / 2;

            if (canPaint(arr, k, mid)) {
                answer = mid;
                high = mid - 1; 
            }
            else {
                low = mid + 1;  
            }
        }

        return answer;
    }
};
