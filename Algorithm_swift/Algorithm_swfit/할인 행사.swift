//
//  할인 행사.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/11/07.
//
import Foundation

func solution(_ want:[String], _ number:[Int], _ discount:[String]) -> Int {
    var dic: [String: Int] = [:]
    var ans = 0
    for i in 0 ..< want.count {
        dic[want[i]] = number[i]
    }
    for i in 0...9 {
        if let _ = dic[discount[i]] {
            dic[discount[i]]! -= 1
        }
    }
    var flag = true
    for i in 0 ..< want.count {
        if dic[want[i]]! >= 1 {
            flag = false
            break
        }
    }
    if flag {
        ans += 1
    }
    
    for i in 10..<discount.count {
        if want.contains(discount[i]) {
            dic[discount[i]]! -= 1
        }
        if want.contains(discount[i - 10]) {
            dic[discount[i - 10]]! += 1
        }
        flag = true
        for i in 0 ..< want.count {
            if dic[want[i]]! >= 1 {
                flag = false
                break
            }
        }
        if flag {
            ans += 1
        }
    }
    return ans
}
