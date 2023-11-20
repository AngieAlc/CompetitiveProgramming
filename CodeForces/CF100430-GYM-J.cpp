/*
    Idea: probar todas las opciones (de mayor a menor) + opmitizaciones + fe
*/
#include <bits/stdc++.h> 
using namespace std; 

#define f(i,a,b) for(int i = a; i < b; i++)
#define fa(i,a,b) for(int i = a; i >= b; i--)

const int N = 500; 

int s[N]; 
int n, k, sum; 
vector <int> v; 

int get(int l, int r){
    return s[r] - s[l-1]; 
}

void go(int c, int maxi){
    if(c == k){
        if(sum == n * (k - 1)){
            cout << "YES\n"; 

            for(int x: v) cout << n - x << " "; 
            cout << "\n"; 
            exit(0); 
        }
        return; 
    }
    int need = k - c, want = n * (k - 1) - sum; 
    if(maxi < need) return; 
    if(get(1, need) > want or get(maxi-need+1, maxi) < want) return; 

    fa(i,maxi,1){
        if(sum + i*i > n * (k -1)) continue; 
        sum += i * i; 
        v.push_back(i*i); 

        go(c+1, i-1); 
        sum -= i * i; 
        v.pop_back(); 
    }
}
int main(){
    freopen("squary.in","r",stdin); 
	freopen("squary.out","w",stdout); 

    cin >> n >> k; 

    f(i,1,N) s[i] = s[i-1] + (i * i); 

    int ra = sqrt(n);
    if(ra * ra == n) ra--; 

    go(0, ra); 

    cout << "NO\n"; 
    return 0; 
}
