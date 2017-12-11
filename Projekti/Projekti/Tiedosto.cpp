#include <iostream>
#include "Kirjautuminen.h"
#include <string>
#include <fstream>

using namespace std;

void Kirjautuminen() { // funktio kirjautumiselle
	ifstream tiedosto;
	string rivi, tiedostonimi, tiedostosalasana;
	kayttaja user;
	bool tiedostonloppu = false;


	cout << "Anna k�ytt�j�nimi: "; // k�ytt�j�lt� kysyt��n nimi
	cin >> ws >> user.nimi; // otetaan vain k�ytt�j�n sy�tt� talteen
	cout << "\nAnna salasana: "; // kysyt��n salasana
	cin >> ws >> user.salasana; // otetaan vain k�ytt�j�n sy�tt� talteen

	tiedosto.open("kayttajat.txt"); // avataan k�ytt�j�t.txt
	if (tiedosto.is_open()) {// jos tiedosto avataan onnistuneesti
		while (getline(tiedosto, rivi)) {// haetaan jokaiselta rivilt� tiedoston loppuun saakka
			tiedostonimi = rivi.substr(0, rivi.find(" ")); // haetaan jokaiselta rivilt� ennen v�li� (eli k�ytt�ji� etsit��n) oleva sana
			tiedostosalasana = rivi.substr(rivi.find(" ") + 1); // haetaan v�lin j�lkeen (eli salasanoja etsit��n) oleva sana
			if (user.nimi == tiedostonimi && user.salasana == tiedostosalasana) { // jos k�ytt�j�n sy�tt�m� nimi ja salasana matchaa, kirjaudutaan sis��n.
				cout << "hienoa kirjauduit sis��n" << endl;
				tiedostonloppu = true; // asetetaan tiedostonloppu trueksi, niin ei tule virheilmoitusta v��r�st� k�ytt�j�st� ja salasanasta
			}
		}
	}
	else {// jos jokin meni m�nk��n tiedoston avaamisessa
		cout << "tiedostoa ei voitu avata" << endl;
	}

	if (tiedostonloppu == false) // jos tiedostonloppu-boolean ei muutu annetaan virheilmoitus v��r�st� salasanasta ja k�ytt�j�st�
	{
		cout << "K�ytt�j�tunnus tai salasana v��rin!" << endl; // virheilmoitus
	}

	tiedosto.close();// suljetaan k�ytt�j�t.txt
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
