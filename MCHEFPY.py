# cook your code here
test = input()
while test:
    test -= 1
    n,k,m = map(int,raw_input().split())
    
    arr = map(int,raw_input().split())
    sum1 = 0
    for i in arr:
        sum1 += i
    leng = [999 for _ in xrange(n)]
    #arrcos = zip(arr,leng)
    while m:
        m -= 1
        x,y,c = map(int,raw_input().split())
        for i in xrange(x-1,y):
            if(leng[i]>c):
                leng[i]=c
    
    arrcos = zip(arr,leng)    
    arrcos.sort(key = lambda t:t[0])
    
    for i in xrange(len(arrcos)):
        if arrcos[i][0]>=0:
            del(arrcos[i:])
            break
    lo=i
    used = [0 for _ in xrange(lo)]
    #print arrcos
    
    if lo-1>0:
        dp = [[0 for _ in xrange(k+1)] for _ in xrange(lo+1)]
        for i in xrange(lo):
            for j in xrange(k+1):
                if i==0 or j==0:
                    dp[i][j] = 0
                elif arrcos[i-1][1]<=j:
                    dp[i][j] = min(arrcos[i-1][0]+dp[i-1][j-arrcos[i-1][1]],dp[i-1][j])
                else:
                    dp[i][j] = dp[i-1][j]
        
        # print dp[i]+j
    print sum1-dp[lo-1][k]
    
        