//
//  다리를 지나는 트럭.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/10/28.
//

import Foundation
 
func solution(_ bridge_length:Int, _ weight:Int, _ truck_weights:[Int]) -> Int {
    var truck_weights = truck_weights
    var time = 0
    var w = 0
    var times = [Int]()
    var weights = [Int]()
    
    while !truck_weights.isEmpty{
        time += 1
        if !times.isEmpty{
            if time == times.first! {
            times.removeFirst()
            w -= weights.first!
            weights.removeFirst()
        }
    }
        if w+truck_weights.first! <= weight{
            w += truck_weights.first!
            weights.append(truck_weights.first!)
            times.append(time+bridge_length)
            truck_weights.removeFirst()
        }
    }
    return times.last!
}


