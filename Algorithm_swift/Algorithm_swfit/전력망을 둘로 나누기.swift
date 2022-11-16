import Foundation

var n1 = 0
var n2 = 0

func dfs(_ map: [[Int]], _ start: Int, _ trigger: Int, _ visited: [Int]) {
    var visited = visited
    for i in 0..<map[start].count {
        if map[start][i] == 1 && visited[i] == 0 {
            if trigger == 1 {
                n1 += 1
            } else {
                n2 += 1
            }
            visited[i] = 1
            dfs(map,i,trigger, visited)
        }
    }
}
func solution(_ n:Int, _ wires:[[Int]]) -> Int {
    var mn = Int.max
    var map = [[Int]](repeating: [Int](repeating: 0, count: n+1), count: n+1)
    for i in wires {
        map[i[0]][i[1]] = 1
        map[i[1]][i[0]] = 1
    }
    
    for i in wires {
        var visited = [Int](repeating: 0, count: n+1)
        n1 = 0
        n2 = 0
        map[i[0]][i[1]] = 0
        map[i[1]][i[0]] = 0
        visited[i[0]] = 1
        dfs(map, i[0], 1, visited)
        for i in 0...n {
            visited[i] = 0
        }
        visited[i[1]] = 1
        dfs(map, i[1], 0, visited)
        map[i[0]][i[1]] = 1
        map[i[1]][i[0]] = 1
        if abs(n1 - n2) < mn {
            mn = abs(n1 - n2)
        }
    }
    return mn
}

print(solution(9 ,[[1,3],[2,3],[3,4],[4,5],[4,6],[4,7],[7,8],[7,9]]))
