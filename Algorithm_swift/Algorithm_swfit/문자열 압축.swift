//
//  문자열 압축.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/11/22.
//

import Foundation

func slice(_ str: String, _ length: Int) -> [String] {
    var ans = [String]()
    var tmp = ""
    for s in str {
        tmp += String(s)
        if tmp.count >= length {
            ans.append(tmp)
            tmp = ""
        }
    }
    if tmp != "" { //남은거
        ans.append(tmp)
    }
    return ans
}
func condense(_ arr: [String]) -> String {
    var ans = ""
    var tmp = ""
    var cnt = 1
    
    for str in arr {
        if tmp == str {
            cnt += 1
        } else {
            if tmp != "" {
                ans += (cnt > 1) ? "\(cnt)\(tmp)" : "\(tmp)"
            }
            tmp = str
            cnt = 1
        }
    }
    if tmp != "" {
        ans += (cnt > 1) ? "\(cnt)\(tmp)" : "\(tmp)"
    }
    return ans
}
func solution(_ s:String) -> Int {
    if s.count <= 2 { return s.count }
    var ans = Int.max
    
    for i in 1...s.count/2 {
        var number = condense(slice(s,i)).count
        if ans > number {
            ans = number
        }
    }
    return ans
}
    
