func findCheapestPrice(n int, flights [][]int, src int, dst int, k int) int {

    type Pair struct{
        First int
        Second int
    }

    type State struct{
        Node int
        Stops int
        Dist int
    }

    // n := len(flights)
    adj := make([][]Pair, n)

    for _ , it:= range flights {
        u := it[0]
        v := it[1]
        wt := it[2]

        adj[u] = append(adj[u], Pair{First: v, Second: wt})
    }

    dist := make([]int, n);
    for i:=0; i<n; i++ {
        dist[i] = 1e9
    }

    q := []State{{src, 0, 0}}

    for len(q)>0{
        curr := q[0]
        q = q[1:]

        if curr.Stops > k {
            continue
        }

        for _ , it := range adj[curr.Node] {
            if it.Second + curr.Dist < dist[it.First]{
                dist[it.First] = it.Second + curr.Dist
                q = append(q, State{it.First, curr.Stops+1, it.Second + curr.Dist})
            }
        }
    }
    if dist[dst] == 1e9 {
        return -1
    }
    return dist[dst]
}