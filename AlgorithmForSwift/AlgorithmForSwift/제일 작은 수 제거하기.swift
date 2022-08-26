//
//  main.swift
//  AlgorithmForSwift
//
//  Created by ohhyeongseok on 2022/08/26.
//

import Foundation

func solution(_ arr:[Int]) -> [Int] {
    var result = arr
    result.remove(at: result.firstIndex(of: arr.min()!)!)
    
    return result.isEmpty ? [-1] : result
}
