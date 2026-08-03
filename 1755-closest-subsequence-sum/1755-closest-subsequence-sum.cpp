
class Solution {
    void generateSubsets(const vector<int>& arr, int index, int currentSum, vector<int>& subsetSums) {
        if (index == arr.size()) {
            subsetSums.push_back(currentSum);
            return;
        }
        generateSubsets(arr, index + 1, currentSum, subsetSums);
        generateSubsets(arr, index + 1, currentSum + arr[index], subsetSums);
    }

public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> left(nums.begin(), nums.begin() + n / 2);
        vector<int> right(nums.begin() + n / 2, nums.end());
        vector<int> left_sums, temp_right_sums;
        generateSubsets(left, 0, 0, left_sums);
        generateSubsets(right, 0, 0, temp_right_sums);
        set<int> right_sums(temp_right_sums.begin(), temp_right_sums.end());
        int min_diff = INT_MAX;
        for (int x : left_sums) {
            int target = goal - x;
            auto it = right_sums.lower_bound(target);
            if (it != right_sums.end()) {
                min_diff = min(min_diff, abs(target - *it));
            }
            if (it != right_sums.begin()) {
                auto prev_it = it;
                prev_it--;
                min_diff = min(min_diff, abs(target - *prev_it));
            }

            if (min_diff == 0) {
                return 0;
            }
        }

        return min_diff;
    }
};

