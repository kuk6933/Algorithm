#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n;
	cin >> n;
	int arr[1002];
	int dp[1002] = {};
	for (int i = 1; i <= n; i++)
	{

		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++)
	{
		dp[i] = arr[i];
		for (int j = 1; j <= i; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[i], dp[j] + arr[i]);
			}
		}
	}
	int mx = 0;

	for (int i = 1; i <= n; i++)
	{
		if (dp[i] > mx)
			mx = dp[i];
	}
	cout << mx;


}