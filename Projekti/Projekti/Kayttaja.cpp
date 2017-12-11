#include <iostream>
#include "Kirjautuminen.h"

using namespace std;

int Valikko(){ // K�ytt�j�lt� kysyt��n mit� tehd��n.
	int vastaus;
	cout << "Valikko: " << endl << "1.Tee k�ytt�j�" << endl << "2.Kirjaudu " << endl << "0. Lopeta" << endl;
	cin >> vastaus;
	vastaus = HyvaksyttySyotto(vastaus); // tarkistetaan k�ytt�j�n sy�tt�
	return vastaus; // K�ytt�j�n sy�tt� palautetaan
}

void Aloitus() {// K�ytt�j�n sy�t�n perusteella:
	int kayttajansyotto;
	int* osoitinsyotto; // osoittimen muuttuja

	osoitinsyotto = &kayttajansyotto; // kutsutaan osoittimen kautta k�ytt�j�nsy�tt��

	do // do/while looppi kirjautumismenuun ja k�ytt�j�n luomiseen
	{
		kayttajansyotto = Valikko(); // palautetaan k�ytt�j�nsy�tt�
		switch (*osoitinsyotto) {// k�ytt�j�n sy�t�n perusteella
		case 1: {
			LuoKayttaja(); // luodaan k�ytt�j�
			break;
		}
		case 2: {
			Kirjautuminen();//kirjaudu	
			break;
		}
		}
	} while (*osoitinsyotto != 0);
}




