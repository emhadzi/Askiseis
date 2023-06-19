#include <bits/stdc++.h>
using namespace std;

int n, m, q;
int a, b, c;
vector <vector <pair <int, int> > > adj;
vector <int> path;
vector <bool> v;

int dfs(int src, int left){
    v[src] = 1;
    path.push_back(src);
    if(src == b)
        return 1;
    for(auto& x : adj[src]){
        if(!v[x.first] && x.second <= c){
            int fills = (left >= x.second ? dfs(x.first, left - x.second) 
                : (dfs(x.first, c - x.second) + 1));
            if(fills > 0)
                return fills;
        }
    }
    path.pop_back();
    return -(1 << 30);
}

void solve(){
    scanf("%d%d%d", &a, &b, &c);

    path = vector <int>();
    v = vector <bool>(n);
    
    int fills = dfs(a, c);
    if(fills > 0){
        cout << "POSSIBLE: " << fills << " fill(s), ";
        for(int x : path)
            cout << x << " ";
        cout << "\n";
    }
    else
        cout << "IMPOSSIBLE\n";
}

int main(){
    scanf("%d%d", &n, &m);

    adj = vector <vector <pair <int, int> > >(n);
    for(int i = 0; i < m; i++){
        int u, v, l;
        scanf("%d%d%d", &u, &v, &l);
        adj[u].push_back({v, l});
        adj[v].push_back({u, l});
    }

    scanf("%d", &q);
    while(q--)
        solve();
}
