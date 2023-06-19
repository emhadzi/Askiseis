#include <bits/stdc++.h>
using namespace std;

int n, m;
int deg[10005];

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        deg[a]++;
        deg[b]++;
    }
    vector <int> odd;
    for(int i = 0; i < n; i++)
        if(deg[i] % 2)
            odd.push_back(i);
    if(odd.size() == 0)
        cout << "CYCLE\n";
    else if(odd.size() == 2)
        cout << "PATH " << odd[0] << " " << odd[1] << "\n";
    else
        cout << "IMPOSSIBLE\n"; 
}
