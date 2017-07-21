import numpy as np 
import matplotlib.pyplot as plt
import matplotlib.animation as animation


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

it_30=int(30/dt)
it_60=int(60/dt)

def evolucion(t_max):

	barrera = np.ones((302,302))
	barrera[200][0:130]=0
	barrera[200][170:302]=0

	for i in range (1,300):

		for j in range (1,300):
		
			u_futuro[i][j]= (r/2*(u_inicial[i+1][j]-u_inicial[i-1][j]))+(r/2*(u_inicial[i][j+1]-u_inicial[i][j-1]))+u_inicial[i][j]

	m_tiempo.append(u_inicial)

	u_presente=u_futuro.copy()*barrera

	u_pasado=u_inicial.copy()

	m_tiempo.append(u_presente)

	for k in range(1,t_max):
		for i in range(1,300):
			for j in range(1,300):
			
				u_futuro[i][j]= ((u_presente[i+1][j]-2*u_presente[i][j]+u_presente[i-1][j])*(r**2))+((r**2)*(u_presente[i][j+1]-2*u_presente[i][j]+u_presente[i][j-1]))+2*u_presente[i][j]-u_pasado[i][j]

		
		u_pasado=u_presente.copy()
		u_presente=u_futuro.copy()*barrera
		m_tiempo.append(u_presente)

	return m_tiempo




f_anim=evolucion(it_60)
t_30=f_anim[it_30]
t_60=f_anim[it_60]

plt.imshow(t_30, cmap="gist_gray")
plt.title("Evolucion de la onda t=30s")
plt.savefig("Onda_30.png")
plt.close()

plt.imshow(t_60, cmap="gist_gray")
plt.title("Evolucion de la onda t=60s")
plt.savefig("Onda_60.png")
plt.close()

fig=plt.figure(figsize=(15,15))
cubeta=plt.imshow(f_anim[0],cmap="flag")


nueva_lista=[]

for i in range(len(f_anim)):

	if (i%2==0):
		nueva_lista.append(f_anim[i])

		i+=1
	else:	
		i+=1

def init(i):

	datos=nueva_lista[i]
	cubeta.set_array(datos),
	return cubeta,

ani=animation.FuncAnimation(fig,init, np.arange(0,len(nueva_lista)), interval=200)
ani.save('Onda.mp4')



