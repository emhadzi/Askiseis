#include <bits/stdc++.h>
using namespace std;

int n, m, k;
bool found[1000005];
int anc[1000005], sz[1000005];

inline int root(int x){
    if(anc[x] == x)
        return x;
    return anc[x] = root(anc[x]);
}

void join(int a, int b){
    a = root(a);
    b = root(b);
    if(a == b)
        return;
    if(sz[a] < sz[b])
        swap(a, b);
    anc[b] = a;
    if(sz[a] == sz[b])
        sz[a]++;
}

int main(){
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++){
        anc[i] = i;
        sz[i] = 0;
    }

    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        join(a, b);
    }

    for(int i = 1; i <= n; i++)
        found[root(i)] = 1;

    int cnt = 0;
    for(int i = 1; i <= n; i++)
        cnt += found[i];
    cout << max(1, cnt - k) << "\n"; 
}
