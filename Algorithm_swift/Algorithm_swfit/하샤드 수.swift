//
//  하샤드 수.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/12/12.
//
func solution(_ x:Int) -> Bool {
    var num = x
    var sum = 0
    while(num != 0) {
        sum += num % 10
        num /= 10
    }
    
    return x % sum == 0
}
