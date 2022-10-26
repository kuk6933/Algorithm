//
//  파일명 정렬.swift
//  Algorithm_swfit
//
//  Created by ohhyeongseok on 2022/10/26.
//

func cmp( a: [String],  b: [String]) -> Bool {
    if a[0].lowercased() != b[0].lowercased() {
        return a[0].lowercased() < b[0].lowercased()
    } else {
        return Int(a[1])! < Int(b[1])!
    }
}
func solution(_ files:[String]) -> [String] {
    var arr = [[String]](repeating: Array(repeating: "", count: 3), count: files.count)
    for i in 0..<files.count {
        var trigger = -1
        var fileName = files[i].map({$0})
        for j in 0..<fileName.count {
            if trigger < 0 {
                if fileName[j].isNumber {
                    arr[i][1] += String(fileName[j])
                    trigger += 1
                } else {
                    arr[i][0] += String(fileName[j])
                }
            } else if trigger < 4  {
                if !fileName[j].isNumber {
                    arr[i][2] += String(fileName[j])
                    trigger = 5
                } else {
                    arr[i][1] += String(fileName[j])
                    trigger += 1
                }
            } else {
               arr[i][2] += String(fileName[j])
            }
        }
    }
    var tmp = arr.sorted(by: cmp(a:b:))
    var ans = [String]()
    for component in tmp {
        let str = component[0] + component[1] + component[2]
        ans.append(str)
    }
    return ans
    
}
