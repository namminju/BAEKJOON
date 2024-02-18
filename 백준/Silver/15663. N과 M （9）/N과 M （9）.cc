#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generateSequence(vector<int>& nums, int m, vector<int>& sequence, vector<bool>& chosen) {
    if (sequence.size() == m) { 
        for (int num : sequence) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (!chosen[i]) {
            chosen[i] = true;
            sequence.push_back(nums[i]);
            generateSequence(nums, m, sequence, chosen);
            sequence.pop_back();
            chosen[i] = false;

            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                ++i;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end()); 

    vector<int> sequence;
    vector<bool> chosen(n, false); 

    generateSequence(nums, m, sequence, chosen);

    return 0;
}
