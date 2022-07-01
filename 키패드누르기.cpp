#include <string>
#include <vector>
#include <cmath>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left=9;
    int right=11;
    int tmp=10;
    int lmodular, rmodular, lshare, rshare, kmodular, kshare;
    int ldistance, rdistance;
    for(auto i: numbers)
    {
        switch(i)
        {
            case 0:
                lmodular= left%3;
                rmodular= right%3;
                lshare = left/3;
                rshare = right/3;
                kmodular= (11-1)%3;
                kshare = (11-1)/3;
                ldistance= abs(kshare-lshare)+ abs(kmodular-lmodular);
                rdistance= abs(kshare-rshare) + abs(kmodular- rmodular);
                if( ldistance< rdistance)
                {
                    left = 10;
                    answer+="L";
                }
                else if( ldistance > rdistance)
                {
                    right=10;
                    answer+="R";
                }
                else {
                    if (hand == "left") {
                        left = 10;
                        answer += "L";
                    } else {
                        right = 10;
                        answer += "R";
                    }
                }
                break;
            case 1:
                left=0;
                answer+="L";
                break;
            case 2:
                lmodular= left%3;
                rmodular= right%3;
                lshare = left/3;
                rshare = right/3;
                kmodular= (i-1)%3;
                kshare = (i-1)/3;
                ldistance= abs(kshare-lshare)+ abs(kmodular-lmodular);
                rdistance= abs(kshare-rshare) + abs(kmodular- rmodular);
                if( ldistance< rdistance)
                {
                    left = 1;
                    answer+="L";
                }
                else if( ldistance > rdistance)
                {
                    right=1;
                    answer+="R";
                }
                else
                {
                    if(hand=="left")
                    {
                        left=1;
                        answer+="L";
                    }
                    else{
                        right=1;
                        answer+="R";
                    }
                }
                break;
            case 3:
                right=2;
                answer+="R";
                break;
            case 4:
                left=3;
                answer+="L";
                break;
            case 5:
                lmodular= left%3;
                rmodular= right%3;
                lshare = left/3;
                rshare = right/3;
                kmodular= (i-1)%3;
                kshare = (i-1)/3;
                ldistance= abs(kshare-lshare)+ abs(kmodular-lmodular);
                rdistance= abs(kshare-rshare) + abs(kmodular- rmodular);
                if( ldistance< rdistance)
                {
                    left = 4;
                    answer+="L";
                }
                else if( ldistance > rdistance)
                {
                    right=4;
                    answer+="R";
                }
                else
                {
                    if(hand=="left")
                    {
                        left=4;
                        answer+="L";
                    }
                    else{
                        right=4;
                        answer+="R";
                    }
                }
                break;
            case 6:
                right=5;
                answer+="R";
                break;
            case 7:
                left=6;
                answer+="L";
                break;
            case 8:
                lmodular= left%3;
                rmodular= right%3;
                lshare = left/3;
                rshare = right/3;
                kmodular= (i-1)%3;
                kshare = (i-1)/3;
                ldistance= abs(kshare-lshare)+ abs(kmodular-lmodular);
                rdistance= abs(kshare-rshare) + abs(kmodular- rmodular);
                if( ldistance< rdistance)
                {
                    left = 7;
                    answer+="L";
                }
                else if( ldistance > rdistance)
                {
                    right=7;
                    answer+="R";
                }
                else
                {
                    if(hand=="left")
                    {
                        left=7;
                        answer+="L";
                    }
                    else{
                        right=7;
                        answer+="R";
                    }
                }
                break;
            case 9:
                right=8;
                answer+="R";
                break;
        }
    }
    return answer;
}