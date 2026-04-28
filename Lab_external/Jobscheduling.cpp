#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

struct Job {
    string id;
    int deadline;
    int profit;
};

struct Result {
    vector<string> jobSequence;
    int totalProfit;
    int jobsCompleted;
};

Result jobScheduling(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
        return a.profit > b.profit;
    });

    int maxDeadline = 0;
    for (const auto& job : jobs)
        maxDeadline = max(maxDeadline, job.deadline);

    vector<int> slots(maxDeadline + 1, -1);

    Result result;
    result.totalProfit = 0;
    result.jobsCompleted = 0;
    result.jobSequence.resize(maxDeadline + 1, "");

    for (int i = 0; i < (int)jobs.size(); i++) {
        for (int j = min(maxDeadline, jobs[i].deadline); j >= 1; j--) {
            if (slots[j] == -1) {
                slots[j] = i;
                result.jobSequence[j] = jobs[i].id;
                result.totalProfit += jobs[i].profit;
                result.jobsCompleted++;
                break;
            }
        }
    }

    return result;
}

int main() {
    vector<Job> jobs = {
        {"J1", 2, 100},
        {"J2", 1, 19},
        {"J3", 2, 27},
        {"J4", 1, 25},
        {"J5", 3, 15}
    };

    cout << "===== Job Scheduling Algorithm (Greedy) =====\n\n";

    cout << "Input Jobs:\n";
    cout << left;
    cout << setw(8) << "Job ID" << setw(12) << "Deadline" << setw(10) << "Profit\n";
    cout << string(30, '-') << "\n";
    for (const auto& job : jobs)
        cout << setw(8) << job.id << setw(12) << job.deadline << setw(10) << job.profit << "\n";

    Result result = jobScheduling(jobs);

    cout << "\nScheduled Jobs (Time Slot → Job):\n";
    cout << string(30, '-') << "\n";
    for (int i = 1; i < (int)result.jobSequence.size(); i++) {
        if (!result.jobSequence[i].empty())
            cout << "  Slot " << i << "  →  " << result.jobSequence[i] << "\n";
    }

    cout << "\nJobs Completed : " << result.jobsCompleted << "\n";
    cout << "Total Profit   : " << result.totalProfit << "\n";

    return 0;
}
