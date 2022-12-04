//
//  징검다리 건너기.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/12/02.
//


import Foundation

func solution(_ stones:[Int], _ k:Int) -> Int {
    var stones = stones
    var left = 0
    var right = stones.max()!
    var mid = 0
    
    while left <= right {
        var isPossible = true
        var pass = 0
        mid = (left + right) / 2
        
        for stone in stones {
            if stone - mid >= 0 {
                pass = 0
            } else {
                pass += 1
            }
            
            if pass >= k {
                isPossible = false
                break
            }
        }
        if isPossible {
            left = mid + 1
        } else {
            right = mid - 1
        }
    }
    return right
}
