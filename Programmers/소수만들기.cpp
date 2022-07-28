#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;

int number =3002;
vector<bool> prime(3002);
void findPrimeNumber()
{
    for(int i=2; i<3002; i++)
    {
        prime[i] =true;
    }

    for(int i=2; i<=sqrt(number); i++)
    {
        if(prime[i]==false)
            continue;
        for(int j= i+i; j <=number; j+=i)
            prime[j] = false;
    }

}

int solution(vector<int> nums) {

    int n=nums.size();
    findPrimeNumber();
    int answer = 0;
    for(int i=0; i<n-2; i++ )
    {
        for(int j=i+1; j<n-1; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                if(prime[nums[i]+ nums[j]+nums[k]] == true )
                {
                    answer++;
                }
            }

        }
    }
    return answer;
}

