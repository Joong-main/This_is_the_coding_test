n,m=map(int,input().split())
x,y,direction=map(int,input().split())

#방문 여부 체크용 행렬
d=[]
for i in range(n):
    d.append([0]*m)
    
d[x][y]=1


# 맵 전체 정보
matrix=[]
for i in range(n):
    row = list(map(int,input().split()))
    matrix.append(row)
    
dx=[-1,0,1,0]
dy=[0,1,0,-1]

def turn_left():
    global direction
    direction -= 1
    if direction == -1:
        direction =3
        
visit_cnt = 1
turn_cnt=0

while True:
    turn_left()
    nx=x+dx[direction]
    ny=y+dy[direction]
    
    if matrix[nx][ny] == 0 and d[nx][ny] == 0:
        d[nx][ny] = 1
        x=nx
        y=ny
        
        visit_cnt+=1
        turn_cnt=0
        continue
    
    else:
        turn_cnt +=1
        
        if turn_cnt ==4:
            nx=x-dx[direction]
            ny=y-dy[direction]
            if matrix[nx][ny] == 0:
                x=nx
                y=ny
                
            else:
                break
            turn_cnt=0
            
print(visit_cnt)
    
