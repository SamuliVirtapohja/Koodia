#include <iostream>
#include "Kirjautuminen.h"
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void Kirjautuminen() { // funktio kirjautumiselle
	ifstream tiedosto;
	string rivi, tiedostonimi, tiedostosalasana;
	kayttaja user;
	bool tiedostonloppu = false;
	int hashattysalasana, verrattavasalasana;
	char* salasanamuunnos;

	cout << "Anna k�ytt�j�nimi: "; // k�ytt�j�lt� kysyt��n nimi
	cin >> ws >> user.nimi; // otetaan vain k�ytt�j�n sy�tt� talteen
	cout << "\nAnna salasana: "; // kysyt��n salasana
	cin >> ws >> user.salasana; // otetaan vain k�ytt�j�n sy�tt� talteen


	salasanamuunnos = user.salasana;// hashataan sy�tt�j�n input
	hashattysalasana = HashattySyotto(salasanamuunnos); 

	tiedosto.open("kayttajat.txt"); // avataan k�ytt�j�t.txt
	if (tiedosto.is_open()) {// jos tiedosto avataan onnistuneesti
		while (getline(tiedosto, rivi)) {// haetaan jokaiselta rivilt� tiedoston loppuun saakka
			tiedostonimi = rivi.substr(0, rivi.find(" ")); // haetaan jokaiselta rivilt� ennen v�li� (eli k�ytt�ji� etsit��n) oleva sana
			tiedostosalasana = rivi.substr(rivi.find(" ") + 1); // haetaan v�lin j�lkeen (eli salasanoja etsit��n) oleva sana
			
			stringstream salasanavertaus(tiedostosalasana);// muutetaan stringi int muuttujaksi jota verrataan tiedostossa olevaan salasanaan.
			salasanavertaus >> verrattavasalasana;

			if (user.nimi == tiedostonimi && hashattysalasana == verrattavasalasana) { // jos k�ytt�j�n sy�tt�m� nimi ja salasana matchaa, kirjaudutaan sis��n.
				cout << "hienoa kirjauduit sis��n" << endl;
				tiedostonloppu = true; // asetetaan tiedostonloppu trueksi, niin ei tule virheilmoitusta v��r�st� k�ytt�j�st� ja salasanasta
			}
		}
	}else {// jos jokin meni m�nk��n tiedoston avaamisessa
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
	int hashattysalasana; // hashatyn salasanan palautus, mik� menee tiedostoon
	char* salasanamuunnos; // k�ytet��n osoitinta salasanamuunnoksessa
	ofstream tiedosto;

	cout << "Anna k�ytt�j�nimi: "; // k�ytt�j�lt� kysyt��n nimi
	cin >> ws >> uusikayttaja.nimi; // otetaan vain k�ytt�j�n sy�tt� talteen
	cout << "Anna salasana: "; // k�ytt�j�lt� kysyt��n salasana
	cin >> ws >> uusikayttaja.salasana; // otetaan vain k�ytt�j�n sy�tt� talteen
	salasanamuunnos = uusikayttaja.salasana;
	hashattysalasana = HashattySyotto(salasanamuunnos); // muutetaan salasana numeroiksi ihmiselle lukemattomaan muotoon

	tiedosto.open("kayttajat.txt", ios_base::app); // avataan kayttajat.txt
	tiedosto << uusikayttaja.nimi << " " << hashattysalasana << endl;//Kirjaa nimi ja salasana tiedostoon
	tiedosto.close(); // suljetaan kayttajat.txt
}


int HyvaksyttySyotto(int syotto) {// funktio k�ytt�j�n sy�t�n korjaamiselle valikossa
	while (cin.fail()) {// aina kun k�ytt�j�n sy�tt� ei toimi ajetaan uudestaan
		cin.clear(); // tyhjennet��n k�ytt�j�n sy�tt�
		cin.ignore(256, '\n'); // ei v�lit� ennen v�lily�nti�
		cin >> syotto;
	}
	return syotto; // palautetaan hyv�ksytty sy�tt�
}

int HashattySyotto(char* syotto) {// funktio salasanan hashaamiselle
	int i = 0, kerroin = 5; // kerroin on hashin kertominen
	long hash = 0;
	for (i = 0; i < strlen(syotto); i++) {
		hash = (hash + syotto[i]) * kerroin; // asetetaan k�ytt�j�n sy�t�st� jokainen kirjain 
	}
	return hash; // palautetaan lopuksi numerot
}