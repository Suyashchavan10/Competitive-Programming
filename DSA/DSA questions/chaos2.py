import math
import matplotlib.pyplot as plt
def logistic(r, x0, n):
    x = x0
    for i in range(n):
        yield x
        x = r*x*(1-x)

plt.xlabel("n")
plt.ylabel("x_n")
r = 2.999
plt.title(f"r = {r}")
plt.plot(range(100), list(logistic(r, 0.2, 100)))
plt.show()
