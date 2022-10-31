import math
from re import X
import matplotlib.pyplot as plt
#bifurcation diagram
#generator function on the equation x(n+1)  = r*x(n)*(1-x(n))
def logistic(r, x0, n):
    x = x0
    for i in range(n):
        yield x
        x = r*x*(1-x)

def plotGraph(r, x0, n):
    rs = [r for i in range(n)]
    vals = list(logistic(r, x0, n))
    vals = vals[n-64:]
    rs = rs[n-64:]
    plt.scatter(rs, vals, c="#000000", s= 0.2)

delta = 1e-3
r = 1
while(r <= 4):
    plotGraph(r, 0.2, 600)
    r += delta

plt.show()
