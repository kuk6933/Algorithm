import Foundation

func solution(_ elements:[Int]) -> Int {
    var newelements = elements
    newelements.append(contentsOf: elements)
    var set = Set<Int>()
    for i in 1...elements.count {
        for j in 0..<elements.count {
            var tmp = 0
            for k in j..<j+i {
                tmp += newelements[k]
            }
            set.insert(tmp)
        }
    }
    return set.count
}
