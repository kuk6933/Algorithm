//
//  쿼드압축 후 개수 세기.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/11/01.
//

import Foundation

var zero = 0
var one = 0
func check(_ row: Int, _ col: Int, _ n: Int, _ arr: [[Int]]) {
    let criteria = arr[row][col]

    for i in row ..< row + n {
        for j in col ..< col + n {
            if arr[i][j] != criteria {
                check(row, col, n / 2, arr)
                check(row, col + n / 2, n / 2, arr)
                check(row + n / 2, col, n / 2, arr)
                check(row + n / 2, col + n / 2, n / 2, arr)
                return
            }
        }
    }
    if criteria == 0 {
        zero += 1
    } else {
        one += 1
    }
}
func solution(_ arr:[[Int]]) -> [Int] {
    check(0,0,arr.count, arr)
    return [zero, one]
}
