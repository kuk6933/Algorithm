import Foundation
func solution(_ a:Int, _ b:Int) -> String {
    let month = [0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    var numberOfDay = -1
    if a == 1 {
        numberOfDay += b
    } else {
        for index in stride(from: 1, to: a, by: 1) {
            numberOfDay += month[index]
        }
        numberOfDay += b
    }
    var day = ""
    switch (numberOfDay % 7) {
    case 2:
        day = "SUN"
    case 3:
        day = "MON"
    case 4:
        day = "TUE"
    case 5:
        day = "WED"
    case 6:
        day = "THU"
    case 0:
        day = "FRI"
    case 1:
        day = "SAT"
    default:
        day = "SUN"
    }
    return day
}
