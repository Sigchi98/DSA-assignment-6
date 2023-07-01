class Solution {
public:
    vector<int> findPermutation(string& s) {
        int n = s.length();
        vector<int> perm(n + 1);

        int low = 0, high = n;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'I') {
                perm[i] = low++;
            } else {
                perm[i] = high--;
            }
        }
        perm[n] = low; // or high (same value at this point)

        return perm;
    }
};
