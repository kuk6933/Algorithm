import Foundation

func solution(_ n:Int, _ s:Int, _ a:Int, _ b:Int, _ fares:[[Int]]) -> Int {
    var visited = [Bool](repeating: false, count: n+1)
    var roads = [[Int]](repeating: [Int](repeating: 0, count: n+1), count: n+1)
    for fare in fares {
        roads[fare[0]][fare[1]] = fare[2]
        roads[fare[1]][fare[0]] = fare[2]
    }
    return 0
}

// S -> A
// S -> B 인데 같은 길은 한번씩 빼야함 
