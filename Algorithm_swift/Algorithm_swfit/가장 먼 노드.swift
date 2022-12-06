//
//  가장 먼 노드.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/12/06.
//
import Foundation

func solution(_ n:Int, _ edge:[[Int]]) -> Int {
    var graph = [[Int]](repeating: [Int](), count: n+1)
    var visited = [Bool](repeating: false, count: n+1)
    var rank = [Int](repeating: 0, count: n+1)
    for e in edge {
        graph[e[0]].append(e[1])
        graph[e[1]].append(e[0])
    }
    
    visited[1] = true
    var q = [Int]()
    q.append(1)
    while !q.isEmpty {
        var cur = q.removeFirst()
        for i in 0..<graph[cur].count {
            if visited[graph[cur][i]] == false {
                q.append(graph[cur][i])
                visited[graph[cur][i]] = true
                rank[graph[cur][i]] = rank[cur] + 1
            }
        }
    }
    var mx = rank.max()
    var cnt = 0
    for i in rank {
        if i == mx {
            cnt += 1
        }
    }
    return cnt
}
