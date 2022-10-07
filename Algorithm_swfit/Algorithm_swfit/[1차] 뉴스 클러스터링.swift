//
//  기능 개발.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/10/07.
//

func solution(_ str1:String, _ str2:String) -> Int {
    var dic1: [String: Int] = [:]
    var dic2: [String: Int] = [:]
    
    let str1Arr = str1.map({ $0 })
    let str2Arr = str2.map({ $0 })
    
    for i in 0...str1Arr.count-2 {
        if str1Arr[i].isLetter, str1Arr[i+1].isLetter {
            var tmp = String(str1Arr[i]).lowercased() + String(str1Arr[i+1]).lowercased()
            if dic1[tmp] != nil {
                dic1[tmp]! += 1
            } else {
                dic1[tmp] = 1
            }
        }
    }
    
    
    for i in 0...str2Arr.count-2 {
        if str2Arr[i].isLetter, str2Arr[i+1].isLetter {
            var tmp = String(str2Arr[i]).lowercased() + String(str2Arr[i+1]).lowercased()
            if dic2[tmp] != nil {
                dic2[tmp]! += 1
            } else {
                dic2[tmp] = 1
            }
        }
    }
    
    var sum = 0
    var inter = 0
    
    for (key, value) in dic1 {
        if dic2[key] != nil {
            sum += max(value, dic2[key]!)
            inter += min(value, dic2[key]!)
        } else {
            sum += value
        }
    }
    
    for (key, value) in dic2 {
        if dic1[key] == nil {
            sum += value
        }
    }
    if sum == 0 {
        return 65536
    }
    var divide = Int(Double(inter) / Double(sum) * 65536)
    return divide
}
var sol = solution("E=M*C^2", "e=m*c^2")
