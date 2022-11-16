
import Foundation

func Gcd(_ num1: Int64, _ num2: Int64) -> Int64 {
    let remain = num1 % num2
    if remain == 0 {
        return num2
    } else {
        return Gcd(num2, remain)
    }
}
func solution(_ w:Int, _ h:Int) -> Int64{
    let width = Int64(min(w, h))
    let height = Int64(max(w, h))
    
    let sum = width * height
    let gcd = Gcd(width, height)
    
    return sum - (width / gcd + height / gcd - 1) * gcd
}

