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
		if(lista_wydarzen[i]!=NULL)
			lista_wydarzen[i]->Wyswietl();
		else {
			lista_wydarzen.erase(lista_wydarzen.begin() + i);
			i--;
		}
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
	cout << login << " " << haslo << " " << imie << " " << nazwisko << " " << id << " " << data_urodzenia.dzien << "-" << data_urodzenia.miesiac << "-" << data_urodzenia.rok << " "<< nr_telefonu << " " << adres_email << endl;
}

bool Klient::Zapisz_do_GrTrening(GrTrening* grTrening)
{
	if (grTrening != nullptr) {
		grTrening->DodajUczestnika(this);
		lista_wydarzen.push_back(grTrening);
		return true;
	}
	return false;
}
