/*
    Idea: Split the vertices in two halves, solve the MIS for each subset of 
    those halves. Then for each (subset left half) find the maximum 
    length of a (subset right half) such that when combining both halves it remains
    as an Independent Set. 
*/

#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
const int N = 45, M = (1<<21); 

int n, m, dpr[M], rat[M]; 
int used[N]; // used[i]: mask of the right half that has an edge between (i, right half)
// dpr[i] : mask=i (right half) -> what's the MIS of that subset     
// rat[i] : specific MIS 

bool edge[N][N]; 
bool A[M], B[M]; 
// A[i] : is mask=i (left half) an independent set?
// B[i] : same for right half 

int main(){ 
    cin >> n >> m; 

    int mi = n/2; 
    // [0, mi] ... [mi+1, n-1]

    for(int i = 0; i < m; i++){
        int u, v; 
        cin >> u >> v; 
        edge[u][v] = edge[v][u] = true;

        if(u > v) swap(u, v); 
        if(u <= mi and v > mi){
            used[u] ^= (1<<(v-mi-1)); 
        }
    }

    ll ans = 1, mask = 1;  

    // right [mi+1, n-1]
    
    B[0] = true, dpr[0] = 0; 
    for(int i = 1; i < (1<<(n-mi-1)); i++){
        int id = 31 - __builtin_clz(i); 
        if(B[(i^(1<<id))]){
            B[i] = true; 

            for(int j = id-1; j >= 0; j--){
                if((i&(1<<j)) and edge[id+mi+1][j+mi+1]){
                    B[i] = false; 
                    break; 
                }
            }
        }
        if(B[i]) {
            dpr[i] = __builtin_popcount(i); 
            rat[i] = i; 

            if(dpr[i] > ans){
                ans = dpr[i]; 
                mask = ((ll) rat[i]<<(mi+1)); 
            }
        }
        else{
            for(int j = id; j >= 0; j--){
                if((i&(1<<j)) and dpr[i] < dpr[i^(1<<j)]){
                    dpr[i] = dpr[i^(1<<j)];
                    rat[i] = rat[i^(1<<j)]; 
                }
            }
        }
    }


    // left 
    A[0] = true; 
    for(int i = 1; i < (1<<(mi+1)); i++){
        int id = 31 - __builtin_clz(i); 
        if(!A[(i^(1<<id))]) continue; 
        A[i] = true; 

        for(int j = id-1; j >= 0; j--){
            if(i&(1<<j)){ 
                if(edge[id][j]){
                    A[i] = false; 
                    break;
                }
            }
        }

        if(!A[i]) continue; 

        // combining with right half
        int posible = (1<<(n-mi-1)) - 1, dont = 0; 
        for(int j = id; j >= 0; j--){
            if(i&(1<<j))
                dont |= used[j];
        }
        posible ^= dont; 

        int new_val = __builtin_popcount(i) + dpr[posible]; 
        ll new_mask = ((ll) i|((ll) rat[posible]<<(mi+1))); 

        if(new_val > ans){
            ans = new_val; 
            mask = new_mask; 
        }
    }

    cout << ans << "\n"; 
    for(ll i = 0; i < n; i++){
        if(mask&(1LL<<i)){
            cout << i << " "; 
        } 
    }

    return 0; 
}
