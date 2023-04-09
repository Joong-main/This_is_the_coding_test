#왕실의 나이트
#8 by 8
#수평 두칸 수직 한칸
#수직 두칸 수평 한칸
cnt=0
max_row=7
max_col=7

pos_info=input()
row_info=pos_info[1]
col_info=pos_info[0]

print("row info = {0}".format(row_info))
print("col info = {0}".format(col_info))

row_index=int(row_info)-1


if col_info == 'a':
    col_index=0
elif col_info =='b':
    col_index=1
elif col_info =='c':
    col_index=2
elif col_info =='d':
    col_index=3
elif col_info =='e':
    col_index=4
elif col_info =='f':
    col_index=5
elif col_info =='g':
    col_index=6
elif col_info =='h':
    col_index=7
else:
    print("Wrong input!")
    
print("row: {0}, col: {1}".format(row_index,col_index))

#cnt case part

#우로 두칸 이동 이후 아래 위로 1칸씩
if col_index+2 <=max_col:
    if row_index+1<=max_row:
        cnt+=1
    if row_index-1 >=0:
        cnt+=1
#좌로 두칸 이동 이후 아래 위로 1칸씩
if col_index-2 >=0:
    if row_index+1 <= max_row:
        cnt+=1
    if row_index-1 >=0:
        cnt+=1
#하으로 두칸 이동 이후 오른쪽 왼쪽 1칸씩
if row_index+2<= max_row:
    if col_index+1<= max_col:
        cnt+=1
    if col_index-1 >=0:
        cnt+=1
#상으로 두칸 이동 이후 오른쪽 왼쪽 1칸씩
if row_index-2>= 0:
    if col_index+1<= max_col:
        cnt+=1
    if col_index-1 >=0:
        cnt+=1
print(cnt)
