#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> stk;
    int board_size= board.size();

    for(int i=0; i<moves.size(); i++)
    {
        for(int j=0; j<board_size; j++)
        {
            if(board[j][moves[i]-1] != 0 )
            {
                if(stk.size()>0)
                {
                    if(stk.top() == board[j][moves[i]-1])
                    {
                        answer +=2;
                        board[j][moves[i]-1]=0;
                        stk.pop();
                        break;
                    }
                    else
                    {
                        stk.push(board[j][moves[i]-1]);
                        board[j][moves[i]-1]=0;
                        break;
                    }
                }
                else
                {
                    stk.push(board[j][moves[i]-1]);
                    board[j][moves[i]-1]=0;
                    break;
                }
            }
        }
    }
    return answer;
}


int main() {

}