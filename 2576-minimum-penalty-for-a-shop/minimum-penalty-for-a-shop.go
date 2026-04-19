// prefixSum = 0 0 0 1 1
// suffixSum = 3 2 1 1 0

func bestClosingTime(customers string) int {

    n := len(customers)
    minPenalty := int(1e9)
    minHour := int(1e9)

    prefixSum := make([]int, n+1)
    prefixSum[0] = 0
    suffixSum := make([]int, n+1)
    suffixSum[n] = 0

    for i:=1; i<=n; i++ {
        if customers[i-1] == 'Y' {
            prefixSum[i] = prefixSum[i-1]
        } else {
            prefixSum[i] = prefixSum[i-1] + 1
        }
    }

    for i:=n-1; i>=0; i-- {
        if customers[i]=='Y' {
            suffixSum[i] = suffixSum[i+1] + 1
        } else {
            suffixSum[i] = suffixSum[i+1]
        }
    }

    for i:=0; i<=n; i++ {
        penalty := prefixSum[i] + suffixSum[i]
        if penalty < minPenalty {
            minPenalty = penalty
            minHour = i
        }
        // else if penalty == minPenalty
    }
    return minHour
}
