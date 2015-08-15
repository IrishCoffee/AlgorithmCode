import numpy as np
alpha = 1
alphas = [alpha for i in range(5)]
alphas = [0.2,0.3,0.4,0.1]
print alphas
seed = 5
np.random.seed(seed)
outputs = np.random.dirichlet(alphas)
print outputs
outputs = np.random.dirichlet(alphas)
print outputs
outputs = np.random.dirichlet(alphas)
print outputs
outputs = np.random.dirichlet(alphas)
print outputs
outputs = np.random.dirichlet(alphas)
