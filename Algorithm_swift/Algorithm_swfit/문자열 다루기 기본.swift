//
//  main.swift
//  AlgorithmForSwift
//
//  Created by ohhyeongseok on 2022/08/23.
//

import Foundation

func solution(_ s:String) -> Bool {
    return (s.count == 4 || s.count == 6) && !s.contains(where: {$0.isLetter})
}
