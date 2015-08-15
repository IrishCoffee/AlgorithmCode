def find_same_prefix(tmpA,tmpB):
	if len(tmpA) == 1:
		return True
	for i in range(0,len(tmpA) - 1):
		if tmpA[i] != tmpB[i] :
			return False
	return True

def init():
	for i in range(0,iterm_size):
		count = 0
		for j in range(0,trans_size):
			if transcation[j][i] > 0: count+= transcation[j][i]
		if count >= support_threshold: 
			tmp = [i]
			ans.append(tmp)

def join_step(begin,end):
	for i in range(begin,end):
		for j in range(i+1, end):
			tmpA = ans[i]
			tmpB = ans[j]
			if find_same_prefix(tmpA,tmpB):
				tmp = tmpA[:]
				tmp.append(tmpB[len(tmpB) - 1])
				ans.append(tmp)

def prune_step(begin,end):
	global smaller
	for i in range(begin,end):
		count = 0
		for j in range(0,trans_size):
			tmp_list = []
			for k in range(0,len(ans[i])):
				tmp_list.append(transcation[j][ans[i][k]])
			tmp = min(tmp_list)
			count += tmp 
		if count < support_threshold:
			smaller.append(i)

iterm_name = "ABCDEFGHIJKLMN"
text_file = open("text_file","r")
trans_size = int(text_file.readline())
iterm_size = int(text_file.readline())
support_threshold = int(text_file.readline())
transcation = [ ([0] * iterm_size) for i in range(trans_size) ]
ans = []

for i in range(0,trans_size):
	for j in range(0,iterm_size):
		transcation[i][j] = int(text_file.readline())
for i in range(0,trans_size):
	for j in range(0,iterm_size):
		print transcation[i][j],
	print ""
init()
flag1 = 0
flag2 = len(ans)
while True:
	join_step(flag1,flag2)
	if flag2 == len(ans):break
	flag1 = flag2
	flag2 = len(ans)
	smaller = []
	prune_step(flag1,flag2)
	flag2 -= len(smaller)
	for i in range(0,len(smaller)):
		smaller[i] -= i ###Good Idea!
		del ans[smaller[i]]

for i in range(0,len(ans)):
	print "Itermset",i,":"," {",
	for j in range(0,len(ans[i])):
		print iterm_name[ans[i][j]],
		if j != len(ans[i]) - 1:
			print ",",
	print "}"


