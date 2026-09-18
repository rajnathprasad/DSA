#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    int adj[n+1][m+1];
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u][v]=1;
    }
    return 0;
}