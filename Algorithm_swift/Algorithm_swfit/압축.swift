//
//  압축.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/10/12.
//

func solution(_ msg:String) -> [Int] {
    var dic = [String: Int]()
    var ans = [Int]()
    var cnt = 1
    let alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    let alphabetArr = alphabet.map({ $0 })
    for i in alphabetArr {
        cnt += 1
        dic[String(i)] = cnt
    }
    var strCnt = 0
    var msgArr = msg.map( { $0 })
    for i in 0...msg.count-1 {
        var done = false
        var str = ""
        var prestr = ""
        if strCnt > 0 {
            strCnt -= 1
            continue;
        }
        for j in i...msg.count - 1 {
            str += String(msgArr[j])
            if dic[str] != nil {
                prestr = str
                strCnt += 1
            } else {
                print(prestr)
                ans.append(dic[prestr]!)
                cnt += 1
                strCnt -= 1
                dic[str] = cnt
                done = true
                break
            }
        }
        if done == false {
            ans.append(dic[prestr]!)
        }
    }
    return ans
}
