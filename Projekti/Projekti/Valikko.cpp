#include <iostream>
#include "Kirjautuminen.h"
#include <string>
#include <fstream>
using namespace std;
int Valikko(int vastaus){ // K�ytt�j�lt� kysyt��n mit� tehd��n.
	cout << "Valikko: " << endl << "1.Tee k�ytt�j�" << endl << "2.Kirjaudu " << endl << "0. Lopeta" << endl;
	cin >> vastaus;
	return vastaus; // K�ytt�j�n sy�tt� palautetaan
}

void Aloitus() {// K�ytt�j�n sy�t�n perusteella:
	int kayttajansyotto = 10;

	do // do/while looppi kirjautumismenuun ja k�ytt�j�n luomiseen
	{
		kayttajansyotto = Valikko(kayttajansyotto); 
		switch (kayttajansyotto) {// k�ytt�j�n sy�t�n perusteella
		case 1: {
			LuoKayttaja(); // luodaan k�ytt�j�
			break;
		}
		case 2: {
			Kirjautuminen();//kirjaudu
			break;
		}
		}
	} while (kayttajansyotto != 0);
}

void LuoKayttaja() { // funktio k�ytt�j�n luomiselle
	kayttaja uusikayttaja;

	ofstream tiedosto;

	cout << "Anna k�ytt�j�nimi: "; // k�ytt�j�lt� kysyt��n nimi
	cin >> ws >> uusikayttaja.nimi; // otetaan vain k�ytt�j�n sy�tt� talteen
	cout << "Anna salasana: "; // k�ytt�j�lt� kysyt��n salasana
	cin >> ws >> uusikayttaja.salasana; // otetaan vain k�ytt�j�n sy�tt� talteen
	tiedosto.open("kayttajat.txt", ios_base::app); // avataan kayttajat.txt
	tiedosto << uusikayttaja.nimi << " " << uusikayttaja.salasana << endl;//Kirjaa nimi ja salasana tiedostoon
	tiedosto.close(); // suljetaan kayttajat.txt
}


void Kirjautuminen() { // funktio kirjautumiselle
	ifstream tiedosto;
	string rivi, tiedostonimi, tiedostosalasana;
	kayttaja user;

	cout << "Anna k�ytt�j�nimi: "; // k�ytt�j�lt� kysyt��n nimi
	cin >> ws >> user.nimi; // otetaan vain k�ytt�j�n sy�tt� talteen
	cout << "\nAnna salasana: "; // kysyt��n salasana
	cin >> ws >> user.salasana; // otetaan vain k�ytt�j�n sy�tt� talteen
	tiedosto.open("kayttajat.txt"); // avataan k�ytt�j�t.txt

	if (tiedosto.is_open()) {// jos tiedosto avataan onnistuneesti
		while (getline(tiedosto, rivi)) {// haetaan jokaiselta rivilt� tiedoston loppuun saakka
			if (tiedosto.eof())
			{
				cout << "K�ytt�j�tunnus tai salasana v��rin!";
				break;
			}
			tiedostonimi = rivi.substr(0, rivi.find(" ")); // haetaan jokaiselta rivilt� ennen v�li� (eli k�ytt�ji� etsit��n) oleva sana
			tiedostosalasana = rivi.substr(rivi.find(" ") + 1); // haetaan v�lin j�lkeen (eli salasanoja etsit��n) oleva sana
			if (user.nimi == tiedostonimi && user.salasana == tiedostosalasana) { // jos k�ytt�j�n sy�tt�m� nimi ja salasana matchaa, kirjaudutaan sis��n.
				cout << "hienoa kirjauduit sis��n" << endl; 
			}
		}
		tiedosto.close(); // tiedosto suljetaan
	}
	else{// jos jokin meni m�nk��n
		cout << "tiedostoa ei voitu avata" << endl;
	}
	tiedosto.close();// suljetaan k�ytt�j�t.txt
}



