import Foundation
func solution(_ a:Int, _ b:Int) -> Int64 {
    
    var numa = a
    var numb = b
    var result = 0
    if numa > numb {
        swap(&numa, &numb)
    }
    var num = 0
        for i in stride(from: numa, through: numb, by: 1) {
        result += i
    }
    return Int64(result)
}
