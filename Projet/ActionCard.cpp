#include "ActionCard.h"

//Auteurs: Nicolas Daigle (7223444), Zachary Paquette (7230016)
//Cours: CSI2772
//Date de remise: 9 Decembre 2015


//La variable publique act de Action Card obtient sa valeur d'enumeration par la valeur entree en parametre en construisant la carte d'action
ActionCard::ActionCard(char c) : NoSplit(c)
{
	if (c == 'B')
	{
		act = Bear;
	}
	else if (c == 'D')
	{
		act = Deer;
	}
	else if (c == 'H')
	{
		act = Hare;
	}
	else if (c == 'M')
	{
		act = Moose;
	}
	else if (c == 'W')
	{
		act = Wolf;
	}
	else
	{
		// nothing
	}

}

ActionCard::~ActionCard()
{

}

//Query choisit quel chemin prendre par rapport a la valeur de la variable act de la classe ActionCard. Les variables sont assignes par entree de l'utilisateur
QueryResult ActionCard::query()
{
	QueryResult q = QueryResult();

	if (act == Bear) 
	{
		std::cout << "Vous avez joué une carte d'action de type Ours!" << std::endl;
		std::cout << "Avec quel joueur voulez vous echanger votre main?";
		std::cin >> q.playerNum;
	}

	else if (act == Deer) 
	{
		std::cout << "Vous avez joué une carte d'action de type Cerf!" << std::endl;
		std::cout << "Quel est le numero du joueur avec qui vous voulez echanger votre carte objectif?";
		std::cin >> q.playerNum;
	}

	else if (act == Hare)
	{
		std::cout << "Vous avez joué une carte d'action de type Lievre!" << std::endl;

		std::cout << "Quel carte voulez vous deplacer? (Coordonnees X,Y)" << std::endl;
		std::cin >> q.cX;
		std::cin >> q.cY;

		std::cout << "A quel emplacement voulez vous placer cette carte? (Coordonnees X,Y)" << std::endl;
		std::cin >> q.rX;
		std::cin >> q.rY;
	}

	else if (act == Moose) 
	{
		std::cout << "Vous avez joué une carte d'action de type Original!" << std::endl;
		std::cout << "Changement des cartes d'objectifs..." << std::endl;
	}

	else if (act == Wolf) 
	{
		std::cout << "Vous avez joué une carte d'action de type Loup!" << std::endl;
		std::cout << "Quel carte voulez vous prendre? (Coordonnees X, Y)" << std::endl;
		std::cin >> q.rX;
		std::cin >> q.rY;
	}

	else
	{
		//nothing
	}
	return q;
}

//Perform s'execute a l'aide de la valuer de l'enumaration act
void ActionCard::perform(Table& t, Player* p , QueryResult q)
{
	/*On trouve le "Other Player" a l'aide de la difference entre le numero du joueur courant et le numero du joueur voulu demande pendant query. 
	On peut deplacer un pointeur temporaire dans la direction de la difference. Lorsque cet autre joueur est trouver, on assigne une Hand temporaire et on change les positions des mains des joueurs*/

	if (act == Bear) {
		Player* oP = p+(q.playerNum - p->getNum());
		Hand tH = p->getHand();
		p->setHand(oP->getHand());
		oP->setHand(tH);
	}

	//On trouve le "Other Player" comme dans BearAction mais cette fois si c'est l'animal secret qu'on jongle avec une valeur temporaire.
	else if (act == Deer) {
		Player* oP = p + (q.playerNum - p->getNum());
		std::string tS = p->getSecretAnimal();
		p->swapSecretAnimal(oP->getSecretAnimal());
		oP->swapSecretAnimal(tS);
	}

	//On enleve le pointeur a la carte et on la place a la position voulu par l'utilisateur
	else if (act == Hare) {
		std::shared_ptr<AnimalCard> sP1 = t.pickAt(q.cX, q.cY);
		if (sP1 != nullptr)
		{
			t.addAt(sP1, q.rX, q.rY);
		}
	}

	//On assigne un pointeur temporaire a la fin de la liste. On sauvegarde son animal secret. Les animaux secrets sont remplaces par l'animal du pointeur precedent celui courant.
	//L'animal temporaire est assigne a la fin quand le pointeur pointe au premier element de l'array de joueur
	else if (act == Moose) {
		Player* lP = p + (t.numPlayers - p->getNum());

		std::string tA = lP->getSecretAnimal();

		for (int i = t.numPlayers; i >1 ; i--)
		{
			lP->swapSecretAnimal((--lP)->getSecretAnimal());
		}
		lP->swapSecretAnimal(tA);
	}

	//Ici on retire la carte de la table et on la place dans la main du joueur. 
	else if (act == Wolf) {
		std::shared_ptr<AnimalCard> sP = t.pickAt(q.cX, q.cY);
		p->getHand() += sP;
	}

	else
	{
		//do nothing
	}

}
