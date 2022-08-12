import Foundation

func solution(_ n:Int) -> Int {
    if n % 2 == 1 {
        return 2
    }
    for i in stride(from: 3, to: n-1, by: 2){
        if n % i == 1 {
            return i
        }
    }
    return n - 1
}
