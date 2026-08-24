#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int A) {
    // Write your solution here
    int n=arr.size();
    int maxi=INT_MIN;
    int total=0;
    for(int k=1;k<n-1;k++){
        if (arr[k] > 0 && arr[k + 1] > 0) {
            maxi = max(maxi, arr[k] + arr[k + 1]);
        }
    }
    return maxi+A;
}

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int A;
    cin >> A;

    cout << solve(arr, A) << endl;

    return 0;
}