//
//  기지국 설치.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/12/02.
//
import Foundation

func solution(_ n:Int, _ stations:[Int], _ w:Int) -> Int{
    var tmp = 1
    var ans = 0
    
    for station in stations {
        ans += Int(ceil((Double(station - w - tmp) / Double(2 * w + 1))))
        tmp = station + w + 1
    }
    if tmp <= n {
        ans += Int(ceil((Double(n - tmp + 1) / Double(2 * w + 1))))
    }
    return ans
}
