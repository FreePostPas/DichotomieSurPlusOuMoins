#include <iostream>
#include <sstream>
#include <time.h>

int half(int x, int y)
{
	return (x + y) / 2;
}

int dicho(int& first, int& last, int target)
{
	switch(target)
	{
	case 0:
		return half(first, last);
	case 1:
		last = half(first, last);
		return half(first, last);
	case 2:
		first = half(first, last);
		return half(first, last);
	}
}

float game(float m, int y)
{
	std::cout << "Plus ou moins" << std::endl;

	srand(time(NULL));
	int alea = rand() % 100;
	int iThink = 0;
	int i = 0;
	int first = 0;
	int last = 100;
	int target = 0; // 0 : Center (1er coup) | 1 : C'est moins | 2 : C'est plus

	do
	{
		std::cout << "Tapez un chiffre" << std::endl;
		iThink = dicho(first, last, target); // Réponse de "l'IA"
		std::cout << iThink << std::endl;

		if(iThink > alea)
			target = 1;
		else if(iThink < alea)
			target = 2;
		else
			std::cout << "Gagne en " << i << " coups" << std::endl;

		i++;
	} while(iThink != alea);

	float result = (m * (y - 1) + i) / i;

	return result;
}

int main()
{
	for(int i = 0; i < 1000; i++)
	{
		float moyenne = 0;
		game(moyenne, i);
	}

	std::cout << "Sur 1000 tests, il faut en moyenne " << moyenne << " coups a l'algorithme pour qu'il résolve le jeu." << std::endl << std::endl;

	system("PAUSE"); 
}