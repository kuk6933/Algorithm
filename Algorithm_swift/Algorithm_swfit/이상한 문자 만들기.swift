//
//  main.swift
//  AlgorithmForSwift
//
//  Created by ohhyeongseok on 2022/08/25.
//

import Foundation

func solution(_ s:String) -> String {
    var result = ""
    var cnt = 0
    for element in s {
        if element == " " {
            cnt = 0
            result.append(element)
        } else if cnt % 2 == 0 {
            result.append(element.description.uppercased())
            cnt += 1
        } else {
            result.append(element.description.lowercased())
            cnt += 1
        }
    }
    return result
}
