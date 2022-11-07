//
//  불량 사용자.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/11/03.
//
import Foundation

func solution(_ user_id:[String], _ banned_id:[String]) -> Int {
    var bannedList = [[String]]()
    
    for bid in banned_id {
        var matched_id = [String]()
        var bidArr = bid.map{$0}
        
        for uid in user_id {
            var uidArr = uid.map{$0}
            if bid.count != uid.count { continue }
            var flag = true
            for i in 0..<bidArr.count {
                if bidArr[i] != uidArr[i] && bidArr[i] != "*" {
                    flag = false
                    break
                }
            }
            if flag {
                matched_id.append(uid)
            }
        }
        bannedList.append(matched_id)
    }
    // 각 ban id별로 배열 생성
    var stack = [(idx: Int, idList: [String])]()
    var answer = [[String]]()
    
    for id in bannedList[0] {
        stack.append((0, [id]))
    }
    
    while(stack.count > 0) {
        var cur = stack.removeLast()
        
        if cur.idx == banned_id.count - 1 {
            answer.append(cur.idList)
            continue
        }
        let idx = cur.idx + 1
        
        for id in bannedList[idx] {
            var idList = cur.idList
            if idList.contains(id) { continue }
            idList.append(id)
            stack.append((idx, idList))
        }
    }
    
    return Set(answer.map { $0.sorted()}).count
}

