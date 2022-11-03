//
//  순열.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/11/02.
//

import Foundation
func permutation<T: Comparable>(_ array: [T], _ n: Int) -> [[T]] {
    var result = [[T]]()
    
    if array.count < n { return result }
    
    var visited = Array(repeating: false, count: array.count)
    
    func cycle(_ now: [T]) {
        if now.count == n {
            result.append(now)
            return
        }
        for i in 0..<array.count {
            if visited[i] {
                continue
            } else {
                visited[i] = true
                cycle(now + [array[i]])
                visited[i] = false
            }
        }
    }
    cycle([])
    print(result)
    return result
}


var b = permutation([1,2,3,4,5,6], 6)
