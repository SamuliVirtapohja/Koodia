#pragma once
struct kayttaja {
	char salasana[20], nimi[20];
}; // luodaan k�ytt�j� tietue

void Tulostus(); // tulostuksen funktio
int Valikko(); // valikon funktio
void Aloitus(int); // aloituksen funktio
void LuoKayttaja(); // k�ytt�j�n luominen

