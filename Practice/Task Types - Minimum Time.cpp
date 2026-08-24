#include <bits/stdc++.h>
using namespace std;

int solve(vector<char>& tasks, int K) {
    // Write your solution here

}

int main() {
    int N;
    cin >> N;

    vector<char> tasks(N);

    for (int i = 0; i < N; i++) {
        cin >> tasks[i];
    }

    int K;
    cin >> K;

    cout << solve(tasks, K) << endl;

    return 0;
}