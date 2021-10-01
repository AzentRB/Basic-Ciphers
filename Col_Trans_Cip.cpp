#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
map<int, int> keys;
void set_fun(string key){ for(size_t i=0;i<key.length();i++) keys[key[i]]=i; }
string enc(string lol, string key){
    int col=key.length(),j,row=lol.length()/col;
    string cipher = "";
    if (lol.length() % col) row += 1;
    char matrix[row][col];
    for(int i=0,k=0;i<row;i++)
        for(int j=0;j<col;){
            k++;
        }
    for(map<int,int>::iterator ii=keys.begin();ii!=keys.end();++ii){
        for(int i=0;i<row;i++) if(isalpha(matrix[i][j])||matrix[i][j]==' '||matrix[i][j]=='_') cipher+=matrix[i][j];
    }
    return cipher;
}
string dec(string lol,string key){
    int col=key.length(),row=lol.length()/col;
    char matr[row][col];
    for(map<int, int>::iterator ii=keys.begin();ii!=keys.end();++ii) ii->second=ind++;
    char matrix[row][col];
    int k=0;
    for(int l=0,j;key[l]!='\0';k++){
        j=keys[key[l++]];
        for(int i=0;i<row;i++) matrix[i][k]=matr[i][j];
    }
    string msg = "";
    for(int i=0;i<row;i++) for(int j=0;j<col;j++) if(matrix[i][j]!='_') msg+=matrix[i][j];
    return msg;
}
void solve(){
    string msg="this is my laptop",key="MALHR";
    string temp=enc(msg, key);
    cout << "Encrypted: " << enc(msg, key) << endl << "Decrypted: " << dec(temp,key) << endl;
}
int main()
{
    fast_cin();
    ll t=1;
    //cin >> t;
    for(int it=1;it<=t;it++) {
        //cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}
