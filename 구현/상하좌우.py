N=int(input())

orders=list(input().split())

init_pos=[1,1] #[row_val,col_val]

def L_fun():
  if init_pos[1]-1>=1 and init_pos[1]-1<=N:
    init_pos[1]-=1
def R_fun():
  if init_pos[1]+1>=1 and init_pos[1]+1<=N:
    init_pos[1]+=1
def U_fun():
  if init_pos[0]-1>=1 and init_pos[0]-1<=N:
    init_pos[0]-=1
def D_fun():
  if init_pos[0]+1>=1 and init_pos[0]+1<=N:
    init_pos[0]+=1

#print(orders)

for order in orders:
  if order =='L':
    L_fun()
    
  elif order =='R':
    R_fun()
    
  elif order =='U':
    U_fun()
    
  elif order =='D':
    D_fun()
    
  else:
    print("error")
    break
print("{0} {1}".format(init_pos[0],init_pos[1]))
