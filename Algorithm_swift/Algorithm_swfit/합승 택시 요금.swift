import Foundation

func solution(_ n:Int, _ s:Int, _ a:Int, _ b:Int, _ fares:[[Int]]) -> Int {
    var graph = [[Int]](repeating: [Int](repeating: 200 * 100000 + 1, count: n + 1), count: n + 1)
    var ans = Int.max

    for fare in fares {
        let from = fare[0]
        let to = fare[1]
        let cost = fare[2]
        
        graph[from][to] = cost
        graph[to][from] = cost
    }
    for node in 1...n {
        graph[node][node] = 0
    }

    for k in 1...n {
        for i in 1...n {
            for j in 1...n {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])
            }
        }
    }

    for mid in 1...n {
        ans = min(ans, graph[s][mid] + graph[mid][a] + graph[mid][b])
    }

    return ans
}
