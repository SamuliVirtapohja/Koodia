#include <iostream>
#include "Kirjautuminen.h"
#include <string>
#include <fstream>
using namespace std;

int Valikko(){ // K�ytt�j�lt� kysyt��n 
	int vastaus;
	cout << "Valikko: " << endl << "1.Tee k�ytt�j�" << endl << "2.Kirjaudu " << endl << "0. Lopeta" << endl;
	cin >> vastaus;
	return vastaus;
}

void Aloitus(int syotto) {// K�ytt�j�n sy�t�n perusteella:
	switch (syotto){
		case 1: {
			LuoKayttaja(); // luodaan k�ytt�j�
		}
		case 2: {
			//kirjaudu
		}
		case 0: {
			break;
		}
	default:
		cout << "joku meni pieleen";
		break;
	}
}

void LuoKayttaja() { // funktio k�ytt�j�n luomiselle
	kayttaja uusikayttaja;

	ofstream tiedosto;

	cout << "Anna k�ytt�j�nimi: "; // k�ytt�j�lt� kysyt��n nimi
	cin >> ws >> uusikayttaja.nimi; // otetaan vain k�ytt�j�n sy�tt� talteen
	cout << "Anna salasana: "; // k�ytt�j�lt� kysyt��n salasana
	cin >> ws >> uusikayttaja.salasana; // otetaan vain k�ytt�j�n sy�tt� talteen
	tiedosto.open("kayttajat.txt"); // avataan kayttajat.txt
	tiedosto << uusikayttaja.nimi << " " << uusikayttaja.salasana << endl;//Kirjaa nimi ja salasana tiedostoon
	tiedosto.close(); // suljetaan kayttajat.txt
}



