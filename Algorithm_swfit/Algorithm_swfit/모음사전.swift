//
//  모음사전.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/10/27.
//

import Foundation

var arr = [String]()

func recursion(str: String){
    var tmp = str
    if tmp.count < 5 {
        tmp += "A"
        arr.append(tmp)
        recursion(str: tmp)
    }
    tmp = str
    if tmp.count < 5 {
        tmp += "E"
        arr.append(tmp)
        recursion(str: tmp)
    }
    tmp = str
    if tmp.count < 5 {
        tmp += "I"
        arr.append(tmp)
        recursion(str: tmp)
    }
    tmp = str
    if tmp.count < 5 {
        tmp += "O"
        arr.append(tmp)
        recursion(str: tmp)
    }
    tmp = str
    if tmp.count < 5 {
        tmp += "U"
        arr.append(tmp)
        recursion(str: tmp)
    }
}
func solution(_ word:String) -> Int {
    recursion(str: "")
    return arr.firstIndex(of: word)! + 1
}
