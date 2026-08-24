#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int>& friction) {
    // Write your solution here
    int n=friction.size();

    long long prefix=0;
    long long totalDamage=0;
    long long maxReduction=0;

    for(int i=0;i<n;i++){
        prefix+=friction[i];
        totalDamage+=prefix;
        long long contribution=1LL*friction[i]*(n-i);
        maxReduction=max(maxReduction, contribution);
    }
    return totalDamage-maxReduction;
}

int main() {
    int N;
    cin >> N;

    vector<int> friction(N);

    for (int i = 0; i < N; i++) {
        cin >> friction[i];
    }

    cout << solve(friction) << endl;

    return 0;
}