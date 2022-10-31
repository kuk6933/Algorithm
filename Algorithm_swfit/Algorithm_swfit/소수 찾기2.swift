//
//  소수 찾기2.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/10/31.
//


import Foundation

func isPrime(_ n: Int) -> Bool {
    if n < 2 {
        return false
    } else if n == 2 {
         return true
    } else {
        for i in 2...Int(sqrt(Double(n))) + 1 {
            if n % i == 0 {
                return false
            }
        }
        return true
    }
}

func solution(_ numbers:String) -> Int {
    var arr = numbers.map{$0}
    var result: Set<Int> = []
    var checkList = [Int](repeating: 0, count: arr.count)
    var number = ""
    
    func DFS(_ depth: Int,_ str: String, _ cnt: Int) {
        if depth == cnt {
            if let number = Int(str) {
                if isPrime(number) {
                    result.insert(number)
                }
            }
        } else {
            for i in 0..<arr.count {
                if checkList[i] == 0 {
                    number += String(arr[i])
                    checkList[i] = 1
                    DFS(depth + 1, number, cnt)
                    checkList[i] = 0
                    number = str
                }
            }
        }
    }
    for i in 1...arr.count {
        DFS(0, "", i)
    }
    return result.count
}
