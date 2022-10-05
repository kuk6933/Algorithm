//
//  H-Index.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/10/05.
//

import Foundation

func solution(_ citations:[Int]) -> Int {
    let arr = citations.sorted(by: >)
    var index = -1
        
    while true {
        index += 1
        if index >= arr.count {
            return arr.count
        }
        
        if index >= arr[index] {
            return index
        }
    }
}
