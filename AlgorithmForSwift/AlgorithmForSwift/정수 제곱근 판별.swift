//
//  main.swift
//  AlgorithmForSwift
//
//  Created by ohhyeongseok on 2022/08/26.
//

import Foundation

import Foundation
func solution(_ n:Int64) -> Int64 {
    let t = Int64(sqrt(Double(n)))
    return t * t == n ? (t+1)*(t+1) : -1
}

