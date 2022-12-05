//
//  스티커 모으기(2).swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/12/05.
//

import Foundation

func solution(_ sticker:[Int]) -> Int {
    var dp1 = [Int](repeating:0, count: sticker.count)
    var dp2 = [Int](repeating:0, count: sticker.count)
    if sticker.count < 3 {
        if sticker.count == 1 {
            return sticker[0]
        } else {
            return max(sticker[0], sticker[1])
        }
    }
    dp1[0] = sticker[0]
    dp1[1] = dp1[0]
    dp2[1] = sticker[1]
    for i in 2..<sticker.count-1 {
        dp1[i] = max(dp1[i-2] + sticker[i], dp1[i-1])
    }
    for i in 2..<sticker.count {
        dp2[i] = max(dp2[i-2] + sticker[i], dp2[i-1])
    }
    return max(dp1[sticker.count-2], dp2[sticker.count-1])
}
