import math
def Tsyn(t1,t2):
    return (t1*t2)/(abs(t2-t1))
def Tsialkovskogo(m1,m2,I,m0,N):
    return abs(sum(I for i in range(1,N))*math.log((m0+sum(m1 for i in range(1,N)))/(m0+m2-m1+sum(m1 for i in range(1,N)))))
def VsemTyag(m1,m2,r):
    g=6.6743 *10**(-11)
    return (g*m1*m2)/(r**2)
def kosmv1(M,R):
    g=6.6743 *10**(-11)
    a=sqrt((g*M)/R)
    return a;
def kosmv2(M,R):
    return kosmv1*sqrt(2)
def massa_ot_vremeni(M,k,T,M1,t):
    k=(M-M1)/T
    return M-k*t
def delta_V(b,d,p0,GM,e,r0,H,Ei):
    b=0.004892379 
    d=0.2
    e=2.71828182846
    return -sqrt(b*d*p0*GM)*(e**(r0/(2*H)))*Ei*(-r0/(2*H))
print(Tsyn(1,2))
print(Tsialkovskogo(1,2,3,4,5))
print(VsemTyag(1,2,3))
print(kosmv1(1,2))
print(kosmv2(1,2))
print(massa_ot_vremeni(1,2,3,4,5))
print(delta_V(1,2,3,4,5,6,7,8))
