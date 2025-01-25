def findPeakGrid(g: [[int]]) -> [int]:
    n = len(g)
    m = len(g[0])
    low = 0
    high = m -1
    # print(g,n,m)
    while(high>=low):
        mid = int((high+low)/2)
        maxRowIndex = maxInColum(g,n,m,mid)
        if(mid - 1 >= 0):
            left = g[maxRowIndex][mid - 1]
        else:
            left = -1
        if(mid + 1 < m):
            right = g[maxRowIndex][mid + 1]
        else:
            right = -1
        if(g[maxRowIndex][mid]> left and g[maxRowIndex][mid]> right):
            return maxRowIndex,mid
        elif(left>g[maxRowIndex][mid]):
            high = mid - 1
        else:
            low = mid + 1
    return -1,-1


def maxInColum(mat,n,m,col):
    maxEle=-1
    index=-1
    for i in range(n):
        if(mat[i][col]>maxEle):
            maxEle=mat[i][col]
            index = i 
    # print(maxEle,index,"max in col")
    return index