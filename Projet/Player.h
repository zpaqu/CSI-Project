#include <string>

class Player
{
public:
	Player();
	~Player();
	std::string swapSecretAnimal(std::string&);
	std::string getSecretAnimal();
	//Methode d'affiche d'etat aussi...

private:
	std::string name;
	std::string sAnimal;
	//Je sais pas comment ajouter sa main live...

};
