//
//  보석 쇼핑.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/11/04.
//

import Foundation

func solution(_ gems:[String]) -> [Int] {
    let kinds = Set(gems).count
    if kinds == 1 {
        return [1, 1]
    }
    var dic: [String: Int] = [:]
    var ans = [0, 0]
    var minDiff = Int.max
    var start = 0
    var end = 0
    
    while end < gems.count {
        if dic.count == kinds { // 모든 보석 다 있을때
            if end - start < minDiff {
                minDiff = end - start
                ans = [start + 1, end + 1]
            }
            dic[gems[start]]! -= 1
            if dic[gems[start]] == 0 {
                dic[gems[start]] = nil
            }
            start += 1
        } else { // 없을 때
            if let _ = dic[gems[end]] {
                dic[gems[end]]! += 1
                end += 1
            } else {
                dic[gems[end]] = 0
            }
        }
    }
    return ans
}
