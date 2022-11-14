
import Foundation

func solution(_ board:[[Int]]) -> Int
{
    var board = board
    var mx = 0
    if board.count == 1 {
        if board[0].contains(1) {
            return 1
        } else {
            return 0
        }
    }
    for i in 1..<board.count {
        for j in 1..<board[i].count {
            if board[i][j] != 0{
            var mn = min(board[i-1][j-1], board[i-1][j])
            mn = min(mn, board[i][j-1])
            board[i][j] += mn
            if board[i][j] > mx {
                mx = board[i][j]
            }
            }
        }
    }
    return mx*mx
}
