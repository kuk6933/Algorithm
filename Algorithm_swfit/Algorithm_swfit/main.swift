import Foundation

var ans = 0
var sz = 0

func solution(_ k:Int, _ dungeons:[[Int]]) -> Int {
    sz = dungeons.count
    let visited = [Bool](repeating: false, count: sz)
    DFS(visited,dungeons, 0, k)
    return ans
}

func DFS(_ visited: [Bool], _ dungeons: [[Int]], _ cnt: Int, _ k: Int) {
    if cnt > ans {
        ans = cnt
    }
    for i in 0..<sz {
        if !visited[i] , dungeons[i][0] <= k {
            var newVisited = visited
            newVisited[i] = true
            DFS(newVisited,dungeons, cnt+1, k-dungeons[i][1])
        }
    }
}
