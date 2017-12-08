#include <iostream>
#include "Kirjautuminen.h"
#include <string>
#include <fstream>
using namespace std;

int Valikko(){ // Käyttäjältä kysytään 
	int vastaus;
	cout << "Valikko: " << endl << "1.Tee käyttäjä" << endl << "2.Kirjaudu " << endl << "0. Lopeta" << endl;
	cin >> vastaus;
	return vastaus;
}

void Aloitus(int syotto) {// Käyttäjän syötön perusteella:
	switch (syotto){
		case 1: {
			LuoKayttaja(); // luodaan käyttäjä
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

void LuoKayttaja() { // funktio käyttäjän luomiselle
	kayttaja uusikayttaja;

	ofstream tiedosto;

	cout << "Anna käyttäjänimi: "; // käyttäjältä kysytään nimi
	cin >> ws >> uusikayttaja.nimi; // otetaan vain käyttäjän syöttö talteen
	cout << "Anna salasana: "; // käyttäjältä kysytään salasana
	cin >> ws >> uusikayttaja.salasana; // otetaan vain käyttäjän syöttä talteen
	tiedosto.open("kayttajat.txt"); // avataan kayttajat.txt
	tiedosto << uusikayttaja.nimi << " " << uusikayttaja.salasana << endl;//Kirjaa nimi ja salasana tiedostoon
	tiedosto.close(); // suljetaan kayttajat.txt
}



