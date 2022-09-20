//
//  main.swift
//  AlgorithmForSwift
//
//  Created by ohhyeongseok on 2022/09/19.
//

import Foundation

func solution(_ queue1:[Int], _ queue2:[Int]) -> Int {
    var q1 = queue1
    var q2 = queue2
    var q1Sum = 0
    var q2Sum = 0
    q1Sum = q1.reduce(0, +)
    q2Sum = q2.reduce(0, +)
    var idx1 = 0
    var idx2 = 0
    var ans = 0
    var maxidx = q1.count + q2.count
    while(idx1 < maxidx && idx2 < maxidx ) {
        if q1Sum == q2Sum {
            return ans
        }
        ans += 1
        if q1Sum > q2Sum {
            let tmp = q1.remove(at: 0)
            q2.insert(tmp, at: q2.count)
            q1Sum -= tmp
            q2Sum += tmp
            idx1 += 1
        } else {
            let tmp = q2.remove(at: 0)
            q1.insert(tmp, at: q1.count)
            q2Sum -= tmp
            q1Sum += tmp
            idx2 += 1
        }
    }
    return -1
}
