//
//  괄호 변환.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/11/10.
//

import Foundation

func check(_ p: String) -> (Bool, Bool) {
    var stk = [String]()
    var oCnt = 0
    var cCnt = 0
    var isComplete = true
    for char in p {
        if char == "(" {
            oCnt += 1
            stk.append("(")
        } else {
            cCnt += 1
            if !stk.isEmpty {
                if stk.last! == "(" {
                    stk.removeLast()
                } else {
                    isComplete = false
                }
            } else {
                isComplete = false
            }
        }
    }
    if isComplete {
        return (true, true)
    } else if oCnt == cCnt {
        return (false, true)
    } else {
        return (false, false)
    }
}

func solution(_ p:String) -> String {
    if p.isEmpty {
        return ""
    }
    var isComplete = check(p)
    if isComplete.0 { //온전ㄴ
        return p
    } else { // 온전x balnce o
        var u = ""
        var v = ""
        var oCnt = 0
        var cCnt = 0
        var isU = true
        for char in p {
            if isU {
                u += String(char)
                if char == "(" {
                    oCnt += 1
                } else {
                    cCnt += 1
                }
                if oCnt == cCnt {
                    isU = false
                }
            } else {
                v += String(char)
            }
        } // u, v나눴음
        if check(u).0 { // u가 완전체임
            var vStr = solution(v)
            return u+vStr
        } else { // 아님
            var tmp = "("
            tmp += solution(v)
            tmp += ")"
            u.removeFirst()
            u.removeLast()
            var reverseU = ""
            for char in u {
                if char == ")" {
                    reverseU.append("(")
                } else {
                    reverseU.append(")")
                }
            }
            return tmp + reverseU
        }
    }
}
