


tria: teste_matriz_triangular.cpp MatInferior.h MatSuperior.h MatSuperior.cpp MatInferior.cpp
	g++ -o tria teste_matriz_triangular.cpp MatInferior.cpp MatSuperior.cpp


sym: teste_matriz_simetrica.cpp MatSimetrica.h MatSimetrica.cpp
	g++ -o sym teste_matriz_simetrica.cpp MatSimetrica.cpp


asym: teste_matriz_anti.cpp MatAntiSimetrica.h MatAntiSimetrica.cpp
	g++ -o asym teste_matriz_anti.cpp MatAntiSimetrica.cpp

clean:
	rm -f tria *.o

.PHONY: clean tria


run: tria sym
	./sym
	./tria