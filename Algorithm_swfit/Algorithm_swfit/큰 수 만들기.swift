//
//  큰 수 만들기.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/11/08.
//

import Foundation

func solution(_ number:String, _ k:Int) -> String {
    var numberArr = number.map({ String($0) })
    var k = k
    var stack = [String]()
    
    for n in numberArr {
        while !stack.isEmpty , k > 0 , stack.last! < n {
            stack.removeLast()
            k -= 1
        }
        stack.append(n)
    }
    while k > 0 {
        stack.removeLast()
        k -= 1
    }
    return stack.joined()
}
