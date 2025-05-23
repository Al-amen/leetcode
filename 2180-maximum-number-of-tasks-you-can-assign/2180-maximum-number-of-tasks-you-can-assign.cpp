class Solution {
public:
    bool canAssign(int k, const vector<int>& tasks, const vector<int>& workers, int pills, int strength) {
        multiset<int> availableWorkers(workers.end() - k, workers.end());
        int remainingPills = pills;

        for (int i = k - 1; i >= 0; --i) {
            int task = tasks[i];

            // Try to find a worker who can do it without a pill
            auto it = availableWorkers.lower_bound(task);
            if (it != availableWorkers.end()) {
                availableWorkers.erase(it);
            } else {
                // Try to use a pill
                if (remainingPills == 0) return false;

                it = availableWorkers.lower_bound(task - strength);
                if (it == availableWorkers.end()) return false;

                availableWorkers.erase(it);
                remainingPills--;
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int left = 0, right = min((int)tasks.size(), (int)workers.size());
        int result = 0;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
        
    }
};