//
//  n^2 배열 자르기!.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/10/06.
//

import Foundation

func solution(_ n:Int, _ left:Int64, _ right:Int64) -> [Int] {
    var ans = [Int]()
    ans = (Int(left)...Int(right)).map {
        max($0 / n + 1, $0 % n + 1)
    }
    
    return ans
}
