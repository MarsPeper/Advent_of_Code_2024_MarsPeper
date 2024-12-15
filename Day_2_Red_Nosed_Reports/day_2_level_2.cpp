#include <bits/stdc++.h>
using namespace std;

/* clang-format off */

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

/* FUNCTIONS */
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back

/* PRINTS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }

/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;


bool isSafe(vi sign_diff) {
    // increasing when sign_diff[i] < 0
    // decreasing when sign_diff[i] > 0
    bool increasing, decreasing = false;
    for (int i = 0; i < sign_diff.size(); i++) {
        if (sign_diff[i] < 0) {
            increasing = true;
        }
        if (sign_diff[i] > 0) {
            decreasing = true;
        }
        if ((abs(sign_diff[i]) > 3) || (sign_diff[i] == 0)) {
            return false;
        }
        if (increasing && decreasing) { 
            return false;
        }
    }
    if (increasing || decreasing) {
        return true;
    }
    return false;
}

/* clang-format on */

bool solve(vi l1) {
    // sign diff is an array of difference between
    // n and n+1
    // if all same sign and different by at least 1 and at most 3
    // ==> safe
    // Idea: recurr this for all sub array
    for (int k = 0; k < l1.size(); k++) {
        vi sign_diff;
        vi sub_l1;
        for (int i = 0 ; i < l1.size(); i++) {
            if (i != k) {
                sub_l1.push_back(l1[i]);
            }    
        }
        //construct sign_diff
        for (int i = 0; i < sub_l1.size() - 1; i++) {
            sign_diff.push_back(sub_l1[i] - sub_l1[i+1]);
        }
        if (isSafe(sign_diff)) {
            return true;
        }

    }
    return false;
}

/* Main()  function */
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	// Some error handling for input file just for caution
	ifstream inputFile("input.txt");
	if (!inputFile) {
		cerr << "Error opening file!" << endl;
		return 1;
	}

	int num;

	string str;
	int sol = 0;
	while(getline(inputFile, str)) {
		vi l1; 
		istringstream ss(str);
		//Grab second number
		while(ss >> num) {
			l1.push_back(num);
		}
		if (solve(l1)) {
			sol++;
		}
	}

	
	cout << sol << endl;
	inputFile.close();
	return 0;
}