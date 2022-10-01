# find N number of samples in a binomial distribution of X number of coin flips and Y probability of heads with optional seed value (S)
import numpy as np
import random
from scipy.stats import binom
seed=int(input("Enter seed value: "))
np.random.seed(seed)

X = int(input("Enter number of coin flips: "))
Y = int(input("Enter probability of heads: "))
Distribution = np.random.binomial(X,Y)
print(Distribution)

print("Mean of the given Binomial Distribution is {:0.2f}".format(np.mean(Distribution)))
print("Variance of the given Binomial Distribution is {:0.2f}".format(np.var(Distribution)))
