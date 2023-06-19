#include <bits/stdc++.h>
using namespace std;

int n, m, k;
bool found[1000005];
int anc[1000005], sz[1000005];

int root(int x){
    if(anc[x] == x)
        return x;
    return root(anc[x]);
}

void join(int a, int b){
    int ra = anc[a], rb = anc[b];
    if(sz[ra] < sz[rb])
        anc[ra] = rb;
    else if(sz[ra] > sz[rb])
        anc[rb] = ra;
    else{
        anc[ra] = rb;
        sz[rb]++; 
    }
}

int main(){
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++){
        anc[i] = i;
        sz[i] = 0;
    }

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        join(a, b);
    }

    for(int i = 1; i <= n; i++)
        found[root(i)] = 1;

    int cnt = 0;
    for(int i = 1; i <= n; i++)
        cnt += found[i];
    cout << max(1, cnt - k) << "\n"; 
}
