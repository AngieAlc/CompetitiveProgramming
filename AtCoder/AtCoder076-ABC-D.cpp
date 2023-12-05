/*
    https://img.atcoder.jp/abc076/editorial.pdf (page 8)
*/
#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
#define f(i,a,b) for(int i = a; i < b; i++)
#define fa(i,a,b) for(int i = a; i >= b; i--)

const int N = 1e6 + 5; 

vector <pair<double, pair<double,double>>> vec; 

double get(double l, double r, double v, double time){
    if(time < l) return v + l - time; 
    if(time <= r) return v; 
    return v + time - r; 
}
double speed(double time){
    double maxi = N;
    for(auto p: vec){
        maxi = min(maxi, get(p.second.first, p.second.second, p.first, time)); 
    } 
    return maxi; 
}

double n, t[105], v[105]; 

int main(){
    cin >> n; 

    f(i,1,n+1) cin >> t[i]; 
    f(i,1,n+1) cin >> v[i]; 

    int curr = 0; 
    f(i,0,n+2){
        vec.push_back({v[i], {curr, curr+t[i]}});
        curr += t[i];  
    }

    double area = 0; 

    f(i,0,curr){
        // [i, i + 0.5]
        area += (speed(i) + speed(i + 0.5)); 
        // [i + 0.5, i+1]
        area += (speed(i + 0.5) + speed(i+1)); 
    }
    area /= 4; 
    cout << setprecision(10) << fixed << area << "\n"; 

    return 0; 
}
