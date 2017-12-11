#include <iostream>
#include "Kirjautuminen.h"
#include <string>
#include <fstream>
using namespace std;
int Valikko(int vastaus){ // Käyttäjältä kysytään mitä tehdään.
	cout << "Valikko: " << endl << "1.Tee käyttäjä" << endl << "2.Kirjaudu " << endl << "0. Lopeta" << endl;
	cin >> vastaus;
	return vastaus; // Käyttäjän syöttö palautetaan
}

void Aloitus() {// Käyttäjän syötön perusteella:
	int kayttajansyotto = 10;

	do // do/while looppi kirjautumismenuun ja käyttäjän luomiseen
	{
		kayttajansyotto = Valikko(kayttajansyotto); // palautetaan käyttäjänsyöttö
		switch (kayttajansyotto) {// käyttäjän syötön perusteella
		case 1: {
			LuoKayttaja(); // luodaan käyttäjä
			break;
		}
		case 2: {
			Kirjautuminen();//kirjaudu
			break;
		}
		}
	} while (kayttajansyotto != 0);
}

void LuoKayttaja() { // funktio käyttäjän luomiselle
	kayttaja uusikayttaja;

	ofstream tiedosto;

	cout << "Anna käyttäjänimi: "; // käyttäjältä kysytään nimi
	cin >> ws >> uusikayttaja.nimi; // otetaan vain käyttäjän syöttö talteen
	cout << "Anna salasana: "; // käyttäjältä kysytään salasana
	cin >> ws >> uusikayttaja.salasana; // otetaan vain käyttäjän syöttä talteen
	tiedosto.open("kayttajat.txt", ios_base::app); // avataan kayttajat.txt
	tiedosto << uusikayttaja.nimi << " " << uusikayttaja.salasana << endl;//Kirjaa nimi ja salasana tiedostoon
	tiedosto.close(); // suljetaan kayttajat.txt
}


void Kirjautuminen() { // funktio kirjautumiselle
	ifstream tiedosto;
	string rivi, tiedostonimi, tiedostosalasana;
	kayttaja user;
	bool tiedostonloppu = false;


	cout << "Anna käyttäjänimi: "; // käyttäjältä kysytään nimi
	cin >> ws >> user.nimi; // otetaan vain käyttäjän syöttö talteen
	cout << "\nAnna salasana: "; // kysytään salasana
	cin >> ws >> user.salasana; // otetaan vain käyttäjän syöttö talteen

	tiedosto.open("kayttajat.txt"); // avataan käyttäjät.txt
	if (tiedosto.is_open()) {// jos tiedosto avataan onnistuneesti
		while (getline(tiedosto, rivi)) {// haetaan jokaiselta riviltä tiedoston loppuun saakka
			tiedostonimi = rivi.substr(0, rivi.find(" ")); // haetaan jokaiselta riviltä ennen väliä (eli käyttäjiä etsitään) oleva sana
			tiedostosalasana = rivi.substr(rivi.find(" ") + 1); // haetaan välin jälkeen (eli salasanoja etsitään) oleva sana
			if (user.nimi == tiedostonimi && user.salasana == tiedostosalasana) { // jos käyttäjän syöttämä nimi ja salasana matchaa, kirjaudutaan sisään.
				cout << "hienoa kirjauduit sisään" << endl;
				tiedostonloppu = true; // asetetaan tiedostonloppu trueksi, niin ei tule virheilmoitusta väärästä käyttäjästä ja salasanasta
			}
		}							
	}
	else{// jos jokin meni mönkään tiedoston avaamisessa
		cout << "tiedostoa ei voitu avata" << endl;
	}

	if (tiedostonloppu == false) // jos tiedostonloppu-boolean ei muutu annetaan virheilmoitus väärästä salasanasta ja käyttäjästä
	{
		cout << "Käyttäjätunnus tai salasana väärin!" << endl; // virheilmoitus
	}

	tiedosto.close();// suljetaan käyttäjät.txt
}



