import Foundation

func solution(_ numbers:[Int], _ target:Int) -> Int {
    var q = [Int]()
    q.append(numbers[0])
    q.append(-numbers[0])
    for i in 1...numbers.count - 1 {
        for _ in 0...q.count-1 {
            let tmp = q.removeFirst()
            q.append(tmp + numbers[i])
            q.append(tmp - numbers[i])
        }
    }
    
    var cnt = 0
    for i in q {
        if i == target {
            cnt += 1
        }
    }
    
    return cnt
}

var a = [1, 1, 1, 1, 1]
var b = 3
var sol = solution(a, b)
