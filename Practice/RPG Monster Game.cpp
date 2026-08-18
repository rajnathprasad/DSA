#include <bits/stdc++.h>
using namespace std;

int solve(int n, int e, vector<int> power, vector<int> bonus) {
    // Write your code here
    int count=0;
    vector<pair<int, int>> monsters;
    for(int i=0;i<n;i++){
        monsters.push_back({power[i],bonus[i]});
    }
    sort(monsters.begin(), monsters.end());

    for(int i=0;i<n;i++){
        if(e>=monsters[i].first){
            count++;
            e+=monsters[i].second;
        }else break;
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    int e;
    cin >> e;

    vector<int> power(n);
    vector<int> bonus(n);

    for(int i = 0; i < n; i++)
        cin >> power[i];

    for(int i = 0; i < n; i++)
        cin >> bonus[i];

    cout << solve(n, e, power, bonus);

    return 0;
}