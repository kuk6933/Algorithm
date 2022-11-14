//
//  main.swift
//  AlgorithmForSwift
//
//  Created by ohhyeongseok on 2022/08/23.
//

import Foundation

func solution(_ strings:[String], _ n:Int) -> [String] {
    return strings.sorted { Array($0)[n] == Array($1)[n] ? $0 < $1 : Array($0)[n] < Array($1)[n]}
}
