//
//  main.swift
//  AlgorithmForSwift
//
//  Created by ohhyeongseok on 2022/08/23.
//

import Foundation

func solution(_ n:Int) -> Int {
    var count = 0
    var array = Array(repeating: false, count: n+1)
    
    for i in 2...n {
        if array[i] == false {
            count += 1
            
            for j in stride(from: i, through: n, by: i) {
                array[j] = true
            }
        }
    }
    return count
}
