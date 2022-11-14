func solution(_ dartResult:String) -> Int {
    let numbers = dartResult.split(whereSeparator: {$0.isLetter||$0=="*"||$0=="#"})
    let letters = dartResult.split(whereSeparator: {$0.isNumber})
    
    var result = numbers.map({Int($0)!})
    
    for (index, element) in letters.enumerated() {
        for c in String(element) {
            let i = Int(index)
            switch c {
            case "S":
                break
            case "D":
                result[i] *= result[i]
            case "T":
                result[i] *= result[i]*result[i]
            case "*":
                if i != 0 {
                    result[i-1] *= 2
                }
                result[i] *= 2
            case "#":
                result[i] *= -1
            default:
                print("error")
            }
        }
    }
    
    return result.reduce(0, +)
}
