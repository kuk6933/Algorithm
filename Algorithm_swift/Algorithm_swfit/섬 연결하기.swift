//
//  섬 연결하기.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/12/07.
//

import Foundation

func solution(_ n:Int, _ costs:[[Int]]) -> Int {
    var ans = 0
    var costs = costs.sorted { $0[2] < $1[2] }
    var parent = [Int](repeating:0, count: n)
    for i in 0..<n { //부모를 나타냄
        parent[i] = i
    }
    for cost in costs {
        if findParent(&parent, cost[0]) != findParent(&parent, cost[1]) {
            union(&parent, cost[0], cost[1])
            ans += cost[2]
        }
    }
    return ans
}

func union(_ parent: inout [Int], _ a: Int, _ b: Int) {
    let a = findParent(&parent, a)
    let b = findParent(&parent, b)
    
    if a < b {
        parent[b] = a
    } else {
        parent[a] = b
    }
}

func findParent(_ parent: inout [Int], _ x: Int) -> Int {
    if parent[x] != x {
        parent[x] = findParent(&parent, parent[x])
    }
    return parent[x]
}
