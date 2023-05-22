#include <iostream>
#include <vector>

using namespace std;

int n,m,cnt;
int arr[3][4]; //2개 미션 3개 장소
void spy(int day, int preStage,int nowStage,int mission ,int num) {

    int nowNum = num;
    if(preStage == nowStage) {
        nowNum += arr[mission][nowStage] / 2;
    } else {
        nowNum += arr[mission][nowStage];
    }

    if(day == n) {
        if(nowNum >= m) {
            cnt++;
        }
        return;
    }

    for(int i=1; i<=2; i++) {
        for(int j=1; j<= 3; j++) {
            spy(day+1, nowStage, j,i, nowNum);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1; i<=2; i++) {
        for(int j=1; j<=3; j++) {
            cin>>arr[i][j];
        }
    }
    spy(0,0,0,0,0);
    cout<<cnt;
}