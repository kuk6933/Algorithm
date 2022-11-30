//
//  이중 우선 순위 큐.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/11/30.
//

import Foundation

func solution(_ operations:[String]) -> [Int] {
    var q = [Int]()
    for oper in operations {
        let oper = oper.components(separatedBy: " ")
        if String(oper[0]) == "I" {
            q.append(Int(oper[1])!)
        } else {
            if !q.isEmpty {
                if String(oper[1]) == "-1"  {
                q.removeLast()
            } else {
                q.removeFirst()
                }
            }
        }
        q.sort(by: >)
    }
    var result = [Int]()
    if q.isEmpty {
        result = [0,0]
    } else {
        result = [q[0], q[q.count-1]]
    }
    return result
}
