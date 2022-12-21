
import Foundation

var result = [[String]]()

func cmp(_ a: [String], _ b: [String]) -> Bool {
    for i in 0..<a.count {
        if a == b {
            continue
        } else {
            let aArr = a[i].map{$0}
            let bArr = b[i].map{$0}
            for j in 0...2 {
                if aArr[j] < bArr[j] {
                    return true
                } else if aArr[j] > bArr[j] {
                    return false
                }
            }
        }
    }
    return true
}
func dfs(_ remainTickets: [String: [String]], _ course: [String], _ cur: String) {
    if remainTickets.count == 0 {
        result.append(course)
        return
    }
    if remainTickets[cur] != nil {
        for destination in remainTickets[cur]! {
            var newCourse = course
            newCourse.append(destination)
            var tmpRemainTickets = remainTickets
            tmpRemainTickets[cur]?.remove(at: (remainTickets[cur]?.firstIndex(of: destination)!)!)
            if tmpRemainTickets[cur]?.count == 0 {
                tmpRemainTickets[cur] = nil
            }
            dfs(tmpRemainTickets, newCourse, destination)
        }
    }
}
func solution(_ tickets:[[String]]) -> [String] {
    var dic = [String: [String]]()
    for ticket in tickets { // 넣어줬어
        if dic[ticket[0]] == nil {
            dic[ticket[0]] = []
        }
        dic[ticket[0]]?.append(ticket[1])
    }
    dfs(dic, ["ICN"], "ICN")
    let ans = result.sorted(by: cmp)
    
    return ans[0]
}
print(solution([["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL","SFO"]]))
