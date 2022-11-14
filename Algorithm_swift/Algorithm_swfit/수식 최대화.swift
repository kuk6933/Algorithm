//
//  수식 최대화.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/11/02.
//

import Foundation

func solution(_ expression:String) -> Int64 {
    let numbers = expression.components(separatedBy: ["+", "-", "*"]).map{Int($0)!}
    print(numbers)
    let operation = expression.filter { !$0.isNumber }.map{$0}
    print(operation)
    var mx: Int64 = 0
    var order = [["+", "-", "*"],["+", "*", "-"],["-", "+", "*"],["-", "*", "+"],["*", "-", "+"],["*", "+", "-"]]
    for operations in order {
        var tmpNums = numbers
        var tmpOpers = operation
        for oper in operations {
            while tmpOpers.contains(Character(oper)) {
                if let idx = tmpOpers.firstIndex(of: Character(oper)) {
                    if oper == "+" {
                        tmpNums[idx] = tmpNums[idx] + tmpNums[idx+1]
                    } else if oper == "-" {
                        tmpNums[idx] = tmpNums[idx] - tmpNums[idx+1]
                    } else {
                        tmpNums[idx] = tmpNums[idx] * tmpNums[idx+1]
                    }
                    tmpOpers.remove(at: idx)
                    tmpNums.remove(at: idx+1)
                }
            }
        }
        if abs(tmpNums[0]) > mx {
            mx = Int64(abs(tmpNums[0]))
        }
    }
    return mx
}
