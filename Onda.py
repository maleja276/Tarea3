import numpy as np 
import matplotlib.pyplot as plt 

#Solucionar la euacion de Onda en dos dimensiones 

c = 1.
lados= 30.
prof= 2.

#t_max=60
a=0
b=30
n=302

x=np.linspace(a,b,n)


r=0.5

dx=x[1]-x[0]


dt= r*dx

u_inicial=np.zeros([n,n])
u_inicial[100][151]=-0.5

u_futuro=np.zeros([n,n])
u_presente=np.zeros([n,n])
u_pasado=np.zeros([n,n])
m_tiempo=[]

def evolucion(t_max):
	for i in range (1,300):

		for j in range (1,300):
		
			u_futuro[i][j]= (r/2*(u_inicial[i+1][j]-u_inicial[i-1][j]))+(r/2*(u_inicial[i][j+1]-u_inicial[i][j-1]))+u_inicial[i][j]

	m_tiempo.append(u_inicial)

	u_presente=u_futuro.copy()

	u_pasado=u_inicial.copy()

	m_tiempo.append(u_presente)

	for k in range(1,t_max):
		for i in range(1,300):
			for j in range(1,300):
			
				u_futuro[i][j]= ((u_presente[i+1][j]-2*u_presente[i][j]+u_presente[i-1][j])*(r**2))+((r**2)*(u_presente[i][j+1]-2*u_presente[i][j]+u_presente[i][j-1]))+2*u_presente[i][j]-u_pasado[i][j]

		u_pasado=u_presente.copy()
		u_presente=u_futuro.copy()
		m_tiempo.append(u_presente)


	return u_presente, m_tiempo

plt.imshow(evolucion(30)[0], cmap="binary")
plt.title("Evolucion de la onda t=30s")
plt.savefig("Onda_30.pdf")
plt.close()

plt.imshow(evolucion(60)[0], cmap="binary")
plt.title("Evolucion de la onda t=60s")
plt.savefig("Onda_60.pdf")
plt.close()







