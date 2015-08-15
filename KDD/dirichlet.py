def getComponentScore(alpha,inputs,outputNum,k,seed):
	alphas = [alpha for i in range(outputNum)]
	np.ramdon.seed(seed)
	results = []
	for inp in inputs:
		outputs = np.random.dirichlet(alphas)
		for output in outputs:
			result.append(inp*output)
	results.sort(reverse = True)
	return results[0:k]

def experiment(alpha,seed,outputNumList,kList,componentNum):
	output = [100]
	for i in range(componentNum):
		output = getComponentScore(alpha,output,outputNumList[i],kList[i],seed)
	return out
