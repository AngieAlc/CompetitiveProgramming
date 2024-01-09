/*
    Idea: try to understand my code (idk how to explain it)
*/
#include <bits/stdc++.h> 
using namespace std; 

#define f(i,a,b) for(int i = a; i < b; i++)
#define fa(i,a,b) for(int i = a; i >= b; i--)
const int N = 205; 

int n, m, ans; 
int down[N][N], ri[N][N], le[N][N];  
char a[N][N];

int main(){
    freopen("fortmoo.in", "r", stdin); 
    freopen("fortmoo.out","w", stdout); 
    
    cin >> n >> m; 
    
    f(i,1,n+1) f(j,1,m+1) cin >> a[i][j]; 

    // ri
    fa(i,m,1){
        f(j,1,n+1){
            if(a[j][i] == 'X') continue; 
            ri[j][i] = i; 
            if(i != m and a[j][i+1] != 'X') ri[j][i] = ri[j][i+1]; 
        }
    }

    // le
    f(i,1,m+1){
        f(j,1,n+1){
            if(a[j][i] == 'X') continue; 
            le[j][i] = i; 
            if(i != 1 and a[j][i-1] != 'X') le[j][i] = le[j][i-1]; 
        }
    }

    // down
    fa(i,n,1){
        f(j,1,m+1){
            if(a[i][j] == 'X') continue; 
            down[i][j] = i; 
            if(i != n and a[i+1][j] != 'X') down[i][j] = down[i+1][j]; 
        }
    }

    // go right ( < )
    f(i,1,n+1){
        f(j,1,m+1){
            if(a[i][j] == 'X') continue; 
            int id = down[i][j], curr = j;  

            while(curr <= m and a[i][curr] != 'X' and id >= i){
                if(down[i][curr] >= id){
                    ans = max(ans, (id - i + 1) * (curr - j + 1)); 
                }
                while(id >= i and ri[id][j] <= curr) id--; 
                curr++; 
            }
        }
    }
  
    // go left  ( > )
    f(i,1,n+1){
        fa(j,m,1){
            if(a[i][j] == 'X') continue; 
            int id = down[i][j], curr = j;  

            while(curr >= 1 and a[i][curr] != 'X' and id >= i){
                if(down[i][curr] >= id){
                    ans = max(ans, (id - i + 1) * (j - curr + 1)); 
                }
                while(id >= i and le[id][j] >= curr) id--; 
                curr--; 
            }
        }
    }
    cout << ans << "\n"; 

    return 0; 
}
