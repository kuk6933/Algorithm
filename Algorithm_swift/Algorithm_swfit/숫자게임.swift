//
//  숫자게임.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/12/01.
//

import Foundation

func solution(_ a:[Int], _ b:[Int]) -> Int {
    var ans = 0
    var a = a.sorted(by: <)
    var b = b.sorted(by: <)
    
    var aIndex = 0
    
    for element in b {
        if element > a[aIndex] {
            ans += 1
            aIndex += 1
        }
    }
    return ans
}
