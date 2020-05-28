#include "Klient.h"

bool Klient::Dodaj_wydarzenie(Wydarzenie* wydarzenie)
{
	lista_wydarzen.push_back(wydarzenie);
	return true;
}

void Klient::Wyswietl_kalendarz()
{
	cout << "Wydarzenia:" << endl;
	for (int i = 0; i < lista_wydarzen.size(); i++) {
		lista_wydarzen[i]->Wyswietl();
	}
}

bool Klient::Dodaj_karnet(Karnet* nowy_karnet)
{
	this->karnet = nowy_karnet;
	return true;
}

void Klient::Sprawdz_status()
{
	if (karnet!=nullptr && karnet->GetStatus())
		cout << "Aktywny" << endl;
	else
		cout << "Nieaktywny" << endl;
}

void Klient::Wyswietl()
{
	dynamic_cast<Osoba*> (this)->Wyswietl();
	cout << nr_telefonu << " " << adres_email << endl;
}

bool Klient::Zapisz_do_GrTrening(GrTrening* grTrening)
{
	if (grTrening != nullptr) {
		grTrening->Dopisz(this);
		return true;
	}
	return false;
}
