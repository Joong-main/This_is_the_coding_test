N,M,K=map(int,input().split())

num_list=list(map(int,input().split()))

num_list.sort()
num_list.reverse()

print(num_list)

use_cnt=0
cnt=0
res=0

while cnt<M:
    if use_cnt>=K:
        res+= num_list[1]
        use_cnt=0
        cnt+=1
        
    else:
        res+=num_list[0]
        use_cnt+=1
        cnt+=1
        
        
print(res)
