//
//  main.swift
//  AlgorithmForSwift
//
//  Created by ohhyeongseok on 2022/08/23.
//

import Foundation
func solution(_ s:String) -> String {
    return String(s.sorted { $0 > $1})
}
