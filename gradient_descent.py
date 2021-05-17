# для нахождения производной
from scipy.misc import derivative
from time import  time
import math

def f(x):
    return x**(6)+77*(x-2)**(2)
xn = 2.0
yn = f(xn)

Y=0.0

#
# шаг ГС (произвольный подибраем)
step = 0.01
eps =0.001
# по формуле градиентного спуска получаем все значения x y
start = time()
for i in range(10000):
    st = step*derivative(f, xn)
    if abs(st) < eps:
        print(st)
        print("stopped "+str(i))
        break
    xn = xn - step
    yn = f(xn)
    Y = yn
finish = time()

print("Время работы алгоритма "+str(finish-start))
print(xn)
print(Y)

