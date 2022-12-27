
import Foundation

var dy = [-1, 0, 1, 0]
var dx = [0, 1, 0, -1]
var dDir = [false, true, false, true] // false 상하, true 좌 우

func solution(_ board:[[Int]]) -> Int {
    var N = board.count
    var costs = [[Int]](repeating: [Int](repeating: Int.max, count: N), count: N)
    
    func dfs(_ y: Int, _ x: Int, _ cost: Int, _ dir: Bool) {
        if board[y][x] == 1 || cost > costs[y][x] {
            return
        }
        costs[y][x] = cost
        
        for i in 0..<4 {
            let ny = y + dy[i]
            let nx = x + dx[i]
            let ndir = dDir[i]
            
            if nx < N && ny < N && nx > -1 && ny > -1 {
                if board[ny][nx] == 0 {
                    var newCost = ndir == dir ? 100: 600
                    dfs(ny, nx, cost + newCost, ndir)
                }
            }
        }
    }
    dfs(0, 1, 100,true)
    dfs(1, 0, 100,false)
    return costs[N-1][N-1]
}
