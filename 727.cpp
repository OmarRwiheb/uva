#include<bits/stdc++.h>

using namespace std;

const int N = 1e9+7;

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

int priority(char op){
    if(op == '^')
        return 3;
    else if(op == '*' || op == '/')
        return 2;
    else if(op == '+' || op == '-')
        return 1;
    else 
        return 0;
}

string infex_to_postfix(string eq){
    stack<char>st;
    string result = "";
    for(int i = 0; i < eq.length(); i++){
        if(isdigit(eq[i]) || isalpha(eq[i])){
            result += eq[i];
        }
        else{
            if(eq[i] == '(')
                st.push(eq[i]);

            else if(eq[i] == ')'){
                while(st.top() != '('){
                    result += st.top();
                    st.pop();
                }
                st.pop();
            }

            else {
                while(!st.empty() && priority(st.top()) >= priority(eq[i])){
                    result += st.top();
                    st.pop();
                }
                st.push(eq[i]);
            }
        }
    }
    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w",stdout);
#endif
    int tc;
    char s[10];
    cin>>tc;
    cin.ignore(100,'\n');
    while(tc--){
        cin.ignore(100,'\n');
        string n;
        string equation;

        while (cin.peek() != '\n' && cin.peek() != -1){
            cin>>n;
            cin.ignore(100,'\n');
            equation += n;

        }
        
        cout << infex_to_postfix(equation) << endl;
        if (tc)
            cout << endl;

    }
    
    return 0;
}
                        
