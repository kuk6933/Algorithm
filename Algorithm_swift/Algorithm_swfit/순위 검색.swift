import Foundation

var dict = [String: [Int]]()

func resetDict() {
    for language in ["java", "python", "cpp", "-"] {
        for field in ["backend", "frontend","-"] {
            for carrer in ["junior", "senior", "-"] {
                for food in ["chicken", "pizza", "-"] {
                    dict[language + field + carrer + food] = [Int]()
                }
            }
        }
    }
}
func insertDict(_ info: [String]) {
    for str in info {
        let arr = str.components(separatedBy: " ")
        for language in [arr[0], "-"] {
            for field in [arr[1], "-"] {
                for carrer in [arr[2], "-"] {
                    for food in [arr[3], "-"] {
                        dict[language + field + carrer + food]!.append(Int(arr[4])!)
                    }
                }
            }
        }
    }
}
func lowerBound(_ arr: [Int], _ target: Int) -> Int {
    var low = 0
    var mid = 0
    var high = arr.count
    while low < high {
        mid = (low + high) / 2
        if arr[mid] < target {
            low = mid + 1
        } else {
            high = mid
        }
    }
    return high
}


import Foundation

func solution(_ info:[String], _ query:[String]) -> [Int] {
    resetDict()
    insertDict(info)
    
    for (key, value) in dict {
        dict[key] = value.sorted()
    }
    var result = [Int]()
    
    for q in query {
        var q = q.components(separatedBy: " ").filter{ $0 != "and" }
        
        let target = Int(q.removeLast())!
        let arr = dict[q.joined()]!
        
        let index = lowerBound(arr, target)
        result.append(arr.count - index)
    }
    return result
}
