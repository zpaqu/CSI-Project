#include "Table.h"
#include "Exception.h"

//Auteurs: Nicolas Daigle (7223444), Zachary Paquette (7230016)
//Cours: CSI2772
//Date de remise: 9 Decembre 2015


//Constructeur du tableau. Le nombre de joueur est passe en parametre
Table::Table(int players)
{
	numPlayers = players;
	tableau = new std::shared_ptr<AnimalCard>*[103];
	for (int i = 0; i < 103; i++) {
		tableau[i] = new std::shared_ptr<AnimalCard>[103];
	}
	std::shared_ptr<AnimalCard> start(new StartCard());
	addAt(start, 52, 52);
}

Table::~Table()
{
	delete[] tableau;
}

//On ajoute le pointeur a une carte passe en parametre a une case dans le tableau du jeu. Une exception est lancee si la position est invalide
int Table::addAt(std::shared_ptr<AnimalCard> card, int x, int y)
{
	if (validPosition(card, x, y))
	{
		tableau[x][y] = card;
	}
	else 
	{
		Exception erreur("IllegalPlacement");
		throw erreur;
	}
	return tableau[x][y]->animalNumber;
}

//Retire le pointeur a une position donnee dans le tableau. Null si la position est vide
std::shared_ptr<AnimalCard> Table::pickAt(int x, int y)
{
	if (tableau[x][y] == nullptr) {
		return nullptr;
	}
	else {
		std::shared_ptr<AnimalCard> temp = tableau[x][y];
		tableau[x][y] = nullptr;
		return temp;
	}
}

//Retourne le pointeur a la carte d'une position donnee
std::shared_ptr<AnimalCard> Table::get(int x, int y)
{
	if (tableau[x][y] == nullptr) {
		return nullptr;
	}
	else {
		return tableau[x][y];
	}
}

//Verifie s'il y a un gagnant par rapport au nom de l'animal passe en reference
bool Table::win(std::string& animal)
{
	int count = 0;
	char a; 
	if (animal == "Bear")
	{
		a = 'b';
	}
	else if (animal == "Deer")
	{
		a = 'd';
	}
	else if (animal == "Hare")
	{
		a = 'h';
	}
	else if (animal == "Moose")
	{
		a = 'm';
	}
	else if (animal == "Wolf")
	{
		a = 'w';
	}
	else
	{
		return false; 
	}

	for (int x = 0; x < 103; x++) {
		for (int y = 0; y < 103; y++) {
			count += compare(tableau[x][y], a);
		}
	}
	if (count >= 12) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Verifie si la position entree par l'utilisateur est bien une position valide
bool Table::validPosition(std::shared_ptr<AnimalCard> card, int x, int y)
{
<<<<<<< HEAD
	if ((*card).animals[0] == 'c') {
		return true;
	}
	if (!tableau[x][y])
=======
	if (card->animals[0] == 'c')
	{
		return true;
	}
	else if (!tableau[x][y])
>>>>>>> origin/master
	{
		//Joker and Start Card
		if ((x > 0 && y >= 0 && x < 103 && y < 103 && (tableau[x - 1][y]->animals[0] == 'j' || tableau[x - 1][y]->animals[0] == 'c'))
			|| (x >= 0 && y > 0 && x < 103 && y < 103 && (tableau[x][y - 1]->animals[0] == 'j' || tableau[x][y - 1]->animals[0] == 'c'))
			|| (x >= 0 && y >= 0 && x < 102 && y < 103 && (tableau[x + 1][y]->animals[0] == 'j' || tableau[x + 1][y]->animals[0] == 'c'))
			|| (x >= 0 && y >= 0 && x < 103 && y < 102 && (tableau[x][y + 1]->animals[0] == 'j' || tableau[x][y + 1]->animals[0] == 'c')))
		{
			return true; 
		}
		//Animal Cards
		else if (x > 0 && y > 0 && x < 103 && y < 103 && (card->animals[0] == tableau[x - 1][y]->animals[2] || card->animals[0] == tableau[x][y - 1]->animals[1]))
		{
			return true;
		}
		else if (x > 0 && y >= 0 && x < 103 && y < 102 && (card->animals[1] == tableau[x - 1][y]->animals[3] || card->animals[1] == tableau[x][y + 1]->animals[0]))
		{
			return true;
		}
		else if (x >= 0 && y > 0 && x < 102 && y < 103 && (card->animals[2] == tableau[x][y - 1]->animals[3] || card->animals[2] == tableau[x + 1][y]->animals[0]))
		{
			return true;
		}
		else if (x >= 0 && y >= 0 && x < 102 && y < 102 && (card->animals[3] == tableau[x + 1][y]->animals[1] || card->animals[3] == tableau[x][y + 1]->animals[2]))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//Verifie s'il y a un animal correspondant au char passee en parametre sur la carte passee en parametre. Retourne un si oui (elle sera ajoute au compte total pour la methode win())
int Table::compare(std::shared_ptr<AnimalCard> card, char a)
{
	if (card->animals[0] == a || card->animals[1] == a || card->animals[2] == a || card->animals[3] == a)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//Imprite la table courante sur la console
void Table::print()
{
	for (int y = 0; y < 103; y++) {
		if(y<10)
			std::cout << "0";
		if (y<100)
			std::cout << "0";
		std::cout << "y";
		for (int x = 0; x < 103; x++) {
			if (y == 0) {
				if (x < 10)
					std::cout << "0";
				if (x < 100)
					std::cout << "0";
				std::cout << "x";
			}
			(*tableau[x][y]).printRow(Odd);
		}
		for (int x = 0; x < 103; x++) {
			if (y == 0) {
				std::cout << "   ";
			}
			(*tableau[x][y]).printRow(Even);
			std::cout << " ";
		}
		std::cout << std::endl;

	}
}
