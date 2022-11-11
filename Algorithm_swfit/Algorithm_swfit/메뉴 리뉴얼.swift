//
//  메뉴 리뉴얼.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/11/09.
//
import Foundation

func combination<T: Comparable>(_ array: [T], _ n: Int) -> [[T]] {
    var result = [[T]]()

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

func solution(_ orders:[String], _ course:[Int]) -> [String] {
    var dic: [String: Int] = [:]
    for num in course {
        for order in orders {
            var orderArr = order.sorted().map{ String($0) }
            var com = combination(orderArr, num)
            for course in com {
                if let _ = dic[course.joined()] {
                    dic[course.joined()]! += 1
                } else {
                    dic[course.joined()] = 1
                }
            }
        }
    }
    var ans = [String]()
    for num in course {
        var mx = 0
        for (key, value) in dic {
            if key.count == num, value > mx {
                mx = value
            }
        }
        for (key, value) in dic {
            if value == mx && value >= 2 && key.count == num {
                ans.append(key)
            }
        }
    }
    return ans.sorted()
}
