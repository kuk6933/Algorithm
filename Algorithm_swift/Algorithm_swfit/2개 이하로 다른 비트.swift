//
//  2개 이하로 다른 비트.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/10/27.
//

import Foundation

func solution(_ numbers:[Int64]) -> [Int64] {
    var ans = [Int64]()
    for number in numbers {
        var result: Int64 = 0
        if number % 2 == 0 {
            result = number + 1
        } else {
            var bi = Array(String(number,radix: 2)).map { String($0) }
            let count = bi.reversed().firstIndex(of: "0") ?? bi.count
            result = number + Int64(pow(2.0, Double(count) - 1))
        }
        ans.append(result)
    }
    return ans
}
