import Foundation

func solution(_ jobs:[[Int]]) -> Int {
    var jobs = jobs
    jobs.sort(by: { $0[0] < $1[0] })
    var cnt = jobs.count
    var now = 0
    var accumulate = 0
    var pq = [[Int]]()
    while true {
        if jobs.count == 0 && pq.count == 0 {
            break
        }
        while true {
            if jobs.count > 0 {
                if jobs.first![0] <= now {
                pq.append(jobs.removeFirst())
                } else {
                    break
                }
            } else {
                break
            }
        }
        if pq.count == 0 &&  jobs.count != 0 {
            now = jobs.first![0]
            continue
        }
        pq.sort(by: { $0[1] < $1[1] })
        now += pq.first![1]
        accumulate += now - pq.first![0]
        pq.removeFirst()
    }
    return accumulate / cnt
}
