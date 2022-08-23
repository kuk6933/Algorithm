//
//  main.swift
//  AlgorithmForSwift
//
//  Created by ohhyeongseok on 2022/08/23.
//

import Foundation

func solution(_ s:String) -> Bool
{
    return s.filter({$0 == "P" || $0 == "p"}).count == s.filter({$0 == "Y" || $0 == "y"}).count
    
}
