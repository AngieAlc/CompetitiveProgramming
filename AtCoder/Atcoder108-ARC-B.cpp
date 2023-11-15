/*
    Idea: construir con la potencia de 2 mas grande, como un gusanito 100 pies. 
    (1) --1-- (2) --2-- (3) --4-- (4) --8-- (5) .... (x) --2^(x-1)-- (x+1)
        --0--     --0--     --0--     --0--                 --0--

    Luego ir construyendo recursivamente lo demas
*/
#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 

#define f(i,a,b) for(int i = a; i < b; i++)
#define fa(i,a,b) for(int i = a; i >= b; i--)

const int N = 1e5 + 5; 

int l; 
vector <pair<pair<int,int>, int>> v; 

int main(){
    cin >> l; 

    int x = 31 - __builtin_clz(l); 

    f(i,1,x+1){
        v.push_back({{i, i+1}, (1<<(i-1))}); 
        v.push_back({{i, i+1}, 0}); 
    }
    l--, l -= (1<<x); 
    int ini = (1<<x);

    while(l > 0){
        int r = 31 - __builtin_clz(l+1); 
        v.push_back({{r+1, x+1}, ini}); 
        l -= (1<<r); 
        ini += (1<<r); 
    }
    if(l == 0)
        v.push_back({{1, x+1}, ini}); 

    cout << x+1 << " " << v.size() << "\n"; 
    for(auto p: v)
        cout << p.first.first << " " << p.first.second << " " << p.second << "\n"; 

    return 0; 
}
