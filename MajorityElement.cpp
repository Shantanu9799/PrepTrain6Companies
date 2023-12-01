#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int cnt = 1, elem = arr[0];
	for(int i = 1; i < n; i++) {
		if(arr[i] == elem) cnt++;
		else cnt--;
		if(cnt == -1) {
			cnt = 1;
			elem = arr[i];
		}
	}

	cnt = 0;
	for(int i = 0; i < n; i++) {
		if(arr[i] == elem) cnt++;
	}

	return cnt > n/2 ? elem : -1;
}