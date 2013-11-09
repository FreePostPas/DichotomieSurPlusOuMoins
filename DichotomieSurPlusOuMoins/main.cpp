#include <iostream>
#include <time.h>

int half(int x, int y)
{
	return (x + y) / 2;
}

int dicho(int& first, int& last, int target, int i)
{
	switch(i)
	{
	case 0:
		return 33;
		break;
	case 1:
		switch(target)
		{
		case 0:
			return half(first, last);
		case 1:
			last = half(first, last);
			return half(first, last);
		case 2:
			first = 33;
			return 66;
		}
		break;
	default:
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
		break;
	}
}

float game(float m)
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
		iThink = dicho(first, last, target, i); // Réponse de "l'IA"
		std::cout << iThink << std::endl;

		if(iThink > alea)
			target = 1;
		else if(iThink < alea)
			target = 2;
		else
			std::cout << "Gagne en " << i << " coups" << std::endl;

		i++;
	} while(iThink != alea);

	return m + i;
}

int main()
{
	int i;
	float somme = 0;
	for(i = 0; i < 1000; i++)
	{		
		somme = game(somme);
	}

	std::cout << "Sur 1000 tests, il faut en moyenne " << somme / i << " coups a l'algorithme pour qu'il résolve le jeu." << std::endl << std::endl;

	system("PAUSE"); 
}