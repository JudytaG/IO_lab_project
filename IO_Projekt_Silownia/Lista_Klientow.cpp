#include "Lista_Klientow.h"

Lista_Klientow* Lista_Klientow::inst_ = NULL;

Lista_Klientow* Lista_Klientow::getInstance() {
	if (inst_ == NULL) {
		inst_ = new Lista_Klientow();
	}
	return(inst_);
}

bool Lista_Klientow::Dodaj_Klienta(Klient* klient)
{
	klienci.push_back(klient);
	return true;
}

void Lista_Klientow::Wyswietl()
{
	for (int i = 0; i < klienci.size(); i++) {
		klienci[i]->Wyswietl();
	}
}
