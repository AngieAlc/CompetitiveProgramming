#include <bits/stdc++.h>
using namespace std; 
typedef long long ll; 
typedef pair<ll,ll> pll; 
typedef vector <long long> vll;
typedef vector <pair<ll,ll>> vpll; 
#define f(i,a,b) for(ll i=a ; i<b ; i++)
#define fa(i,a,b) for(ll  i=a ; i>=b ; i--)
const int inf=1e9;
const ll N=1e5+5;
const ll M=1e6+5;
const ll mod=1e9+7; 
 
int n, a[502];
int dp[502][502];
bool es(int x, int y){
    int w= (x+y)/2;
    bool c=1;
    f(i,x,w+1) if(a[i] != a[(x+y)-i]) {c=0; break;}
    return c;
}
int d_p(int u, int v){
    if(dp[u][v] != -1) return dp[u][v];
    if(v <= u+1){
        dp[u][v]=1;
        if(u+1 == v and a[u]!=a[v]) dp[u][v]=2;
        return dp[u][v];
    } 
    if(es(u,v)) return dp[u][v] = 1;
    int res = d_p(u+1,v) + 1 ;
 
    f(i,u+1,v+1){
        if(a[i] == a[u]){
            if(i == u+1) res = min(res, 1+d_p(i+1,v));
            else if(i < v)  res = min(res, d_p(u+1,i-1) + d_p(i+1,v)); 
            else {
                f(j,u+1,v-1) res = min( res, d_p(u+1,j) + d_p(j+1,v-1) );
                res = min(res, d_p(u+1,v-1)); 
            } 
        } 
    } 
    return dp[u][v] = res; 
}
int main(){
    cin >> n;
    f(i,1,502) f(j,i,502) dp[i][j] = -1;
    f(i,1,n+1) cin >> a[i];
    cout << d_p(1,n) << '\n';
    return 0;
}
