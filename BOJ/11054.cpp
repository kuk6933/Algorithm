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
	int dp1[1002] = {};
	int dp2[1002] = {};

	for (int i = 1; i <= n; i++)
	{

		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++)
	{
		dp1[i] = 1;
		for (int j = 1; j <= i; j++)
		{
			if (arr[i] > arr[j])
			{
				dp1[i] = max(dp1[i], dp1[j] + 1);
			}
		}
	}
	for(int i=n; i>=1; i--)
	{
		dp2[i] = 1;
		for (int j = n; j >= i; j--)
		{
			if (arr[j] < arr[i])
			{
				dp2[i] = max(dp2[i], dp2[j] + 1);
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if ((dp1[i] + dp2[i]) > sum)
		{
			sum = (dp1[i] + dp2[i]);
		}
	}
	cout << sum-1;

}