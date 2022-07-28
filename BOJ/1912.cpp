#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int arr[100002];
	int dp[100002] = {};

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] >= 0)
		{
			if (dp[i - 1] > 0)
			{
				dp[i] = dp[i - 1] + arr[i];
			}
			else
			{
				dp[i] = arr[i];
			}
		}
		else if(arr[i]<0)
		{
			if (dp[i - 1] > 0)
			{
				if (dp[i - 1] + arr[i] >= 0)
				{
					dp[i] = dp[i - 1] + arr[i];
				}
				else
				{
					dp[i] = arr[i];
				}
			}
			else
			{
				dp[i] = arr[i];
			}
		}
	}
	long long mx = -1001;
	for (int i = 1; i <= n; i++)
	{
		if (dp[i] > mx)
		{
			mx = dp[i];
		}
	}
	cout << mx;

}