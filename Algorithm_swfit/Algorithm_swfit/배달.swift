
import Foundation

func solution(_ N:Int, _ road:[[Int]], _ k:Int) -> Int {
    var ans = 0
    var map = [[Int]](repeating: [Int](repeating: -1, count: N+1), count: N+1)
    var go = [Int](repeating: 0, count: N+1)
    for i in road {
        
        if map[i[0]][i[1]] == -1 {
            map[i[0]][i[1]] = i[2]
            map[i[1]][i[0]] = i[2]
        } else {
            if  i[2] < map[i[0]][i[1]]  {
                map[i[0]][i[1]] = i[2]
                map[i[1]][i[0]] = i[2]
            }
        }
    }
    
    var queue = [(Int,Int)]()
    queue.append((1,0))
    go[1] = 0
    while !queue.isEmpty {
        let cur = queue.removeFirst()
        
        for i in 1...N {
            if i != cur.0 {
                if map[cur.0][i] != -1 {
                    if go[i] == 0 {
                        if i == 1 {
                            continue
                        }
                        go[i] = cur.1 + map[cur.0][i]
                        queue.append((i, cur.1 + map[cur.0][i]))
                    } else {
                        if go[i] > cur.1 + map[cur.0][i] {
                            go[i] = cur.1 + map[cur.0][i]
                            queue.append((i, cur.1 + map[cur.0][i]))
                        }
                    }
                }
            }
        }
    }
    for i in go {
        if i <= k && i != 0 {
            ans += 1
        }
    }

    return ans + 1
}
