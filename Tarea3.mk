Resultados_hw3.pdf : Resultados_hw3.tex  Onda_30.png Onda_60.png Orbitas.png
	pdflatex Resultados_hw3.tex

Onda_30.png : Onda.py
	python Onda.py 

Onda_60.png : Onda.py
	python Onda.py

Orbitas.png : Plots_Planetas.py
	python  Plots_Planetas.py

Plots_Planetas.py : posiciones.txt Planetas.x
	./Planetas.x > .txt 

Planetas.x : Planetas.c
	cc  Planetas.c -o Planetas.x -lm

