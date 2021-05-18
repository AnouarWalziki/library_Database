prog : main.cpp mediath.cpp CD.cpp Livre.cpp Revue.cpp DVD.cpp VHS.cpp Ressource.cpp RessourceNum.cpp
	g++ -std=c++14 main.cpp mediath.cpp CD.cpp Livre.cpp  Revue.cpp DVD.cpp VHS.cpp Ressource.cpp RessourceNum.cpp Login.cpp -o prog 
	

clean:
	rm -rf *.o
	