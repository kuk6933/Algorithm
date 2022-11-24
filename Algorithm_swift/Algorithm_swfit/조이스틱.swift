//
//  조이스틱.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/11/24.
//
import Foundation
func solution(_ name:String) -> Int {
    var ans = 0
     let name = name.map({$0})
     for i in 0..<name.count {
         if name[i] != "A" {
             let up = name[i].asciiValue! - 65
             let down = 91 - name[i].asciiValue!
             ans += Int((up<down) ? up : down)
         }
     }
    
    var minMove = name.count - 1
    for startIdx in 0..<name.count {
        var endIdx = startIdx + 1
        while endIdx < name.count && name[endIdx] == "A" {
            endIdx += 1
        }
        let moveFront = startIdx * 2 + (name.count - endIdx)
        let moveBack = (name.count - endIdx) * 2 + startIdx
        minMove = min(minMove, moveFront)
        minMove = min(minMove, moveBack)
    }
    return ans + minMove
}

print(solution("JAZ"))
