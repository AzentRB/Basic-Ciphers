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
int vmatrix[26][26];
char message[30],key[30],enarr[30];
int create_vigenere_matrix(){
    for(int i=0;i<26;i++) for(int j=0;j<26;j++) vmatrix[i][j]=((i+j)%26 + 65);
    return 0;
}
int print_vigenere_matrix(){
    cout << "The Vinegere Matrix is: " << endl;
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++) printf("%s ",&vmatrix[i][j]);
        cout << endl;
    }
    return 0;
}
int vigenere_encoding(){
    int space_counter=0,j=strlen(key);
    cout << "\nThe Encrypted message is: ";
    for(int i=0;i<strlen(message);i++){
        enarr[i]=((((message[i]+key[i%j])-130)%26)+65);
        printf("%s",&enarr[i]);
        space_counter=space_counter+1;
        if(space_counter==5) cout << " ",space_counter=0;    
    }
    return 0;
}
int vigenere_decoding(){
    int space_counter=0,j=strlen(key);
    cout << "\nThe dncrypted message is: ";
    for(int i=0;i<strlen(enarr);i++){
        int temp =((((enarr[i]-key[i%j])+130)%26)+65);
        printf("%s", &temp);
        space_counter=space_counter+1;
        if(space_counter==5) cout<<" ",space_counter=0;
    }
    return 0;
}
void remove_space_in_message(string tempmsg){
    int length=tempmsg.length();
    for(int i=0;i<length;i++) if(tempmsg[i]==' ') tempmsg.erase(i, 1),length--,i--;
    for(int j=0;j<strlen(message);j++) message[j]=tempmsg[j];
}
void get_msg_and_key()
{
    cout << "Please enter the message to be encrypted \n";gets(message);
    cout << "Please enter the key for encryption \n";gets(key);
}
void solve(){
    create_vigenere_matrix();print_vigenere_matrix();
    get_msg_and_key();remove_space_in_message(message);
    vigenere_encoding();vigenere_decoding();
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
