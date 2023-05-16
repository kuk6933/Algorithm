#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double count =0;
    double sum = 0;
    for(int i=0; i<20; i++) {
        string subject;
        double credit;
        string grade;
        cin>>subject>>credit>>grade;
        if(grade != "P") {
            count += credit;
        }
        if(grade == "A+") {
            sum += credit * 4.5;
        } else if( grade == "A0") {
            sum += credit * 4.0;
        }else if( grade == "B+") {
            sum += credit * 3.5;
        }else if( grade == "B0") {
            sum += credit * 3.0;
        }else if( grade == "C+") {
            sum += credit * 2.5;
        }else if( grade == "C0") {
            sum += credit * 2.0;
        }else if( grade == "D+") {
            sum += credit * 1.5;
        }else if( grade == "D0") {
            sum += credit * 1.0;
        }else if( grade == "F") {
            sum += credit * 0.0;
        }
    }
    cout<<sum/ count;
}