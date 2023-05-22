#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin>>str;
    bool m,o,b,i,s;
    m = o = b = i = s = false;
    for(int t = 0; t< str.size(); t++) {
        if(str[t] == 'M') {
            m = true;
        }
        else if(str[t] == 'O') {
            o= true;
        }
        else if(str[t] == 'B') {
            b= true;
        }
        else if(str[t] == 'I') {
            i= true;
        }
        else if(str[t] == 'S') {
            s= true;
        }
    }
    if(m && o && b && i && s) {
        cout<<"YES";
    } else {
        cout<<"NO";
    }
}

용모가 주문한 피자는 가로 길이가W, 세로 길이가 H인 직사각형 모양이며, 가로 방향이나 세로 방향으로 각 방향에 대해 피자를 가르는 직선 커팅이 피자의 아래쪽 끝이나 왼쪽 끝을 기준으로 1 이상의 자연수만큼의 거리에 하나 이상 존재한다.
CTP 운영진에서는 주문한 피자의 조각 하나의 크기가 K보다 크면 혼자 먹기가 힘들어 부원에게 나누어 줄 수 없기 때문에, 피자 조각들 중에서 부원들에게 나누어 줄 수 있는 피자 조각의 개수를 구해 나누어 주려 한다. 피자의 정보가 주어질 때, CTP 운영진이 부원들에게 나누어 줄 수 있는 피자의 개수를 구해보자.

입력으로 첫 번째 줄에 피자의 가로길이 W와 세로길이 H, 부원들이 먹을 수 있는 피자 조각의 최대 크가 K가 주어져
두번쨰 줄에 가로 방향 커팅의 개수 N개가 주어지고 세번째 줄에 가로 방향 커팅의 세로위치 값이 공백으로 구분되어 주어져
세번째 줄에 세로 방향 커팅의 개수 M이 주어지고 다섯번째 줄에 세로 방향 커팅의 가로 위치 값이 공백으로 구분되어 주어져
N과 M의 최대값이 10만일때 어떻게 풀 수 있을까?