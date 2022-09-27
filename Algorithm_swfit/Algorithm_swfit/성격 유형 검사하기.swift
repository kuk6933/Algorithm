//
//  File.swift
//  AlgorithmForSwift
//
//  Created by ohhyeongseok on 2022/09/18.
//

import Foundation

func solution(_ survey:[String], _ choices:[Int]) -> String {
    
    var dic: [Character: Int] = [:]
    
    dic["R"] = 0
    dic["T"] = 0
    dic["C"] = 0
    dic["F"] = 0
    dic["J"] = 0
    dic["M"] = 0
    dic["A"] = 0
    dic["N"] = 0
    
    for i in 0...survey.count - 1 {
        if choices[i] > 4 {
            dic[survey[i].getChar(at: 1)]! += choices[i] - 4
        } else if choices[i] < 4 {
            dic[survey[i].getChar(at: 0)]! += 4 - choices[i]
        }
    }
    
    var ans = ""
    if dic["R"]! >= dic["T"]! {
        ans += "R"
    } else {
        ans += "T"
    }
    if dic["C"]! >= dic["F"]! {
        ans += "C"
    } else {
        ans += "F"
    }
    if dic["J"]! >= dic["M"]! {
        ans += "J"
    } else {
        ans += "M"
    }
    if dic["A"]! >= dic["N"]! {
        ans += "A"
    } else {
        ans += "N"
    }
    return ans
}

extension String {
    func getChar(at index: Int) -> Character {
        return self[self.index(self.startIndex, offsetBy: index)]
    }
}
