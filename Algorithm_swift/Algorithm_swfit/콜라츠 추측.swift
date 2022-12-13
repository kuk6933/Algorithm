//
//  콜라츠 추측.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/12/13.
//

func solution(_ num:Int) -> Int {
    var cnt = 0
    var a = num
    if a == 0 {
        return -1
    }
    while a != 1 {
        if a % 2 == 0 {
            a /= 2
        } else {
            a = a * 3 + 1
        }
        cnt += 1
        
        if cnt == 500 {
            return -1
        }
    }
    return cnt
}
