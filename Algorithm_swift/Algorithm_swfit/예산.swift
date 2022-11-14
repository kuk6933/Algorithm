import Foundation

func solution(_ d:[Int], _ budget:Int) -> Int {
    var money = budget
    var department = 0
    let sortedArray = d.sorted()
    for i in stride(from: 0, to: d.count, by: 1) {
        if money <= 0 {
            break
        }
        if money >= sortedArray[i] {
            money -= sortedArray[i]
            department += 1
        }
    }
    return department
}
