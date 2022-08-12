import Foundation
func solution(_ n:Int, _ arr1:[Int], _ arr2:[Int]) -> [String] {
    var mergeArr: [String] = []
    var answer: [String] = []
    
    for i in 0 ..< n {
        mergeArr.append(String((arr1[i] | arr2[i]), radix: 2))
    }
    
    for i in 0 ..< n {
        while mergeArr[i].count < n {
            mergeArr[i] = "0" + mergeArr[i]
        }
        var line = ""
        for char in mergeArr[i] {
            line += char == "1" ? "#" : " "
        }
        answer.append(line)
    }
    return answer
}
