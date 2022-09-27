//
//  main.swift
//  AlgorithmForSwift
//
//  Created by ohhyeongseok on 2022/08/23.
//

import Foundation

func solution(_ s:String, _ n:Int) -> String {
    
    let lower = Array("abcdefghijklmnopqrstuvwxyz")
    let upper = Array("abcdefghijklmnopqrstuvwxyz".uppercased())
    let input = Array(s)
    var result = ""
   
    for i in input {
        if i == " "
        {
            result.append(i)
        } else if upper.contains(i) {
            var indexNum = upper.firstIndex(of: i)! + n
            if indexNum > 25 {
                indexNum = indexNum - 26
            }
            result.append(upper[indexNum])
        } else {
            var indexNum = lower.firstIndex(of: i)! + n
            if indexNum > 25 {
                indexNum = indexNum - 26
            }
            result.append(lower[indexNum])
        }
    }
    return result
}
