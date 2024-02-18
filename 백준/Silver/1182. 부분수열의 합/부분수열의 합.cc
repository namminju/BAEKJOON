#include <iostream>
#include <vector>

using namespace std;

int count_subsequences(const vector<int>& nums, int target, int index, int sum) {
    if (index == nums.size()) {
        return sum == target ? 1 : 0;
    }

    return count_subsequences(nums, target, index + 1, sum) +
        count_subsequences(nums, target, index + 1, sum + nums[index]);
}

int main() {
    int N, S;
    cin >> N >> S;

    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    int result = count_subsequences(nums, S, 0, 0);
    if (S == 0) {
        result--;// 공집합
    }
    cout << result << endl;

    return 0;
}
