import numpy as np
init_input_size = 8
top_k = [init_input_size,3,2,1]
size = [0,5,4,3]

#generate the initial input data
alphas = 2 ** np.random.randint(0, 4, size=(1,init_input_size))
np.random.seed(1234)
d = np.empty(alphas.shape)
d[0] = np.random.dirichlet(alphas[0])
data = zip(alphas[0],d[0])
print "Input data"
for i in range(0,8):
	print data[i][0],
	print format(data[i][1],'.2')

#1st component
print "Output of Component 1"
output1 = []
for i in range (0,init_input_size):
	#for each input, gegerate the output of size sita
	alphas = 2 ** np.random.randint(0,4,size=(1,size[1]))
	np.random.seed(1234)
	d = np.empty(alphas.shape)
	d[0] = np.random.dirichlet(alphas[0])

	tmp = []
	#process the score
	for j in range (0,size[1]):
		d[0][j] *= data[i][1]
		tmp.append(data[i][0])
	output1 += list(zip(tmp,alphas[0],d[0]))
	for j in range (size[1] * i,size[1] * (i + 1)):
		print "I0 ", output1[j][0], "I1 ",output1[j][1],
		print format(output1[j][2],'.2')
	print " "

output1.sort(key=lambda x:x[2],reverse = True)
print "top K of Component 1"
for i in range (0,top_k[1]):
	print "I0 ", output1[i][0], "I1 ",output1[i][1],
	print format(output1[i][2],'.2')
print "\n","Output of Component 2"
#2nd component
output2 = []
for i in range (0,top_k[1]):
	#for each input, gegerate the output of size sita
	alphas = 2 ** np.random.randint(0,4,size=(1,size[2]))
	np.random.seed(1234)
	d = np.empty(alphas.shape)
	d[0] = np.random.dirichlet(alphas[0])
	tmp = []
	#process the score
	for j in range (0,size[2]):
		d[0][j] *= output1[i][2]
		tmp.append((output1[i][0],output1[i][1]))
	output2 += list(zip(tmp,alphas[0],d[0]))
	#print "output2 \n",output2
	for j in range (size[2] * i,size[2] * (i + 1)):
		print "I0 ", output2[j][0][0], "I1 ",output2[j][0][1],"I2 ",output2[j][1],
		print format(output2[j][2],'.2')
	print " "

output2.sort(key=lambda x:x[2],reverse = True)
print "top K of Pipeline 2"
for i in range (0,top_k[2]):
	print "I0 ", output2[i][0][0], "I1 ",output2[i][0][1],"I3 ",output2[i][1],
	print format(output2[i][2],'.2')

#3rd component
print "\n","Output of Component 3"
output3 = []
for i in range (0,top_k[2]):
	#for each input, gegerate the output of size sita
	alphas = 2 ** np.random.randint(0,4,size=(1,size[3]))
	np.random.seed(1234)
	d = np.empty(alphas.shape)
	d[0] = np.random.dirichlet(alphas[0])
	tmp = []
	#process the score
	for j in range (0,size[3]):
		d[0][j] *= output2[i][2]
		tmp.append((output2[i][0][0],output2[i][0][1],output2[i][1]))
	output3 += list(zip(tmp,alphas[0],d[0]))
	for j in range (size[3] * i,size[3] * (i + 1)):
		print "I0 ", output3[j][0][0], "I1 ",output3[j][0][1],"I2 ",output3[j][0][2],"I3 ",output3[j][1],
		print format(output3[j][2],'.2')
	print " "

output3.sort(key=lambda x:x[2],reverse = True)
print "top K of Component 3"
for j in range (0,top_k[3]):
	print "I0 ", output3[i][0][0], "I1 ",output3[i][0][1],"I2 ",output3[i][0][2],"I3 ",output3[i][1],
	print format(output3[i][2],'.2')
