import Foundation

var numbers = [Int]()
var target = 0
var cnt = 0

func dfs(_ depth: Int, _ sum: Int) {
    if depth == numbers.count {
        if sum == target {
            cnt += 1
        }
        return
    }
    dfs(depth + 1 ,sum + numbers[depth])
    dfs(depth + 1 ,sum - numbers[depth])
}

func solution (_ numbers: [Int], _ target:Int) -> Int {
    numbers = numbers
      target = target
    dfs(0,0)
    
    return cnt
}
