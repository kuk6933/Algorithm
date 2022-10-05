//
//  괄호 회전하기.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/10/05.
//

import Foundation

func solution(_ s:String) -> Int {
    var ans = 0
    var arr = s.map { String($0) }
    for _ in 0...arr.count - 1 {
        let tmp = arr.removeFirst()
        arr.append(tmp)
        var stack = [String]()
        var isCan = true
        for j in 0...arr.count - 1 {
            if !stack.isEmpty {
                if arr[j] == ")"{
                    if stack[stack.count-1] == "(" {
                        stack.popLast()
                    } else {
                        isCan = false
                        break
                    }
                } else if arr[j] == "}" {
                    if stack[stack.count-1] == "{" {
                        stack.popLast()
                    } else {
                        isCan = false
                        break
                    }
                } else if arr[j] == "]" {
                    if stack[stack.count-1] == "[" {
                        stack.popLast()
                    } else {
                        isCan = false
                        break
                    }
                } else {
                    stack.append(arr[j])
                }
            } else {
                if arr[j] == "(" || arr[j] == "{" || arr[j] == "[" {
                    stack.append(arr[j])
                } else {
                    isCan = false
                    break
                }
            }
        }
        if !stack.isEmpty {
            isCan = false
        }
        if isCan {
            ans += 1
        }
    }
    return ans
}
