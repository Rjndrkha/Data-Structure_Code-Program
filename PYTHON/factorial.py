def fun(a):
	fac=1
	for i in range(0,a):
		fac=fac*(i+1)
	return fac
def fun1(a):
	if a==1:
		return 1
	else:
		return a*fun1(a-1)

x=int(input())
d=fun(x)
e=fun1(x)
print("FACTORIAL BY ITERATION:\n",d)
print("FACTORIAL BY RECURSION:\n",e)
