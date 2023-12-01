#include <bits/stdc++.h>
vector<int> maximumsumSubarray(vector<int> &arr, int n) {
  // Write your code here

  // come up with the maximum sum
  int maximumSum = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
    maximumSum = max(maximumSum, sum);
    if (sum < 0)
      sum = 0;
  }

  // find all the subArray with the sum
  vector<vector<int>> result;
  vector<int> currentSubarray;
  // reinitialise the sum with zero
  sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
    // cout << "sum = " << sum << endl;
    currentSubarray.push_back(arr[i]);
    // If the sum equals the maximum sum, add the current subarray to the result
    if (sum == maximumSum) {
        // cout << "hit" << endl;
      result.push_back(currentSubarray);
    //   cout << result.size() << endl;
    }
    // If the sum becomes negative, reset the subarray
    if (sum < 0) {
      sum = 0;
      currentSubarray.clear();
    }

    if (maximumSum == 0) {
      // If all elements are negative, return the array with a single maximum
      // element
      int maxElement = *max_element(arr.begin(), arr.end());
      result.push_back({maxElement});
    }
  }

//   cout << result.size() << endl;

  return result[0];
}
