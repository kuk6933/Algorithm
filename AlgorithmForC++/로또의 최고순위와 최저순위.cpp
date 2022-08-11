#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zero_cnt=0;
    for(int i=0; i< lottos.size(); i++)
    {
        if(lottos[i]==0)
        {
            zero_cnt++;
        }
    }
    int match=0;

    for(int i=0; i<lottos.size(); i++)
    {
        for(int j=0; j<win_nums.size(); j++)
        {
            if(lottos[i]==win_nums[j])
            {
                match++;
                break;
            }
        }
    }
    int high= match+zero_cnt;
    int low= match;
    switch(high)
    {
        case 6: answer.push_back(1); break;
        case 5: answer.push_back(2); break;
        case 4: answer.push_back(3); break;
        case 3: answer.push_back(4); break;
        case 2: answer.push_back(5); break;
        default: answer.push_back(6); break;
    }

    switch(low)
    {
        case 6: answer.push_back(1); break;
        case 5: answer.push_back(2); break;
        case 4: answer.push_back(3); break;
        case 3: answer.push_back(4); break;
        case 2: answer.push_back(5); break;
        default: answer.push_back(6); break;
    }

    return answer;
}
