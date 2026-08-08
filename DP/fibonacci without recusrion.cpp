#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=5;
    vector<int> dp(n+1,-1);
    int prev2=0;
    int prev=1;
    for(int i=2;i<=n;i++){
        int curi=prev+prev2;
        prev2=prev;
        prev=curi;
    }
    cout<<prev;
    return 0;
}