//
//  프렌즈4블록.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/10/24.
//

func solution(_ m:Int, _ n:Int, _ board:[String]) -> Int {
    var boardArr = [[Character]]()
    for i in 0..<board.count {
        var tmp = board[i].map({$0})
        boardArr.append(tmp)
    }
    var some = [Bool](repeating: false, count: n)
    var matched = [[Bool]](repeating: some, count: m)
    var cnt = 0
    while(true) {
        var matched = [[Bool]](repeating: some, count: m)
        var boom = false
        for i in 0..<m-1 { // 전체 탐색
            for j in 0..<n-1 {
                if boardArr[i][j] != " " &&
                    boardArr[i][j] == boardArr[i][j+1] &&
                   boardArr[i][j] == boardArr[i+1][j] &&
                   boardArr[i][j] == boardArr[i+1][j+1] {
                    boom = true
                    matched[i][j] = true
                    matched[i][j+1] = true
                    matched[i+1][j] = true
                    matched[i+1][j+1] = true
                }
            }
        }
        if boom == false {
            break
        } else {
            for i in 0..<m {// 팡팡
                for j in 0..<n {
                    if matched[i][j] == true {
                        boardArr[i][j] = " "
                        cnt += 1
                    }
                }
            }
            for k in 0..<m {
                for i in stride(from: m-1, through: 1, by: -1) {
                    for j in 0..<n {
                        if boardArr[i][j] == " " {
                            boardArr[i][j] = boardArr[i-1][j]
                            boardArr[i-1][j] = " "
                        }
                    }
                }
            }
        }
    }
    return cnt
}
