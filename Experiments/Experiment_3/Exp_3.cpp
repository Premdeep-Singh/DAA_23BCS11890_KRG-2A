// Given an array arr[] of positive integers which may contain duplicate elements, return the frequency of each distinct element.

#include <bits/stdc++.h>

using namespace std;

// Solution
class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& arr) {
        // code here
        map<int, int> mp;
        for (auto &val: arr) {
            mp[val]++;
        }
        
        vector<vector<int>> freq;
        for (auto p : mp) {
            freq.push_back({p.first, p.second});
        }
        
        return freq;
    }
};


int main() {
    Solution sol;

    vector<int> arr = {1, 2, 2, 3, 3, 5};

    vector<vector<int>> result = sol.countFreq(arr);

    for (auto &v : result) {
        cout << "[" << v[0] << ", " << v[1] << "] " ;
    }

    return 0;
}
