//
//  main.swift
//  AlgorithmForSwift
//
//  Created by ohhyeongseok on 2022/08/26.
//

import Foundation

func solution(_ clothes:[[String]]) -> Int {
    var answer = 1
    var dic: [String:Int] = [:]
    for cloth in clothes {
        if dic[cloth[1]] != nil {
            dic[cloth[1]]! += 1
        } else {
            dic[cloth[1]] = 1
        }
    }
    for (_, value) in dic {
        answer *= (value + 1)
    }
    return answer - 1
}
