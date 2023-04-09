'''
rep = int(input())
ls=list(map(int,input().split()))

ls.sort()
ls.reverse()
group_ls=[]

while True:
    if len(ls)== 0 or ls[0] == 1 :
        break
    new_group = ls[0:ls[0]]
    group_ls.append(new_group)
    ls=ls[ls[0]:]
    
print(len(group_ls)+len(ls))
'''
