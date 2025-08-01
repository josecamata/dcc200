


tria: teste_matriz_triangular.cpp MatInferior.h MatSuperior.h MatSuperior.cpp MatInferior.cpp
	g++ -o tria teste_matriz_triangular.cpp MatInferior.cpp MatSuperior.cpp


sym: teste_matriz_simetrica.cpp MatSimetrica.h MatSimetrica.cpp
	g++ -o sym teste_matriz_simetrica.cpp MatSimetrica.cpp


asym: teste_matriz_anti.cpp MatAntiSimetrica.h MatAntiSimetrica.cpp
	g++ -o asym teste_matriz_anti.cpp MatAntiSimetrica.cpp

coo: teste_matcoo.cpp MatCOO.h MatCOO.cpp
	g++ -o coo teste_matcoo.cpp MatCOO.cpp

clean:
	rm -f tria *.o sym asym coo

.PHONY: clean tria sym asym

