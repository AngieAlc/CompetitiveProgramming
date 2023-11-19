/*
    Idea: Bellman-ford (camino mas corto al cambiarle signo a los pesos) + detectar ciclos negativos 
*/

#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
const int N = 1005; 
const ll inf = 1e18;  

ll d[N];
bool negative[N]; 
int n, m; 

struct edge{
    int u, v; ll w; 
}; 

vector <edge> edges; 

int main(){
    cin >> n >> m; 

    for(int i = 0; i < m; i++){
        int u, v; ll w; 
        cin >> u >> v >> w; 

        edges.push_back({u, v, -w}); 
    }

    for(int i = 2; i <= n; i++) d[i] = inf; 

    for(int i = 0; i < n-1; i++){
        for(edge p: edges){
            if(d[p.u] + p.w < d[p.v]){
                d[p.v] = d[p.u] + p.w;  
            }
        }
    }

    for(int i = 0; i < n-1; i++){
        for(edge p: edges){
            if(negative[p.u] or d[p.v] > d[p.u] + p.w){
                negative[p.v] = true;
            }
        }
    }
   
    if(negative[n]) cout << "inf\n"; 
    else cout << -d[n] << "\n"; 

    return 0; 
}
