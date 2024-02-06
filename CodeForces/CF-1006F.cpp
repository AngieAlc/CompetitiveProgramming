/*
    Idea: split the path in two halves -> meet in the middle
    backtracking in both, then check #occurrences with map 
*/
#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
const int N = 25; 

ll k; 
ll a[N][N], ans; 
int n, m, X, Y; 
map <ll,int> ca; 

void go_down(int x, int y, ll curr){
    curr ^=  a[x][y]; 
    if(X == x and Y == y) {
        ca[curr]++; 
        return; 
    }
    if(y+1 <= Y){
        go_down(x, y+1, curr); 
    }
    if(x+1 <= X){
        go_down(x+1, y, curr); 
    }
}
void go_up(int x, int y, ll curr){ 
    if(X == x and Y == y){
        ans += ca[k^curr]; 
        return; 
    }
    curr ^= a[x][y];
    if(y-1 >= Y){
        go_up(x, y-1, curr); 
    }
    if(x-1 >= X){
        go_up(x-1, y, curr); 
    }
}
int main(){ 
    cin >> n >> m >> k; 

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j]; 
        }
    }

    int mid = 1 + (n + m)/2; 

    for(int i = 1; i <= n; i++){
        int j = mid - i; 
        if(j < 1 or j > m) continue; 

        ca.clear(); 
        X = i, Y = j; 
        go_down(1, 1, 0); 
        go_up(n, m, 0);
    }

    cout << ans << "\n"; 
    return 0; 
}
