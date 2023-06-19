#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int n;
    vector <int>* adj;
public:
    Graph(int V) : n(V){
        adj = new vector <int>[V];
    }

    ~Graph(){
        delete[] adj;
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
    }

    bool dfs(int cur, vector <int> & path, int* v) const{
        //cout << cur << " ";
        path.push_back(cur);
        if(v[cur] == 1)
            return 1;
        v[cur] = 1;
        for(int x : adj[cur]){
            if(v[x] != 2)
                if(dfs(x, path, v))
                    return 1;
        }
        path.pop_back();
        v[cur] = 2;
        return 0;
    }

    bool cycle(vector <int> & path) const{
        //cout << n << " "; 
        int* v = new int[n];
        for(int i = 0; i < n; i++)
            v[i] = 0;

        for(int i = 0; i < n; i++){
            if(v[i] == 0){
                if(dfs(i, path, v)){
                    delete[] v;

                    int j = 0;
                    while(path[j++] != path.back());

                    for(int k = j; k < path.size(); k++)
                        path[k-j] = path[k];
                    path.resize(path.size() - j);

                    return true;
                }
            }
        }
        delete[] v;
        return false;
    }
};
