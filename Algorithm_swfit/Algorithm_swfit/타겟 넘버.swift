import Foundation

var cnumbers = [Int]()
var ctarget = 0
var cnt = 0

func dfs(_ depth: Int, _ sum: Int) {
    if depth == cnumbers.count {
        if sum == ctarget {
            cnt += 1
        }
        return
    }
    dfs(depth + 1 ,sum + cnumbers[depth])
    dfs(depth + 1 ,sum - cnumbers[depth])
}

func solution (_ numbers: [Int], _ target:Int) -> Int {
    cnumbers = numbers
    ctarget = target
    dfs(0,0)
    
    return cnt
}
