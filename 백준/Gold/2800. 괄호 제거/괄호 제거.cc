#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <string>

using namespace std;

void generate_subsets(const vector<pair<int, int>>& nums, int index, vector<pair<int, int>>& subset, vector<vector<pair<int, int>>>& subsets) {
    if (index == nums.size()) {
        subsets.push_back(subset);
        return;
    }

    generate_subsets(nums, index + 1, subset, subsets);

    subset.push_back(nums[index]);
    generate_subsets(nums, index + 1, subset, subsets);
    subset.pop_back();
}

vector<vector<pair<int, int>>> generate_subsets(const vector<pair<int, int>>& nums) {
    vector<vector<pair<int, int>>> subsets;
    vector<pair<int, int>> subset;
    generate_subsets(nums, 0, subset, subsets);
    return subsets;
}

void make_remove_string(const vector<pair<int, int>>& paren_pair, const string& original_str, string& str, int num, set<string>& result) {
    if (num == 0) {
        result.insert(str);
        return;
    }

    for (const auto& subset : generate_subsets(paren_pair)) {
        string modified_str = original_str;
        for (const auto& p : subset) {
            modified_str[p.first] = modified_str[p.second] = ' ';
        }
        modified_str.erase(remove(modified_str.begin(), modified_str.end(), ' '), modified_str.end());
        result.insert(modified_str);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    vector<pair<int, int>> paren_pair;
    stack<int> find_par;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            find_par.push(i);
        }
        else if (str[i] == ')') {
            paren_pair.push_back(make_pair(find_par.top(), i));
            find_par.pop();
        }
    }

    set<string> result;
    for (int i = 1; i <= paren_pair.size(); i++) {
        make_remove_string(paren_pair, str, str, i, result);
    }

    for (const auto& r : result) {
        if (r != str) {
            cout << r << "\n";
        }

    }
    return 0;
}
