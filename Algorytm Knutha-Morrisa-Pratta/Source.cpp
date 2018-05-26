#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

int main()
{
	char tekst[]="ABCEABCDABCDABG";
	char szukana[]="AAABBBAAA";

	int i=0, j=0,m;
	int lt = strlen(tekst);
	int l = strlen(szukana);
	cout << l << endl;
	int koniec = 0;



	int prefiksy[10];//dlugosc tablicy na sztywno + zawsze musi byc wiekszy bo wieksze joty moga zrobic dziwne rzeczy
	prefiksy[0] = 0;
	bool znow = false;

	for (i = 0; i < l; i++)
	{
		prefiksy[i]=0;
	}




	for (i = 1; i <= l; i++)
	{
		znow = true;
		while (znow == true)
		{
			if ((szukana[i] != szukana[j]) && (j > 0))
			{
				j = prefiksy[j - 1];
				znow = true;
				//cout << "Robi sie 3" << endl;
			}

			if (szukana[i] == szukana[j])
			{
				prefiksy[i] = j + 1;
				j++;
				znow = false;
				//cout << "Robi sie 1" << endl;
			}

			if ((szukana[i] != szukana[j]) && (j == 0))
			{
				prefiksy[i] = 0;
				znow = false;
				//cout << "Robi sie 2" << endl;
			}

			
		}
}
	cout << "Prefiksy i postfiksy: ";
	for (m = 0; m < l; m++)
	{
		cout << prefiksy[m];
	}
	cout << endl;


//==============================================================================================================//

	i=0, j = 0;

	while ((i + j < lt)&&(koniec==0))
	{

		if (szukana[i] == tekst[i + j])
		{

			if (i == (l - 1))
			{
				//wzorzec znaleziony
				cout << "Wzorzec znaleziony" << endl;
				koniec = 1;
				cout << "I to: " << i;
				cout << " ,a j+i to: " << j+i << endl;
			}
			else
			{
				i++;

			}
		}


		if (szukana[i] != tekst[i + j])
		{

			if (i > 0)
			{
				j = j + i - prefiksy[i - 1];
				i = prefiksy[i - 1];
			}
			else
			{
				i = 0;
				j++;
			}
		}
	}
	system("PAUSE");

	return 0;
  }