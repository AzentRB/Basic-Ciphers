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
 
class Substitution{
    private:
        map<char, char> m1;
        string str;
        vector<char> ct,pt;
    public:
        Substitution(){
            m1.insert(pair<char,char>('a','Z')),m1.insert(pair<char,char>('b','Y')),m1.insert(pair<char,char>('c','X'));
            m1.insert(pair<char,char>('d','W')),m1.insert(pair<char,char>('e','V')),m1.insert(pair<char,char>('f','U'));
            m1.insert(pair<char,char>('g','T')),m1.insert(pair<char,char>('h','S')),m1.insert(pair<char,char>('i','R'));
            m1.insert(pair<char,char>('j','Q')),m1.insert(pair<char,char>('k','P')),m1.insert(pair<char,char>('l','O'));
            m1.insert(pair<char,char>('s','H')),m1.insert(pair<char,char>('t','G')),m1.insert(pair<char,char>('u','F'));
            m1.insert(pair<char,char>('v','E')),m1.insert(pair<char,char>('w','D')),m1.insert(pair<char,char>('x','C'));
            m1.insert(pair<char,char>('y','B')),m1.insert(pair<char,char>('z','A')),m1.insert(pair<char,char>(' ','*'));
        }
        void getData(){
            cout<<"Enter Plain Text:  ";
            getline(cin, str);
        }
        void encrypt(){
            for(int i=0;i<str.length();i++) {
                map<char, char>::iterator itr;
                for(itr=m1.begin();itr!=m1.end();itr++) if(str.at(i) == itr->first) ct.push_back(itr->second);
            }
        }
        void decrypt(){
            for(char x: ct){
                map<char, char>::iterator itr;
                for(itr=m1.begin();itr!=m1.end();itr++) if(x==itr->second) pt.push_back(itr->first);
            }
        }
        void showCT(){
            cout << "Cipher Text:  ";
            for(char x: ct) cout<<x;
        }
        void showPT() {
            cout << endl << "Decrypted Cipher Text: ";
            for(char x: pt) cout<<x;
        }
};
void solve(){
    Substitution s;
    s.getData();
    cout << endl;
    cout << endl;
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
