#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]>57)
        {
            if(s[i]=='z')//zero
            {
                s.erase(i,4);
                s.insert(i,"0");
            }
            else if(s[i]=='o') //one
            {
                s.erase(i,3);
                s.insert(i,"1");

            }
            else if(s[i]=='t')
            {
                if(s[i+1]=='w') //two
                {
                    s.erase(i,3);
                    s.insert(i,"2");
                }
                else if(s[i+1]=='h') //three
                {
                    s.erase(i,5);
                    s.insert(i,"3");
                }

            }
            else if(s[i]=='f')
            {
                if(s[i+1]=='o') //four
                {
                    s.erase(i,4);
                    s.insert(i,"4");
                }
                else if(s[i+1]=='i') //five
                {
                    s.erase(i,4);
                    s.insert(i,"5");
                }
            }
            else if(s[i]=='s')
            {
                if(s[i+1]=='i') //six
                {
                    s.erase(i,3);
                    s.insert(i,"6");
                }
                else if(s[i+1]=='e') //seven
                {
                    s.erase(i,5);
                    s.insert(i,"7");
                }
            }
            else if(s[i]=='e') //eight
            {
                s.erase(i,5);
                s.insert(i,"8");
            }
            else if(s[i]=='n') //nine
            {
                s.erase(i,4);
                s.insert(i,"9");
            }
        }
    }
    answer = stoi(s);
    return answer;
}

int main()
{
    string str = "onetwothreefourfivesixseveneightnine";
    int ans = solution(str);
    cout<<ans;
}