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

visited_dfs=[0]*(n+1)

def dfs(v):
    visited_dfs[v]=1 #방문 노드는 리스트에서 방문 처리
    print(v,end=' ')
    
    for i in range(1,n+1): #1 번 노드 부터 끝번 노드 까지 순회
        if(visited_dfs[i] == 0 and matrix[v][i] == 1): # 만일 해당 노드가 미방문 상태이면서 노드간 엣지가 존재하면 
            dfs(i) #해당 노드 방문 아니면 이전 방문 노드로 돌아가는 재귀식


dfs(v)
