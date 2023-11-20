/*
    Idea: check all posibilities with backtracking :) 
*/

#include <bits/stdc++.h> 
using namespace std; 

#define f(i,a,b) for(int i = a; i < b; i++)
#define fa(i,a,b) for(int i = a; i >= b; i--)

const int N = 10;

int a[N][N], row[N][N], col[N][N]; 
int c[N][N]; 

int grupo(int l, int r){
    return 2 * ((l - 1) / 4) + 1 + (r - 1) / 4; 
}
void clear(){
    f(i,1,N) f(j,1,N) a[i][j] = row[i][j] = col[i][j] = c[i][j] = 0; 
}
bool go(int x, int y){
    if(x == 9) return 1; 
    if(a[x][y]){
        if(y == 8) return go(x+1, 1); 
        return go(x, y+1); 
    }
    int group = grupo(x, y); 
    f(i,1,9){
        if(!row[x][i] and !col[y][i] and c[group][i] <= 1){
            a[x][y] = i; 
            row[x][i] = col[y][i] = 1; 
            c[group][i]++; 

            bool flag = (y == 8) ? go(x+1, 1) : go(x, y+1); 
            if(flag) return 1; 
            
            a[x][y] = row[x][i] = col[y][i] = 0; 
            c[group][i]--; 
        }
    }
    return 0; 
}
void solve(int test){
    cout << "Test case #" << test << ": "; 
    
    bool flag = false; 

    f(i,1,9){
        f(j,1,9){
            cin >> a[i][j]; 
            if(a[i][j]){
                int group = grupo(i, j); 

                if(row[i][a[i][j]] or col[j][a[i][j]] or c[group][a[i][j]] > 1)
                    flag = true; 
                row[i][a[i][j]] = col[j][a[i][j]] = 1;
                c[group][a[i][j]]++; 
            }
        }
    }

    if(flag or !go(1, 1)){
        cout << "NO\n"; 
    }
    else{
        cout << "YES\n";
        f(i,1,9) { f(j,1,9) cout << a[i][j] << " "; cout << "\n"; } 
    }
    clear(); 
}
int main(){
    int t; cin >> t; 
    f(i,1,t+1) solve(i); 
    return 0; 
}
