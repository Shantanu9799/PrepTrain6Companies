#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    if (n == 0) {
        return 0;
    }

    unordered_set<int> numSet(arr.begin(), arr.end());
    int maxLength = 0;

    for (int num : numSet) {
        if (numSet.find(num - 1) == numSet.end()) {
            int currentNum = num;
            int currentLength = 1;

            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum += 1;
                currentLength += 1;
            }

            maxLength = max(maxLength, currentLength);
        }
    }

    return maxLength;
}