#include <iostream> 
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#define X first
#define Y second
#define ll long long
using namespace std;

int n, m,num;
int dp[1000000];
int main() {

	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n;
	cin >> n;

	dp[1] = 0;

	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
		{
			dp[i] = min(dp[i], dp[i / 2]+1);
		}

		if(i % 3 == 0)
		{

			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
	}

	cout << dp[n];
	
	


}
