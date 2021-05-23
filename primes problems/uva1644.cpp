#include<bits/stdc++.h>

using namespace std;

#define PI 3.14159265
#define sqr(x) ((x)*(x))
#define pr pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define vull vector<unsigned long long>
#define all(v) ((v).begin()), ((v).end())
#define rev(v) ((v).rbegin()), ((v).rend())
#define rep(i, st, en) for(int i = st; i < en; i++)
#define Fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long int ulli;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }


bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) { return a.second < b.second; }

template<typename T>
void takeInput(vector<T>& v){ for(auto& it : v) cin >> it; }

ll binPow(ll b, ll p) {
    if (p == 0) return 1;
    ll sq = binPow(b, p / 2);
    sq *= sq;

    if (p & 1)
        sq *= b;

    return sq;
}

const int sz = 1e7+1;
bitset<10000010>bs;
vi p;
void seive(){
    ll sieve_size = sz + 1;
    bs.set();
    bs[0] = bs[1] = false;
    for (ll i = 2; i < sieve_size; i++) {
        if (bs[i]) {
            for (ll j = i * i; j < sieve_size; j += i) bs[j] = false;
            p.push_back(i);
        }
    }
}

int main() {
    Fast;
    seive();
    int n;
    while(cin >> n && n){
        auto it = upper_bound(all(p), n);
        if(*it == n){
            cout << 0 << "\n";
            continue;
        }

        auto it2 = it;
        it2--;
        if(it2 < p.begin()){
            cout << *it << "\n";
            continue;
        }
        if(*it > n && *it2 < n){
            cout << *it - (*it2) << "\n";
        }
        else cout << 0 << "\n";
    }
    return 0;
}
