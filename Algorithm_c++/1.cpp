#include <iostream>
#include <string>

using namespace std;

int main() {
    int times;
    cin>>times;
    for (int t=1; t<=times; t++) {
        int n;
        cin >> n;
        int cnt = 0;
        bool arr[10] = {false};
        while (true) {
            cnt++;
            int cur = n * cnt;
            string str = to_string(cur);
            for(int i=0; i<str.size(); i++) {
                arr[str[i]-'0'] = true;
            }
            bool flag = true;
            for(int i=0; i<10; i++) {
                if (!arr[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout<<"#"<<t<<" "<<str <<"\n";
                break;
            }
        }
    }
}
