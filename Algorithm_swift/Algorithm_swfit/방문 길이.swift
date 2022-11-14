//
//  방문 길이.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/10/26.
//
import Foundation

struct Pair: Hashable {
    var x: Int
    var y: Int
    init(_ x: Int, _ y: Int) {
        self.x = x
        self.y = y
    }
}

func solution(_ dirs:String) -> Int {
    var visited = [Pair: Set<Pair>]()
    var curX = 5
    var curY = 5
    var dirs = dirs.map({ $0 })
    for dir in dirs {
        switch dir {
        case "U":
            if curX < 10 {
                var cur = Pair(curX, curY)
                curX += 1
                var next = Pair(curX, curY)
                if visited[cur] != nil {
                    visited[cur]!.insert(next)
                } else {
                    visited[cur] = Set<Pair>()
                    visited[cur]!.insert(next)
                }
            }
            
        case "D":
            if curX > 0 {
                var cur = Pair(curX, curY)
                curX -= 1
                var next = Pair(curX, curY)
                if visited[cur] != nil {
                    visited[cur]!.insert(next)
                } else {
                    visited[cur] = Set<Pair>()
                    visited[cur]!.insert(next)
                }
            }
        case "R":
            if curY < 10 {
                var cur = Pair(curX, curY)
                curY += 1
                var next = Pair(curX, curY)
                if visited[cur] != nil {
                    visited[cur]!.insert(next)
                } else {
                    visited[cur] = Set<Pair>()
                    visited[cur]!.insert(next)
                }
            }
        default:
            if curY > 0 {
                var cur = Pair(curX, curY)
                curY -= 1
                var next = Pair(curX, curY)
                if visited[cur] != nil {
                    visited[cur]!.insert(next)
                } else {
                    visited[cur] = Set<Pair>()
                    visited[cur]!.insert(next)
                }
            }
        }
    }
    var ans = 0.0
    for s in visited {
        ans += Double(s.value.count)
    }
    for s in visited {
        for j in s.value {
            if visited[j] != nil {
                if visited[j]!.contains(s.key) {
                    ans -= 0.5
                }
            }
        }
    }
    return Int(ans)
}
