//
//  프린터.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/10/11.
//

import Foundation

func solution(_ priorities:[Int], _ location:Int) -> Int {
    var pq = [Int]()
    var cnt = 0
    var stk = [(Int,Int)]()
    for i in 0...priorities.count - 1 {
        pq.append(priorities[i])
        stk.append((priorities[i], i))
    }
    pq.sort(by: { $0 > $1 })
    while true {
        if stk.first!.0 < pq.first! {
            var tmp = stk.removeFirst()
            stk.append(tmp)
        } else {
            cnt += 1
            if location == stk.first!.1 {
                return cnt
            }
            pq.removeFirst()
            stk.removeFirst()
        }
    }
}

