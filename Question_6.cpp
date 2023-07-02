class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_set<int> original_set;
        vector<int> original;

        for (int num : changed) {
            if (original_set.count(num * 2) > 0) {
                original.push_back(num);
                original_set.erase(num * 2);
            } else {
                original_set.insert(num);
            }
        }

        if (!original_set.empty()) {
            return {}; // Return an empty array if there are unused elements
        }

        return original;
    }
};
