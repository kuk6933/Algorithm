//
//  행렬 테두리 회전하기.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/11/11.
//

import Foundation

func solution(_ columns:Int, _ rows:Int, _ queries:[[Int]]) -> [Int] {
    var board = [[Int]](repeating: [Int](repeating: 0, count: rows+1), count: columns+1)
    var cnt = 1
    var ans = [Int]()
    for i in 1...columns { //격자판 만들기
        for j in 1...rows {
            board[i][j] = cnt
            cnt += 1
        }
    }
    for query in queries {
        var mn = Int.max

        let p1 = (query[0], query[1])
        let p2 = (query[2], query[3])
        let tmp1 = board[p1.0][p2.1] // (2,4) 저장
        if tmp1 < mn { mn = tmp1 }
        for p in stride(from: p2.1, through: p1.1 + 1, by: -1) {
            board[p1.0][p] = board[p1.0][p-1]
            if board[p1.0][p] < mn {
                mn = board[p1.0][p]
            }
        }
        var tmp = board[p1.0+1][p1.1]
        if tmp < mn { mn = tmp }
        let tmp2 = board[p2.0][p2.1]
        board[p1.0+1][p2.1] = tmp1
        if tmp2 < mn { mn = tmp2 }
        for p in stride(from: p2.0, through: p1.0 + 2, by: -1) {
            board[p][p2.1] = board[p-1][p2.1]
            if board[p][p2.1] < mn {
                mn = board[p][p2.1]
            }
        }

        board[p2.0][p1.1] = tmp2
        let tmp3 = board[p1.0][p2.1]
        if tmp3 < mn { mn = tmp3 }
        for p in stride(from: p1.0, through: p2.0 - 2, by: 1) {
            board[p][p1.1] = board[p+1][p1.1]
            if board[p][p1.1] < mn {
                mn = board[p][p1.1]
            }
        }

        board[p1.0][p2.1-1] = tmp3
        for p in stride(from: p2.1, through: p1.1 + 1, by: -1) {
            board[p1.0][p] = board[p1.0][p-1]
            if board[p1.0][p] < mn {
                mn = board[p1.0][p]
            }
        }
        board[p1.0][p1.1] = tmp
        ans.append(mn)
    }
    return ans
}
