//
//  조합.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/11/02.
//

func combination<T: Comparable>(_ array: [T], _ n: Int) -> [[T]] {
    var result = [[T]]()
    if array.count < n { return }

    func cycle(_ index: Int, _ now: [T]) {
        if now.count == n {
            result.append(now)
            return
        }
        
        for i in index..<array.count {
            cycle(i + 1, now + [array[i]])
        }
    }
    
    cycle(0, [])
    
    return result
}
