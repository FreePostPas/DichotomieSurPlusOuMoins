#include <iostream>

int dicho(int first, int last)
{

}

int main()
{
	std::cout << "Plus ou moins" << std::endl;

	int alea = rand() % 100 + 1;
	int iThink = 0;
	int i = 0;
	int first = 0;
	int last = 100;

	do
	{
		std::cout << "Tapez un chiffre" << std::endl;
		std::cin >> iThink;
		iThink = dicho(first, last); // Réponse de "l'IA"

		if(iThink > alea)
			std::cout << "C'est moins" << std::endl;
		else if(iThink < alea)
			std::cout << "C'est plus" << std::endl;
		else
			std::cout << "Gagne en " << i << " coups" << std::endl;

		i++;
	} while(iThink != alea);

	system("PAUSE"); 
}