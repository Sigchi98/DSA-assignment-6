class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLength = 0;
        int count = 0;
        unordered_map<int, int> countMap;
        countMap[0] = -1;

        for (int i = 0; i < nums.size(); i++) {
            count += nums[i] == 0 ? -1 : 1;

            if (countMap.find(count) != countMap.end()) {
                int prevIndex = countMap[count];
                maxLength = max(maxLength, i - prevIndex);
            } else {
                countMap[count] = i;
            }
        }

        return maxLength;
    }
};

// simpler approach / Brute approach
// class Solution {
// public:
//     int findMaxLength(vector<int>& nums) {
//         int maxLength = 0;
//         int n = nums.size();

//         for (int i = 0; i < n - 1; i++) {
//             for (int j = i + 2; j <= n; j++) {
//                 int countZeros = 0;
//                 int countOnes = 0;
//                 for (int k = i; k < j; k++) {
//                     if (nums[k] == 0) {
//                         countZeros++;
//                     } else {
//                         countOnes++;
//                     }
//                 }
//                 if (countZeros == countOnes && j - i > maxLength) {
//                     maxLength = j - i;
//                 }
//             }
//         }

//         return maxLength;
//     }
// };
