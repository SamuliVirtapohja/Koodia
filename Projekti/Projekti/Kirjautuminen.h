#pragma once
struct kayttaja {
	char salasana[20], nimi[20];
}; // luodaan k‰ytt‰j‰ tietue

// k‰ytt‰j‰n kanssa kohtaavat funktiot
int Valikko(int); // valikon funktio
void Aloitus(); // aloituksen funktio

void asd(kayttaja);

// funktiot mitk‰ eiv‰t koske k‰ytt‰j‰‰ mitenk‰‰n.
void LuoKayttaja(); // k‰ytt‰j‰n luominen
void Kirjautuminen(); // k‰ytt‰j‰n‰ kirjautuminen sis‰‰n

