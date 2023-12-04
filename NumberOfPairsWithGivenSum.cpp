#include <bits/stdc++.h>
long long pairsWithGivenSum(int arr[], int n, int sum)
{
    // Write your code here
    long long ans = 0;

    unordered_map<int, int> mpp;

    for(int i = 0; i < n; i++) {
        int val = sum - arr[i];
        if(mpp[val]) ans += mpp[val];

        mpp[arr[i]]++;
    }

    return ans;

}
