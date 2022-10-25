//
//  스킬트리.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/10/25.
//

import Foundation

func solution(_ skill:String, _ skill_trees:[String]) -> Int {
    var ans = 0
    let skill = skill.map({ $0 })
    var skillTrees = [[Character]]()
    for skillTree in skill_trees {
        let tmp = skillTree.map({ $0 })
        skillTrees.append(tmp)
    }
    
    for i in 0..<skillTrees.count {
        var skillChain = [(Character, Int)]()
        for i in 0..<skill.count {
            skillChain.append((skill[i], 0)) //초기화
        }
        var trigger = true
        for j in 0..<skillTrees[i].count {
            if skill.contains(skillTrees[i][j]) {
                if skillTrees[i][j] == skill[0] {
                    skillChain[0] = (skillTrees[i][j] ,1)
                } else {
                    for k in 0..<skill.firstIndex(of: skillTrees[i][j])! {
                        if skillChain[k].1 == 0 {
                            trigger = false
                        }
                        if trigger == false {
                            break
                        } else {
                            skillChain[skill.firstIndex(of: skillTrees[i][j])!] = (skillTrees[i][j],1)
                        }
                    }
                }
            }
            if trigger == false {
                break
            }
        }
        if trigger == true {
            ans += 1
        }
    }
    
    return ans
}
