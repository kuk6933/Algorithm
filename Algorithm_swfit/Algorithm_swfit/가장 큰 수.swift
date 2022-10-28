//
//  가장 큰 수.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/10/28.
//

import Foundation

func solution(_ numbers: [Int]) -> String {
    var strs = numbers.map({String($0)})
    strs.sort {
        return $0 + $1 > $1 + $0
    }
    if strs.count > 1, strs[0] == "0" {
        return "0"
    }
    return strs.joined()
}
