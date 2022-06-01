row,col=map(int,input().split())

res=0

for i in range(row):
    data=list(map(int,input().split()))
    min_val=min(data)
    res=max(min_val,res)
    
    
print(res)
    
    
