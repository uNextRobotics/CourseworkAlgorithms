метод перебора

import math

def func(x):
	return math.sin(x) - 1 / x

h = 0.0001
a, b = map(float, input().split())
xm = a
m = func(xm)
i=1
while(h * i + a < b):
	x = h * i + a
	f = func(x)
	if (f < m):
		m = f
		xm = x
	i+=1
print("minimum point: "+str(xm))
print("minimum value: "+str(m))

метод хорд

import math

def func(x):
	return pow(math.e, x) - 2 * x*x

def dfunc(x):
	return pow(math.e, x) - 4 * x


def find(a, b, eps):
	while (math.fabs(b - a) > eps):
		a = b - (b - a) * dfunc(b) / (dfunc(b) - dfunc(a))
		b = a - (a - b) * dfunc(a) / (dfunc(a) - dfunc(b))
	return b
	
eps = 0.0001
a, b = map(float, input().split())
xm=find(a, b, eps)
m = func(xm)
print("minimum point: "+str(xm))
print("minimum value: "+str(m))	