#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int>first;
    vector<int>second;
    vector<int>third;
    int first_assist=1;
    int second_assist=1;
    int third_assist = 3;
    int assist=1;
    for(int i=0; i<10001; i++)
    {
        if(first_assist==6)
        {
            first_assist=1;
        }
        first.push_back(first_assist++); ////first

        if(second_assist==2)
        {
            second_assist++;
        }
        else if(second_assist==6)
        {
            second_assist=1;
        }
        if(i%2==0)
        {
            second.push_back(2);
        }
        else
        {
            second.push_back(second_assist++);
        }

        if(assist==3)
        {
            assist = 1;
            switch(third_assist)
            {
                case 1: third_assist=2;
                break;
                case 2: third_assist=4;
                break;
                case 3: third_assist=1;
                break;
                case 4: third_assist=5;
                break;
                default: third_assist=3;
            }
        }
        third.push_back(third_assist);
        assist++;
    }
    int fScore=0;
    int sScore =0;
    int tScore =0;

    for(int i=0; i<answers.size(); i++)
    {
        if(answers[i]==first[i])
        {
            fScore++;
        }
        if(answers[i]==second[i])
        {
            sScore++;
        }
        if(answers[i]==third[i])
        {
            tScore++;
        }
    }

    int mx = max(fScore, sScore);
    mx= max(mx, tScore);

    if(fScore!= sScore&& fScore != tScore && sScore != tScore) //다 다를때
    {
        if(fScore==mx)
        {
            answer.push_back(1);
        }
        else if(sScore==mx)
        {
            answer.push_back(2);
        }
        else
        {
            answer.push_back(3);
        }
    }
    else
    {
        if(fScore==mx)
        {
            answer.push_back(1);
        }
        if(sScore==mx)
        {
            answer.push_back(2);
        }
        if(tScore==mx)
        {
            answer.push_back(3);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}