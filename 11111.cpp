#include<bits/stdc++.h>

using namespace std;

const int N = 1e7+7;

#define vi vector<int>
#define vll vector<long long>
#define all(v) ((v).begin()), ((v).end())

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long int ulli;

/*ll sieve_size;
bitset<10000010>bs;
vll p;

void sieve(ll upperbound){
    sieve_size=upperbound+1;
    bs.set();
    bs[0]=bs[1]=false;
    for(ll i = 2;i<sieve_size;i++) if(bs[i]){
            for(ll j = i*i;j<sieve_size;j+=i) bs[j]=false;
            p.push_back(i);
        }
}*/

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

bool isPrime(ll n) {
    if (!(n % 2))return false;
    for (int i = 3; i * i <= n; i += 2)
        if (!(n % i))return false;
    return true;
}

vector<int>v;
int freq[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w",stdout);
#endif
    string line;
    while(getline(cin,line)){

        memset(freq,0,sizeof freq);
        v.clear();

        istringstream output(line);
        int a;
        stack<int>s;
        bool flag = 1;
        while(output>>a){
            v.push_back(a);
        }
        if(v.size()%2){cout<<":-( Try again."<<endl;continue;}
        for(int i=0;i<v.size();i++){
            if(v[i]<0)
                v[i]*=-1,s.push(v[i]);
            else{
                if(v[i]==s.top()) {
                    freq[s.top()]=0,s.pop();
                    if(!s.empty())
                    freq[s.top()] += v[i];
                }
                else flag = 0;
            }
            if(!s.empty()&&freq[s.top()]>=s.top())
                flag = 0;
        }
        if(!s.empty() || !flag) cout<<":-( Try again."<<endl;
        else cout<<":-) Matrioshka!"<<endl;
    }
    return 0;
}
