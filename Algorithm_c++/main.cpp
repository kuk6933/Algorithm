#include <string>
#include <vector>

using namespace std;
vector<vector<int>> arr(102, vector<int>(102));
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    for(int i=0; i<arr1.size(); i++)
    {
        for(int j=0; j<arr1[i].size(); j++) {

            for(int k=0; k<arr1[i].size(); k++) {
                arr[i][j] += arr1[i][k]*arr[k][j];
            }
        }
    }
    return arr;
}
int main() {
    vector<vector<int>> arr1  = {{1, 4}, {3, 2}, {4, 1}};
    vector<vector<int>> arr2 = {{3, 3}, {3, 3}};
    vector<vector<int>> arr3 = solution(arr1,arr2);
}