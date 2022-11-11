import Foundation

func makeFailureFunction(_ p: String) -> [Int] {
    let p = p.map{ $0 }
    let m = p.count
    var j = 0
    var f = [Int](repeating: 0, count: m)
    for i in 1..<m {
        while j > 0 && p[i] != p[j] {
            j = f[j-1]
        }
        if p[i] == p[j] {
            f[i] = j
            j += 1
        }
    }
    return f
}

func kmp(_ s: String, _ p: String) -> Bool {
    let f = makeFailureFunction(p)
    let s = s.map{ $0 }
    let p = p.map{ $0 }
    var j = 0
    let n = s.count
    let m = p.count
    for i in 0..<n {
        while j > 0 && s[i] != p[j] {
            j = f[j-1]
        }
        if s[i] == p[j] {
            if j == m - 1 {
                if i < s.count-1 {
                    if s[i+1] != "#" {
                        return true
                    }
                } else {
                    return true
                }
            } else {
                j += 1
            }
        }
    }
    return false
}
func replaceSharp(_ str: String) -> String {
    var replaced = str
    replaced = replaced.replacingOccurrences(of: "C#", with: "c")
    replaced = replaced.replacingOccurrences(of: "D#", with: "d")
    replaced = replaced.replacingOccurrences(of: "E#", with: "e")
    replaced = replaced.replacingOccurrences(of: "F#", with: "f")
    replaced = replaced.replacingOccurrences(of: "G#", with: "g")
    replaced = replaced.replacingOccurrences(of: "A#", with: "a")
    
    return replaced
}
    
    func solution(_ m:String, _ musicinfos:[String]) -> String {
    var ans = [(String, Int)]()
    let marr = m.map{ $0 }
    for info in musicinfos {
        let arr = info.split(separator: ",")
        let start = arr[0].map{ $0 }
        let end = arr[1].map{ $0 }
        var time = (Int(String(end[0...1]))! - Int(String(start[0...1]))!) * 60
        time += Int(String(end[3...4]))! - Int(String(start[3...4]))!
        var str = ""
        var strCode = replaceSharp(String(arr[3]))
        var replacedM = replaceSharp(m)
        var replacedCode = strCode.map{ $0 }
        for i in 0..<time {
            str += String(replacedCode[i % replacedCode.count])
        }
        

        //kmp로 찾고 넣어야함
        let isContain = kmp(str, replacedM)
        if isContain {
            ans.append((String(arr[2]), str.count))
        }
    }
    ans.sort(by: { $0.1 > $1.1 })
    if !ans.isEmpty {
        return ans.first!.0
    } else {
        return "(None)"
    }
}
print(solution("ABC", ["12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"]))
