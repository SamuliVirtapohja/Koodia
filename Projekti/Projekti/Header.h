#pragma once
struct kayttaja {
	char salasana[20], nimi[20];
}; // luodaan käyttäjä tietue

void Tulostus(); // tulostuksen funktio
int Valikko(); // valikon funktio
void Aloitus(int); // aloituksen funktio
void LuoKayttaja(); // käyttäjän luominen

