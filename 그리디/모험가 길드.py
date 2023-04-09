#그룹수만 많이 나오면됨, 공포도가 높은 사람은 나중에 뽑을수록 유리해지는 그리디 문제
rep = int(input())
ls=list(map(int,input().split()))

ls.sort()
res=0
cnt=0

for i in ls:
    cnt+=1
    if cnt >= i:
        res+=1
        cnt=0
        
print(res)
