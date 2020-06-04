#include "Trener_Personalny.h"

bool Trener_Personalny::Zaplanuj_trening(Data data, Czas godzina, Czas czas_trwania, string opis, Klient* klient)
{
	string status = "Zaplanowany";
	Trening* nowy_trening = new Trening(data, godzina, czas_trwania, lista_wydarzen.size(), status, opis, klient, this);
	return true;
}

bool Trener_Personalny::Edytuj_trening(Trening* trening, Data data, Czas godzina, Czas czas_trwania)
{
	trening->Edytuj(data, godzina,czas_trwania);
	return true;
}

bool Trener_Personalny::Usun_trening(Trening* trening)
{
	delete trening;
	trening = NULL;
	return true;
}

bool Trener_Personalny::Dodaj_opis(Trening* trening, string opis)
{
	trening->SetOpis(opis);
	return true;
}

bool Trener_Personalny::Usun_opis(Trening* trening)
{
	trening->SetOpis(string());
	return true;
}

bool Trener_Personalny::Wyswietl_opis(Trening* trening)
{
	cout<<trening->GetOpis()<<endl;
	return true;
}

bool Trener_Personalny::Zmien_status(Trening* trening, string status)
{
	trening->SetStatus(status);
	return true;
}

bool Trener_Personalny::Dodaj_wydarzenie(Wydarzenie* wydarzenie)
{
	lista_wydarzen.push_back(wydarzenie);
	return true;
}

void Trener_Personalny::Wyswietl_kalendarz()
{
	cout << "Wydarzenia:" << endl;
	for (int i = 0; i < lista_wydarzen.size(); i++) {
		if (lista_wydarzen[i] != NULL)
			lista_wydarzen[i]->Wyswietl();
		else {
			lista_wydarzen.erase(lista_wydarzen.begin() + i);
			i--;
		}
	}
}
