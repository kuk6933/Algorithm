//
//  main.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/09/27.
//

import Foundation

func solution(_ s:String) -> [Int] {
    var radixS = s
    var zcnt = 0
    var cnt = 0
    
    while(radixS.count != 1) {
        zcnt += radixS.filter({ $0 == "0"}).count
        radixS = radixS.components(separatedBy: "0").joined()
        radixS = String(radixS.count, radix: 2)
        cnt += 1
    }
    return [cnt, zcnt]
}

var a = solution("110")
