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
int slu(int position){ return (position+4)%5; }
int srd(int position){ return (position + 1) % 5; }
vector< vector<char> > cim(string key){
    vector<char> letter_list,result_list;
    for(char letter='a';letter<='z';letter++) if(letter!='j') letter_list.push_back(letter);
    for(int i=0;i<key.length();i++)
        for(int j=0;j<25;j++)
            if(key[i]==letter_list[j]){
                result_list.push_back(key[i]),letter_list[j]='-';
                break;
            }
    for(int i=0;i<25;i++) if(letter_list[i]!='-') result_list.push_back(letter_list[i]);
    vector< vector<char> > matrix;
    vector<char> temp_vector;
    for(int i=0;i<result_list.size();i++){
        temp_vector.push_back(result_list[i]);
        if((i+1)%5==0) matrix.push_back(temp_vector),temp_vector.clear();
    }
    return matrix;
}
string cide(string input, bool mode, vector< vector<char> > matrix ){
    string output,init;
    char first=input[0],second=input[1];
    int fr=0,fc=0,sr=0,sc=0;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++){
            if(first==matrix[i][j]) fr=i,fc=j;
            if(second==matrix[i][j]) sr=i,sc=j;
        }
    if(fr==sr)
    {
        if(mode==true) output=init+matrix[fr][srd(fc)]+matrix[sr][srd(sc)];        
        else output=init+matrix[fr][slu(fc)]+matrix[sr][slu(sc)];
    }
    else if(fc==sc)
    {
        if(mode==true) output=init+matrix[srd(fr)][fc]+matrix[srd(sr)][sc];
        else output=init+matrix[slu(fr)][fc]+matrix[slu(sr)][sc];
    }
    else output=init+matrix[fr][sc]+matrix[sr][fc];
    return output;
}
void solve(){
    string input,output,key,mode_str,temp_str,process_pair;
    cout << "Input: ";getline(cin, input);
    cout << "Key: ";getline(cin, key);
    bool mode = true;
    cout << "Choose 'en' for encrypt and 'de' for decryption (encryption by default): ";
    cin >> mode_str;
    if(mode_str=="de") mode=false;
    else mode=true;
    for(int i=0;i<input.length();i++) if(input[i]!=' ') temp_str+=input[i];
    input=temp_str;
    temp_str="";
    for(int i=0;i<key.length();i++) if(key[i]!=' ') temp_str+=key[i];
    key=temp_str;
    if((input.length()%2)==1) input+="x";
    vector< vector<char> > matrix=cim(key);
    while(true){
        if(input.length()==1) process_pair=input+"x";
        else{
            process_pair=input.substr(0,2);
            if(process_pair[0]==process_pair[1]) input=process_pair.substr(1,1)+input,process_pair=process_pair.substr(0,1) + "x";
        }
        process_pair=cide(process_pair,mode,matrix),output+=process_pair;
        if(input.length()>2) input=input.substr(2);
        else break;
    }
    cout << output;
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