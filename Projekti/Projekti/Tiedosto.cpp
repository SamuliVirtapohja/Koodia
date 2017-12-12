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

	cout << "Anna käyttäjänimi: "; // käyttäjältä kysytään nimi
	cin >> ws >> user.nimi; // otetaan vain käyttäjän syöttö talteen
	cout << "\nAnna salasana: "; // kysytään salasana
	cin >> ws >> user.salasana; // otetaan vain käyttäjän syöttö talteen


	salasanamuunnos = user.salasana;// hashataan syöttäjän input
	hashattysalasana = HashattySyotto(salasanamuunnos); 

	tiedosto.open("kayttajat.txt"); // avataan käyttäjät.txt
	if (tiedosto.is_open()) {// jos tiedosto avataan onnistuneesti
		while (getline(tiedosto, rivi)) {// haetaan jokaiselta riviltä tiedoston loppuun saakka
			tiedostonimi = rivi.substr(0, rivi.find(" ")); // haetaan jokaiselta riviltä ennen väliä (eli käyttäjiä etsitään) oleva sana
			tiedostosalasana = rivi.substr(rivi.find(" ") + 1); // haetaan välin jälkeen (eli salasanoja etsitään) oleva sana
			
			stringstream salasanavertaus(tiedostosalasana);// muutetaan stringi int muuttujaksi jota verrataan tiedostossa olevaan salasanaan.
			salasanavertaus >> verrattavasalasana;

			if (user.nimi == tiedostonimi && hashattysalasana == verrattavasalasana) { // jos käyttäjän syöttämä nimi ja salasana matchaa, kirjaudutaan sisään.
				cout << "hienoa kirjauduit sisään" << endl;
				tiedostonloppu = true; // asetetaan tiedostonloppu trueksi, niin ei tule virheilmoitusta väärästä käyttäjästä ja salasanasta
			}
		}
	}else {// jos jokin meni mönkään tiedoston avaamisessa
		cout << "tiedostoa ei voitu avata" << endl;
	}

	if (tiedostonloppu == false) // jos tiedostonloppu-boolean ei muutu annetaan virheilmoitus väärästä salasanasta ja käyttäjästä
	{
		cout << "Käyttäjätunnus tai salasana väärin!" << endl; // virheilmoitus
	}
	tiedosto.close();// suljetaan käyttäjät.txt
}

void LuoKayttaja() { // funktio käyttäjän luomiselle
	kayttaja uusikayttaja;
	int hashattysalasana; // hashatyn salasanan palautus, mikä menee tiedostoon
	char* salasanamuunnos; // käytetään osoitinta salasanamuunnoksessa
	ofstream tiedosto;

	cout << "Anna käyttäjänimi: "; // käyttäjältä kysytään nimi
	cin >> ws >> uusikayttaja.nimi; // otetaan vain käyttäjän syöttö talteen
	cout << "Anna salasana: "; // käyttäjältä kysytään salasana
	cin >> ws >> uusikayttaja.salasana; // otetaan vain käyttäjän syöttö talteen
	salasanamuunnos = uusikayttaja.salasana;
	hashattysalasana = HashattySyotto(salasanamuunnos); // muutetaan salasana numeroiksi ihmiselle lukemattomaan muotoon

	tiedosto.open("kayttajat.txt", ios_base::app); // avataan kayttajat.txt
	tiedosto << uusikayttaja.nimi << " " << hashattysalasana << endl;//Kirjaa nimi ja salasana tiedostoon
	tiedosto.close(); // suljetaan kayttajat.txt
}


int HyvaksyttySyotto(int syotto) {// funktio käyttäjän syötön korjaamiselle valikossa
	while (cin.fail()) {// aina kun käyttäjän syöttö ei toimi ajetaan uudestaan
		cin.clear(); // tyhjennetään käyttäjän syöttö
		cin.ignore(256, '\n'); // ei välitä ennen välilyöntiä
		cin >> syotto;
	}
	return syotto; // palautetaan hyväksytty syöttö
}

int HashattySyotto(char* syotto) {// funktio salasanan hashaamiselle
	int i = 0, kerroin = 5; // kerroin on hashin kertominen
	long hash = 0;
	for (i = 0; i < strlen(syotto); i++) {
		hash = (hash + syotto[i]) * kerroin; // asetetaan käyttäjän syötöstä jokainen kirjain 
	}
	return hash; // palautetaan lopuksi numerot
}