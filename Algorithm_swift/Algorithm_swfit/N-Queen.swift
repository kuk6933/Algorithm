//
//  N-Queen.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/11/24.
//

import Foundation


var col = [Bool](repeating:false, count: 13)
var right_diagonal = [Bool](repeating:false, count: 25) // 우하향
var left_diagonal = [Bool](repeating:false, count: 25) // 우상향

var ans = 0

func check (_ k: Int, _ n: Int) {
    if k == n {
        ans += 1
        return
    }
    for i in 0..<n {
        if !col[i] && !right_diagonal[k-i+n-1] && !left_diagonal[i+k] {
            col[i] = true
            right_diagonal[k-i+n-1] = true
            left_diagonal[i+k] = true
            check(k+1, n)
            col[i] = false
            right_diagonal[k-i+n-1] = false
            left_diagonal[i+k] = false
            
        }
    }
}

func solution(_ n:Int) -> Int {
    check(0, n)
    return ans
}
