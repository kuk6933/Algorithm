//
//  단어 변환.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/11/30.
//


import Foundation

var mn = Int.max

func dfs(_ visited: [Bool], _ cur: String, _ words: [String], _ cnt: Int, _ target: String) {
    if cur == target {
        if cnt < mn {
            mn = cnt
        }
    }
    var cur = cur.map{ $0 }
    var visited = visited
    for i in 0..<words.count {
        if visited[i] == false {
            var word = words[i].map{ $0 }
            var discord = 0
            for idx in 0..<word.count {
                if word[idx] != cur[idx] {
                    discord += 1
                }
            }
            if discord == 1 {
                visited[i] = true
                dfs(visited, words[i], words, cnt+1, target)
            }
        }
    }
}
func solution(_ begin:String, _ target:String, _ words:[String]) -> Int {
    var visited = [Bool](repeating: false, count: words.count)
    dfs(visited, begin, words, 0, target)
    if mn == Int.max {
        return 0
    }
    return mn
}
