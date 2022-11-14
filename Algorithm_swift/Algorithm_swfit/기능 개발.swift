//
//  기능 개발.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/10/07.
//

import Foundation

struct Queue {
    private var queue: [Int] = []
    
    public mutating func enqueue(_ element: Int) {
        queue.append(element)
    }
    
    public mutating func dequeue() -> Int? {
        return isEmpty ? nil : queue.removeFirst()
    }
    
    public var count: Int {
        return queue.count
    }
    
    public var isEmpty: Bool {
        return queue.isEmpty
    }
    
    
    public var peek: Int {
        return queue.first!
    }
    
    public func at(_ idx: Int) -> Int {
        return queue[idx]
    }
    public mutating func add(_ n: Int, _ idx: Int) {
        queue[idx] += n
    }
}



func solution(_ progresses:[Int], _ speeds:[Int]) -> [Int] {
    var ans = [Int]()
    var proqueue = Queue()
    var speedQueue = Queue()
    for progress in progresses {
        proqueue.enqueue(progress)
    }
    for speed in speeds {
        speedQueue.enqueue(speed)
    }
    while true {
        if proqueue.isEmpty {
            break
        }
        var cnt = 0
        for i in 0...proqueue.count - 1 {
            proqueue.add(speedQueue.at(i), i)
        }
        while true {
            if !proqueue.isEmpty && proqueue.peek >= 100 {
                cnt += 1
                proqueue.dequeue()
                speedQueue.dequeue()
            } else {
                break
            }
        }
        if cnt > 0 {
            ans.append(cnt)
        }
        if proqueue.isEmpty {
            break
        }
    }
    return ans
}
