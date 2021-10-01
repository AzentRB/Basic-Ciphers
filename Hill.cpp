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
#include <vector>
#include <map>
#include <unordered_map>
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
#define max 10

void solve(){
    string plaintxt;
	int len,i,j,k,m;
	cout << "Enter plaintxt : ";
	cin >> plaintxt;
	len = plaintxt.length();
	cout << "Enter dimension of key: ";
	cin >> m;
	float key[max][max];
	cout << "Enter elements of key: \n";
	for(i=0;i<m;i++) for(j=0;j<m;j++) cin >> key[i][j];
	cout << "\nKey: ";
	for(i=0;i<m;i++){
		for(j=0;j<m;j++) cout << key[i][j] << " ";
		cout << endl;
	}
	float textkeyrix[len][1];
	cout << "\nPlain Text keyrix: \n";
	for(i=0;i<len;i++)
		if(isupper(plaintxt[i])){
			textkeyrix[i][0] = int(plaintxt[i] - 65);
			cout << textkeyrix[i][1] << "\n";
		}
		else{
			textkeyrix[i][0] = int(plaintxt[i] - 97);
			cout << textkeyrix[i][1] << "\n";
		}
	cout << "\nkeyrix Multiplication: \n";
	float c[len][1],e[len][1];
	for(i=0;i<m;i++){
		for(j=0;j<1;j++){
			c[i][j]=0;
			for (k=0;k<3;k++) c[i][j]+=key[i][k]*textkeyrix[k][j];
			e[i][j]=c[i][j];
			cout << c[i][j] << endl;
		}
	}
	cout << "\nEncrypted key matrix: \n";
	for(i=0;i<m;i++)
		for(j=0;j<1;j++){
			c[i][j] = int(c[i][j]) % 26;
			cout << c[i][j] << "\n";
		}
	char ch;
	cout << "\nCipher Text/ Encrypted Text:  ";
	for(i=0;i<m;i++)
		for(j=0;j<1;j++){
            if(isupper(plaintxt[i])) ch = c[i][j]+65;
			else ch = c[i][j]+97;
			cout << ch ;
		}
	cout << endl;
	float inv[m][m],det=0;
	for(i=0;i<3;i++) det+=(key[0][i]*(key[1][(i+1)%3]*key[2][(i+2)%3]-key[1][(i+2)%3]*key[2][(i+1)%3]));
	for(i = 0; i < m; i++){
        for(j = 0; j < m; j++){
            inv[i][j]=((key[(j+1)%3][(i+1)%3]*key[(j+2)%3][(i+2)%3])-(key[(j+1)%3][(i+2)%3]*key[(j+2)%3][(i+1)%3]))/det;
            cout << inv[i][j] << " ";
        }
        cout << endl;
    }
    float d[len][1];
    char ch2;
    cout << "Decrypted Matrix: \n";
	for(i=0;i<m;i++)
		for(j=0;j<1;j++){
			d[i][j] = 0;
			for (k=0;k<3;k++) d[i][j] += inv[i][k] * e[k][j];
			cout << d[i][j] << endl;
		}
	cout << "Decrypted Text: ";
	for(i=0;i<m;i++)
		for(j=0;j<1;j++){
            ch2=(int(d[i][j]))+97;
            cout << ch2;		
		}
}
int main(){
    fast_cin();
    ll t=1;
    //cin >> t;
    for(int it=1;it<=t;it++) {
        //cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}