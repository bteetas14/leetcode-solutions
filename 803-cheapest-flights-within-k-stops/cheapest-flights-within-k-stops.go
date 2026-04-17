func findCheapestPrice(n int, flights [][]int, src int, dst int, k int) int {
    
    // Define edge struct (cleaner than [2]int)
    type Edge struct {
        to   int
        cost int
    }

    // Build graph
    graph := make(map[int][]Edge)
    for _, f := range flights {
        from, to, price := f[0], f[1], f[2]
        graph[from] = append(graph[from], Edge{to, price})
    }

    // Distance array (min cost to reach each city)
    const INF = int(1e9)
    dist := make([]int, n)
    for i := 0; i < n; i++ {
        dist[i] = INF
    }
    dist[src] = 0

    // Queue for BFS: (city, cost, stops)
    type State struct {
        city  int
        cost  int
        stops int
    }

    queue := []State{{src, 0, 0}}

    for len(queue) > 0 {
        curr := queue[0]
        queue = queue[1:]

        // If we exceed allowed stops, skip
        if curr.stops > k {
            continue
        }

        // Explore neighbors
        for _, edge := range graph[curr.city] {
            nextCity := edge.to
            newCost := curr.cost + edge.cost

            // Relaxation condition
            if newCost < dist[nextCity] {
                dist[nextCity] = newCost
                queue = append(queue, State{nextCity, newCost, curr.stops + 1})
            }
        }
    }

    if dist[dst] == INF {
        return -1
    }
    return dist[dst]
}