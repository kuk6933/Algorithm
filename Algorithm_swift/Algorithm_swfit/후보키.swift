import Foundation

func combination(_ array: [Int], _ n: Int) -> [[Int]] {
    var result = [[Int]]()
    if array.count < n { return result }
    
    func cycle(_ index: Int, _ now: [Int]) {
        if now.count == n {
            result.append(now)
            return
        }
        
        for i in index..<array.count {
            cycle(i + 1, now + [array[i]])
        }
    }
    cycle(0, [])
    
    return result
}

func solution(_ relation:[[String]]) -> Int {
    var ans = 0 //결과
    var resultSet = Set<Set<Int>>() //최소성을 위한 Set
    var remain = [Int]() // 조합 생성을 위한 배열
    for i in 0..<relation[0].count {
        remain.append(i)
    }
    var cnt = 1
    while !remain.isEmpty {
        if cnt > relation[0].count {
            break
        }
        let comb = combination(remain, cnt)
        cnt += 1
        for element in comb {//(1,3), (2,3) ...
            var arr = [[String]]()
            var isSubset = false
            var s = Set<Int>()
            for value in element {
                s.insert(value)
            }
            for v in resultSet {
                if v.isSubset(of: s) {
                    isSubset = true
                    break
                }
            }
            if isSubset {
                continue
            }
            var can = true
            for rel in relation {
                var tmp = [String]() // 임시 그릇
                for value in element { // 그릇에 담음[100 ryan]
                    tmp.append(rel[value])
                }
                if arr.contains(tmp) {
                    can = false
                    break
                } else {
                    arr.append(tmp)
                }
            }
            if can {
                ans += 1
                resultSet.insert(s)
            }
        }
    }
    return ans
}
