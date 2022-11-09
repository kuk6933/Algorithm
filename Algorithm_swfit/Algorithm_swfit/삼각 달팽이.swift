import Foundation

func circle(_ startvalue: Int,_ loc: Int, _ cur: Int, _ n: Int,_ ans: inout [Int]) {
    var cur = cur // 현재 층
    var loc = loc
    var cnt = startvalue
    ans[loc] = startvalue
    for i in 0..<n-1 { // 내려올때
        cnt += 1
        loc = loc + cur + i
        ans[loc] = cnt
    }
    cur += n - 1
    for _ in 0..<n - 1 { // 횡이동
        cnt += 1
        loc = loc + 1
        ans[loc] = cnt
    }
    if n >= 2 {
        for _ in 0..<n - 2 {
            cnt += 1
            loc = loc - cur
            cur -= 1
            ans[loc] = cnt
        }
    }
    
    loc = loc + cur
    if loc < ans.count {
        if ans[loc] == 0 {
            circle(cnt+1, loc, cur+1, n - 3, &ans )
        }
    }
}

func solution(_ n:Int) -> [Int] {
    var num = 0
    for i in 1...n {
        num += i
    }
    var ans = [Int](repeating: 0, count: num)
    circle(1, 0, 1, n, &ans)
    return ans
}
