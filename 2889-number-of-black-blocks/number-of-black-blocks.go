func countBlackBlocks(m int, n int, coordinates [][]int) []int64 {

    blockCount := make(map[[2]int]int)
    res := make([]int64, 5)

    dir := [][]int{
        {0, 0},
        {0, -1},
        {-1, 0},
        {-1, -1},
    }

    for _, cd := range coordinates {
        r := cd[0]
        c := cd[1]

        for i:=0; i<4; i++ {
            nrow := r + dir[i][0]
            ncol := c + dir[i][1]

            if nrow >= 0 && nrow+1 < m && ncol >= 0 && ncol+1 < n {
                blockCount[[2]int{nrow, ncol}]++;
            }
        }
    }

    res[0] = int64((n-1)*(m-1))

    for _ , it:= range blockCount {
        res[it]++;
        res[0]--;
    }
    return res
}