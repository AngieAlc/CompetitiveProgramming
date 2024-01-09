#include <bits/stdc++.h>
using namespace std; 
 
#define f(i,a,b) for(int i = a; i < b; i++)
const int N = 1e5 + 6, M = 1e6 + 5; 
 
 
int n, a[N], b[N], ans[N], pre[N], id; 
int dp[1<<10][1<<10][11], ID[1<<10][1<<10][11]; 
 
int main(){
    int pr = 0; 
    cin >> n; 
 
    f(i,1,n+1) cin >> a[i]; 
 
    f(i,1,n+1) cin >> b[i]; 
 
    f(i,0,1<<10){
        int x = __builtin_popcount(i); 
        f(j,0,1<<10){
            f(k,x+1,11) dp[j][i][k] = -M; 
        }
    }
    f(i,1,n+1){
        int x, y;
        x = a[i] >> 10; 
        y = a[i] - (x << 10); 
 
        ans[i] = 1; 
        
        f(j,0,1<<10){
            int p = __builtin_popcount((x&j)); 
            if(p <= b[i] and b[i] - p <= 10 and ans[i] < 1 + dp[j][y][b[i]-p]){
                pre[i] = ID[j][y][b[i]-p]; 
                ans[i] = 1 + dp[j][y][b[i]-p]; 
            }
        }
 
        f(j,0,1<<10){
            int p = __builtin_popcount((y&j));
            if(dp[x][j][p] < ans[i]){
                dp[x][j][p] = ans[i]; 
                ID[x][j][p] = i; 
            }  
        }  
 
        if(ans[i] > pr){
            id = i; 
            pr = ans[i]; 
        }
    }
 
    vector <int> ra; 
    while(id > 0){
        ra.push_back(id); 
        id = pre[id]; 
    }
 
    reverse(ra.begin(), ra.end()); 
 
    cout << ra.size() << "\n"; 
    for(int x: ra) cout << x << " "; 
    cout << "\n"; 
 
    return 0; 
}
