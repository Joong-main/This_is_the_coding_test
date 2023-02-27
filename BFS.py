from collections import deque

n,m,v = list(map(int,input().split()))

#매트릭스 초기화
matrix=[[0]*(n+1) for i in range(n+1)]

visited_bfs=[0]*(n+1)

#매트릭스 생성
# 연결 노드:1 , 미연결 노드:0
for i in range(m):
    a,b = map(int,input().split())
    matrix[a][b]=1 
    matrix[b][a]=1

def bfs(v):
    queue=deque([v]) #최초 방문노드 queue 삽입
    visited_bfs[v]=1 #최초 방문 노드 방문처리
    
    while queue: #큐에 element 있는 동안에 큐에서 leftpop
        v=queue.popleft() #큐 맨앞에 있는 노드 뽑기
        print(v, end=' ')
        
        for i in range(1,n+1): # 첫번 노드 부터 끝번 노드까지 반복문 돌리기 (노드간 엣지 존재 여부 확인 )
            if(visited_bfs[i] == 0 and matrix[v][i] == 1): #미방문 노드 이면서 연결된 노드 라면 
                queue.append(i) # 큐에 추가하고 방문으로 처리 하기
                visited_bfs[i]=1

bfs(v)
