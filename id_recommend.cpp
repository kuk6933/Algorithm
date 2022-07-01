#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";

    for (int i = 0; i < new_id.size(); i++) //1단계
    {
        if (new_id[i] >= 65 && new_id[i] <= 90) {
            new_id[i] += 32;
        }
    }

    for (int i = 0; i < new_id.size(); i++) //2단계
    {
        if (!(new_id[i] >= 97 && new_id[i] <= 122)) //alphabet아니고
        {
            if (!(new_id[i] >= 48 && new_id[i] <= 57)) // 숫자도 아니고

                if (new_id[i] != '-' && new_id[i] != '_' && new_id[i] != '.') {
                    new_id.erase(i, 1);
                    i--;
                }
        }
    }
    int cnt = 0;
    for (int i = 0; i < new_id.size(); i++) //3단계
    {
        if (new_id[i] == '.') {
            cnt++;
            if (cnt >= 2) {
                new_id.erase(i, 1);
                cnt--;
                i--;
            }
        }
        else
        {
           cnt=0;
        }
    }
    if (new_id[0] == '.')  //4단계
    {
        new_id.erase(0, 1);
    }
    if (new_id[new_id.size() - 1] == '.') //4단계
    {
        new_id.erase(new_id.size() - 1, 1);
    }
    if (new_id.size() == 0) //5단계
    {
        new_id = "a";
    }



    if (new_id.size() >= 16)//6단계
    {
        new_id.erase(15,new_id.size()-15);
        if (new_id[0] == '.')
        {
            new_id.erase(0, 1);
        }
        if (new_id[new_id.size() - 1] == '.')
        {
            new_id.erase(new_id.size() - 1, 1);
        }
    }

    while(new_id.size()<=2)
    {
        new_id += new_id[new_id.size()-1];
    }
    answer = new_id;

    return answer;
}

int main()
{
   string str="...!@BaT#*..y.abcdefghijklm";
   string a = solution(str);
   cout<<a;
}