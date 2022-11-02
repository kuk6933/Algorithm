//
//  거리두기 확인하기.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/11/02.
//

import Foundation
var one = [[1,0],[0,1],[0,-1],[-1,0]]
func solution(_ places:[[String]]) -> [Int] {
    var ans = [Int]()
    for place in places {
        var room = [[Character]]()
        for line in place {
            var arr = line.map{$0}
            room.append(arr)
        }
        
        var flag = true
        for i in 0..<room.count {
            for j in 0..<room[i].count {
                if room[i][j] == "P" {
                    for k in one {
                        if i + k[0] < 0 || j+k[1] < 0 || i + k[0] > 4 || j+k[1] > 4  {
                            continue
                        } else {
                            if room[i+k[0]][j+k[1]] == "P" {
                                flag = false
                                break
                            }
                        }
                    }
                    if i + 2 <= 4 {
                        if room[i+2][j] == "P" {
                            if room[i+1][j] != "X" {
                                flag = false
                                break
                            }
                        }
                    }
                    if j + 2 <= 4 {
                        if room[i][j+2] == "P" {
                            if room[i][j+1] != "X" {
                                flag = false
                                break
                            }
                        }
                    }
                    if i - 2 >= 0 {
                        if room[i-2][j] == "P" {
                            if room[i-1][j] != "X" {
                                flag = false
                                break
                            }
                        }
                    }
                    if j - 2 >= 0  {
                        if room[i][j-2] == "P" {
                            if room[i][j-1] != "X" {
                                flag = false
                                break
                            }
                        }
                    }
                    
                    if i+1 <= 4, j+1 <= 4 {
                        if room[i+1][j+1] == "P" {
                            if room[i+1][j] != "X" || room[i][j+1] != "X" {
                                flag = false
                                break
                            }
                        }
                    }
                    if i+1 <= 4, j-1 >= 0 {
                        if room[i+1][j-1] == "P" {
                            if room[i+1][j] != "X" || room[i][j-1] != "X" {
                                flag = false
                                break
                            }
                        }
                    }
                    if i-1 >= 0, j-1 >= 4 {
                        if room[i-1][j-1] == "P" {
                            if room[i][j-1] != "X" || room[i-1][j] != "X" {
                                flag = false
                                break
                            }
                        }
                    }
                    if i-1 >= 0, j+1 <= 4 {
                        if room[i-1][j+1] == "P" {
                            if room[i-1][j] != "X" || room[i][j+1] != "X" {
                                flag = false
                                break
                            }
                        }
                    }
                    if flag == false {
                        break
                    }
                }
            }
        }
        var good: Int = flag ? 1 : 0
        ans.append(good)
    }
    return ans
}
