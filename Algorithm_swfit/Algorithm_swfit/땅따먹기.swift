//
//  땅따먹기.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/10/25.
//
import Foundation

func solution(_ land:[[Int]]) -> Int{
    var answer = 0
    var land = land
    
    for i in 1..<land.count {
        land[i][0] += max(land[i-1][1], land[i-1][2], land[i-1][3])
        land[i][1] += max(land[i-1][0], land[i-1][2], land[i-1][3])
        land[i][2] += max(land[i-1][0], land[i-1][1], land[i-1][3])
        land[i][3] += max(land[i-1][0], land[i-1][1], land[i-1][2])
    }
    for i in 0...3 {
        if answer < land[land.count-1][i] {
            answer = land[land.count-1][i]
        }
    }
    return answer
}

