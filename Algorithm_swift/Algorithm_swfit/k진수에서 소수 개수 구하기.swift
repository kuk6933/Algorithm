//
//  main.swift
//  AlgorithmForSwift
//
//  Created by ohhyeongseok on 2022/09/19.
//

import Foundation

func isPrimeNumber(_ n:Int) -> Bool {
    if n == 1  { return false }
    if n == 2 || n == 3 {return true}
    let sq = Int(sqrt(Double(n)))
    for i in 2...sq {
        if n%i == 0 {
            return false
        }
    }
    return true
}

func solution(_ n:Int, _ k:Int) -> Int {
    let radix = String(n, radix: k)
    let split = radix.split(separator: "0")
    return split.filter{isPrimeNumber(Int($0)!)}.count
}


