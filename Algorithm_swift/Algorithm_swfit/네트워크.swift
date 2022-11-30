//
//  네트워크.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/11/30.
//

import Foundation

func dfs(_ com: Int,_ computers:[[Int]], _ visited: inout [Bool]) {
    for i in 0..<computers[com].count {
        if visited[i] == false && computers[com][i] == 1 {
            visited[i] = true
            print(i)
            dfs(i, computers, &visited)
        }
    }
}

func solution(_ n:Int, _ computers:[[Int]]) -> Int {
    var visited = [Bool](repeating:false, count: n+1)
    var ans = 0
    for i in 0..<n {
        if visited[i] == false {
            visited[i] = true
            dfs(i, computers ,&visited)
            ans += 1
        }
    }
    return ans
}
