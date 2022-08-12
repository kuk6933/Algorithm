//
//  main.swift
//  AlgorithmForSwift
//
//  Created by ohhyeongseok on 2022/08/12.
//

import Foundation

func solution(_ price:Int, _ money:Int, _ count:Int) -> Int64{
    var totalPrice = 0
    for i in 1 ... count {
        totalPrice += i * price
    }
    var answer:Int64 = Int64(money - totalPrice)
    if answer > 0 {
        answer = 0
    } else {
        answer = -answer
    }
    return answer
}
