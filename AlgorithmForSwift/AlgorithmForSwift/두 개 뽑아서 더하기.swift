import Foundation

func solution(_ numbers:[Int]) -> [Int] {
    var set: Set<Int> = []
    for i in stride(from: 0, to: numbers.count, by: 1) {
        for j in stride(from: i+1, to: numbers.count, by: 1) {
            set.insert(numbers[i] + numbers[j])
        }
    }
    let arr = set.sorted()
    return arr.sorted()
}
