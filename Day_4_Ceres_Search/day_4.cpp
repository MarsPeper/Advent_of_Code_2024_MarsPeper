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


/* clang-format on */

string stringToFind = "XMAS";

int check_xmas(int m, int n, vector<string> inputString) {
	//check left
	//check right
	//check up
	//check down
	//check diagnal left up
	//check diagnal right up
	//check diagnal left down
	//check diagnal left up

	// x y are the direction in which the word needs to be searched
	// example: x[4] = 0 y[4] = 1 --> go up in the y direction by 1 
	// to find the word
	vector<int> x = {-1, -1, -1, 0, 0, 1, 1, 1};
	vector<int> y = {-1, 0, 1, -1, 1, -1, 0 , 1};
	int count = 0;
	for (int dir = 0; dir < 8; dir++) {
		// declare k here so that k can be compared after loop
		int k = 1;
		
		int currX = m + x[dir];
		int currY = n + y[dir];	
		for (k = 1; k < stringToFind.length(); k++) {
			if (currX >= inputString.size() || currX < 0 || currY >= inputString[0].length() || currY < 0)
				break;
			if (inputString[currX][currY] != stringToFind[k]) 
				break;
		
			// move into a direction
			currX += x[dir], currY += y[dir];
		}
		if (k == stringToFind.length()) {
			count++;
		}
	}
	return count;
}


int solve(vector<string> inputString) {
	int sol = 0;
	for (int i = 0; i < inputString.size(); i++) {
		for (int j = 0; j < inputString[i].length(); j++) {
			if (inputString[i][j] == stringToFind[0]) {
				sol += check_xmas(i, j, inputString);
			} 
		}
	}
	return sol;
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

	string inputString;
	vector<string> inputMatrix;
	while(getline(inputFile, inputString)) {
		inputMatrix.push_back(inputString);
	}
	cout << solve(inputMatrix) << endl;

	inputFile.close();
	return 0;
}
