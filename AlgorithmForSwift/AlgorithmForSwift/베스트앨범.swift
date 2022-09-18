//
//  main.swift
//  AlgorithmForSwift
//
//  Created by ohhyeongseok on 2022/09/15.
//

import Foundation

func solution(_ genres:[String], _ plays:[Int]) -> [Int] {
    var genreDic = [String: Int]()
    var idDic = [String:[Int]]()
    
    for i in stride(from: 0, to: genres.count, by: 1) {
        if genreDic[genres[i]] != nil {
            genreDic[genres[i]]! += plays[i]
        } else {
            genreDic[genres[i]] = plays[i]
        }
        if idDic[genres[i]] != nil {
            idDic[genres[i]]!.append(i)
        } else {
            idDic[genres[i]] = [i]
        }
    }
    
    let genreRanking: [String] = Array(genreDic.keys).sorted {
        return genreDic[$0]! > genreDic[$1]!
    }
    var answer: [Int] = []
    for genre in genreRanking {
        let ids = idDic[genre]!.sorted {
            return plays[$0] > plays[$1]
        }
        answer.append(ids[0])
        if ids.count > 1 {
            answer.append(ids[1])
        }
    }
    return answer
}
