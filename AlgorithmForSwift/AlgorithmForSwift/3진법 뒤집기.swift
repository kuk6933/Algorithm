func solution(_ n:Int) -> Int {
    let toThree = String(n, radix: 3)
    let answer = Int(String(toThree.reversed()), radix: 3)!
    return answer
}
