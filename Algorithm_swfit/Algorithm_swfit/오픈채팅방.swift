//
//  오픈채팅방.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/10/13.
//


import Foundation

func solution(_ record:[String]) -> [String] {
    var result = [String]()
    var dict = [String: String]()
    var arr = [[String]]()
    for i in record {
        var a = [String]()
        a = i.components(separatedBy: " ")
        arr.append(a)
    }
    for sen in arr {
        switch sen[0] {
        case "Enter":
            dict[sen[1]] = sen[2]
        case "Change":
            dict[sen[1]] = sen[2]
        default:
            break
        }
    }
    for sen in arr {
        switch sen[0] {
        case "Enter":
            result.append("\(dict[sen[1]]!)님이 들어왔습니다.")
        case "Leave":
            result.append("\(dict[sen[1]]!)님이 나갔습니다.")
        default:
            continue
        }
    }
    return result
}
