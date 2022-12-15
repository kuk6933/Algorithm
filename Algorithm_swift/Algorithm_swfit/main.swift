
import Foundation

var result = [[String]]()

func dfs(_ cur: String, _ flight: [String: [String]], _ flow: [String], _ cnt: Int,_ collection: Set<String>) {
    if collection.count == cnt {
        result.append(flow)
        return
    }
    var collection = collection
    var flow = flow
    var flight = flight
    for nation in flight[cur]! {
        flow.append(nation)
        collection.insert(nation)
        flight[cur]?.remove(at: (flight[cur]?.firstIndex(of: nation))!)
        dfs(nation, flight, flow, cnt, collection)
    }
}
func solution(_ tickets:[[String]]) -> [String] {
    var s = Set<String>()
    var collection = Set<String>()
    var flight = [String: [String]]()
    for ticket in tickets {
        flight[ticket[0]] = []
        flight[ticket[1]] = []
        s.insert(ticket[0])
        s.insert(ticket[1])
    }
    for ticket in tickets {
        flight[ticket[0]]?.append(ticket[1])
    }
    for ticket in tickets {
        flight[ticket[0]]?.sort()
    }
    dfs("ICN", flight, ["ICN"], s.count, collection )
    result = result.sorted(by: { $0[0] < $1[0] })
    return result[0]
}

print(solution([["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL","SFO"]]))
