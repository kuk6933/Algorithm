//
//  n진수 게임.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/10/17.
//

import Foundation

func solution(_ n:Int, _ t:Int, _ m:Int, _ p:Int) -> String {
    
    var arr = [String]()
    for i in 0...100002 {
        let str = String(i, radix: n)
        let tmp = str.map({ $0 })
        for char in tmp {
            if char <= "z" {
                arr.append(String(char).uppercased())
            }
        }
    }
    var turn = [Int]()
    if p != m {
        turn = (1...100002).filter{ $0 % m == p}
    } else {
        turn = (1...100002).filter{ $0 % m == 0}
    }
    var ans = ""
    for i in 0...t-1 {
        ans += arr[turn[i]-1]
    }
    return ans
}
