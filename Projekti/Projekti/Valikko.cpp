#include <iostream>
#include "Kirjautuminen.h"
#include <string>
#include <fstream>
using namespace std;
int Valikko(){ // Käyttäjältä kysytään mitä tehdään.
	int vastaus;
	cout << "Valikko: " << endl << "1.Tee käyttäjä" << endl << "2.Kirjaudu " << endl << "0. Lopeta" << endl;
	cin >> vastaus;
	return vastaus;
}

void Aloitus(int syotto) {// Käyttäjän syötön perusteella:
	switch (syotto){
		case 1: {
			LuoKayttaja(); // luodaan käyttäjä
			break;
		}
		case 2: {
			Kirjautuminen();//kirjaudu
			break;
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
	tiedosto.open("kayttajat.txt", ios_base::app); // avataan kayttajat.txt
	tiedosto << uusikayttaja.nimi << " " << uusikayttaja.salasana << endl;//Kirjaa nimi ja salasana tiedostoon
	tiedosto.close(); // suljetaan kayttajat.txt
}


void Kirjautuminen() { // funktio kirjautumiselle
	ifstream tiedosto;
	string rivi, tiedostonimi;
	kayttaja user;

	cout << "Anna käyttäjänimi: "; // käyttäjältä kysytään nimi
	cin >> ws >> user.nimi; // otetaan vain käyttäjän syöttö talteen

	tiedosto.open("kayttajat.txt"); // avataan käyttäjät.txt
	if (tiedosto.is_open()) {
		while (getline(tiedosto, rivi)) {// haetaan rivit
			tiedostonimi = rivi.substr(0, rivi.find(" ")); // haetaan jokaiselta riviltä ennen väliä (eli käyttäjiä etsitään) oleva sana
			if (user.nimi == tiedostonimi) { // jos käyttäjän syöttämä nimi matchaa, kysytään salasanaa.
				cout << "\nAnna salasana: "; // kysytään salasana
				cin >> ws >> user.salasana; // otetaan vain käyttäjän syöttö talteen
				tiedostonimi = rivi.substr(rivi.find(" ") + 1); // haetaan jokaiselta riviltä välin jälkeen (eli salasanoja etsitään) oleva sana
				if (tiedostonimi == user.salasana) { // verrataan tiedostossa olevaa sanaa käyttäjän syöttämään sanaan
					cout << "hienoa kirjauduit sisään" << endl; // salasanan kysyminen
				}
				else {
					cout << "Salasana väärin!" << endl; // virheilmoitus
				}
				break;
			}
			else
			{
				cout << "Kyseistä käyttäjää ei löytynyt" << endl; // virheilmoitus
			}
		}
		tiedosto.close(); // tiedosto suljetaan
	}
	else
	{
		cout << "tiedostoa ei voitu avata" << endl;
	}
	tiedosto.close();// suljetaan käyttäjät.txt
}

