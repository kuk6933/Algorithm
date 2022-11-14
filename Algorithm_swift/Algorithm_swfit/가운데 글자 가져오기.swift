//
//  main.swift
//  AlgorithmForSwift
//
//  Created by ohhyeongseok on 2022/08/12.
//

import Foundation

func solution(_ s:String) -> String {
    var ans = ""
    if s.count%2 == 1 {
        ans = "\(s[s.index(s.startIndex, offsetBy: s.count/2)])"
    } else {
        ans = "\(s[s.index(s.startIndex,offsetBy: s.count/2 - 1)])" + "\(s[s.index(s.startIndex, offsetBy: s.count/2)])"
    }
    return ans
}
