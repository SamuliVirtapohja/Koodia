#include <iostream>
#include "Kirjautuminen.h"
#include <string>
#include <fstream>
using namespace std;
int Valikko(){ // K�ytt�j�lt� kysyt��n mit� tehd��n.
	int vastaus;
	cout << "Valikko: " << endl << "1.Tee k�ytt�j�" << endl << "2.Kirjaudu " << endl << "0. Lopeta" << endl;
	cin >> vastaus;
	return vastaus;
}

void Aloitus(int syotto) {// K�ytt�j�n sy�t�n perusteella:
	switch (syotto){
		case 1: {
			LuoKayttaja(); // luodaan k�ytt�j�
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
	string rivi, tiedostonimi;
	kayttaja user;

	cout << "Anna k�ytt�j�nimi: "; // k�ytt�j�lt� kysyt��n nimi
	cin >> ws >> user.nimi; // otetaan vain k�ytt�j�n sy�tt� talteen

	tiedosto.open("kayttajat.txt"); // avataan k�ytt�j�t.txt
	if (tiedosto.is_open()) {
		while (getline(tiedosto, rivi)) {// haetaan rivit
			tiedostonimi = rivi.substr(0, rivi.find(" ")); // haetaan jokaiselta rivilt� ennen v�li� (eli k�ytt�ji� etsit��n) oleva sana
			if (user.nimi == tiedostonimi) { // jos k�ytt�j�n sy�tt�m� nimi matchaa, kysyt��n salasanaa.
				cout << "\nAnna salasana: "; // kysyt��n salasana
				cin >> ws >> user.salasana; // otetaan vain k�ytt�j�n sy�tt� talteen
				tiedostonimi = rivi.substr(rivi.find(" ") + 1); // haetaan jokaiselta rivilt� v�lin j�lkeen (eli salasanoja etsit��n) oleva sana
				if (tiedostonimi == user.salasana) { // verrataan tiedostossa olevaa sanaa k�ytt�j�n sy�tt�m��n sanaan
					cout << "hienoa kirjauduit sis��n" << endl; // salasanan kysyminen
				}
				else {
					cout << "Salasana v��rin!" << endl; // virheilmoitus
				}
				break;
			}
			else
			{
				cout << "Kyseist� k�ytt�j�� ei l�ytynyt" << endl; // virheilmoitus
			}
		}
		tiedosto.close(); // tiedosto suljetaan
	}
	else
	{
		cout << "tiedostoa ei voitu avata" << endl;
	}
	tiedosto.close();// suljetaan k�ytt�j�t.txt
}

