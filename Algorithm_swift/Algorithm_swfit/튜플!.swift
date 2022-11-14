//
//  튜플.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/10/06.
//

import Foundation

func solution(_ s:String) -> [Int] {
    var s = s
    var ans = [Int]()

    var stringTuples = s.replacingOccurrences(of: "{", with: "").components(separatedBy: "},").map({$0.replacingOccurrences(of: "}", with: "")})
    let tuples = stringTuples.map({ stringTuple -> [String] in
        stringTuple.components(separatedBy: ",")
    })
    let sortedTuples = tuples.sorted(by: { $0.count < $1.count })
    for tuple in sortedTuples {
        for num in tuple {
            let number = Int(num)!
            if !ans.contains(number) {
                ans.append(number)
            }
        }
    }
    return ans
}
