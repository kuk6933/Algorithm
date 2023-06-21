#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string &a, string &b) {
    if(a + b > b + a) {
        return true;
    } else {
        return false;
    }
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> string_numbers;
    for(auto number: numbers) {
        string_numbers.push_back(to_string(number));
    }
    sort(string_numbers.begin(), string_numbers.end(), cmp);

    bool isZero = true;
    for(auto str: string_numbers) {
        if(isZero && str=="0") {
            continue;
        }
        isZero = false;
        answer+=str;
    }


    if(answer == "") {
        answer = "0";
    }
    return answer;
}