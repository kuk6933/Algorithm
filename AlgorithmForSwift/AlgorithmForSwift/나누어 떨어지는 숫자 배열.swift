import Foundation
func solution(_ arr:[Int], _ divisor:Int) -> [Int] {
    var result: [Int] = arr.filter( {$0 % divisor == 0})
    if result.count == 0 {
        result.append(-1)
    } else {
        result.sort()
    }
    return result
}

