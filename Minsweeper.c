#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<fcntl.h>
#include<io.h>
#include <windows.h>
#include "Minsweeper.h"
#include "Colors.c"

#define Flush fflush(stdin)
#pragma execution_character_set( "utf-8" )
#pragma warning (disable:4996)


int game[21][21] = { 0 };
int temp[21][21] = { 0 };



void show(int i, int j, int n)
{
	temp[i][j] = 1;
	if (i - 1 >= 0 && j - 1 >= 0 && game[i - 1][j - 1] != -1 && temp[i - 1][j - 1] == 0)
	{
		if (game[i - 1][j - 1] == 0 && temp[i - 1][j - 1] == 0) show(i - 1, j - 1, n);
		else  temp[i - 1][j - 1] = 1;
	}


	if (i + 1 < n && j - 1 >= 0 && game[i + 1][j - 1] != -1 && temp[i + 1][j - 1] == 0)
	{
		if (game[i + 1][j - 1] == 0 && temp[i + 1][j - 1] == 0) show(i + 1, j - 1, n);
		else  temp[i + 1][j - 1] = 1;
	}




	if (i - 1 >= 0 && j + 1 < n && game[i - 1][j + 1] != -1 && temp[i - 1][j + 1] == 0)
	{
		if (game[i - 1][j + 1] == 0 && temp[i - 1][j + 1] == 0) show(i - 1, j + 1, n);
		else  temp[i - 1][j + 1] = 1;
	}




	if (i + 1 < n && j + 1 < n && game[i + 1][j + 1] != -1 && temp[i + 1][j + 1] == 0)
	{
		if (game[i + 1][j + 1] == 0 && temp[i + 1][j + 1] == 0) show(i + 1, j + 1, n);
		else  temp[i + 1][j + 1] = 1;
	}







	if (j - 1 >= 0 && game[i][j - 1] != -1 && temp[i][j - 1] == 0)
	{
		if (game[i][j - 1] == 0 && temp[i][j - 1] == 0) show(i, j - 1, n);
		else  temp[i][j - 1] = 1;
	}




	if (j + 1 < n && game[i][j + 1] != -1 && temp[i][j + 1] == 0)
	{
		if (game[i][j + 1] == 0 && temp[i][j + 1] == 0) show(i, j + 1, n);
		else  temp[i][j + 1] = 1;
	}






	if (i - 1 >= 0 && game[i - 1][j] != -1 && temp[i - 1][j] == 0)
	{
		if (game[i - 1][j] == 0 && temp[i - 1][j] == 0) show(i - 1, j, n);
		else  temp[i - 1][j] = 1;
	}






	if (i + 1 < n && game[i + 1][j] != -1 && temp[i + 1][j] == 0)
	{
		if (game[i + 1][j] == 0 && temp[i + 1][j] == 0) show(i + 1, j, n);
		else  temp[i + 1][j] = 1;
	}



}



int clearround(int x, int y, int n)
{
	int count = 0 , q = 300;


	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (temp[i][j] == -1) count++;
		}
	}

	if (count == game[x][y])
	{

		for (int i = x - 1; i <= x + 1; i++)
		{
			for (int j = y - 1; j <= y + 1; j++)
			{
				if (temp[i][j] == -1)
				{
					if (game[i][j] == -1)
					{
						count--;
					}
				}
			}
		}


		if (count == 0)
		{
			for (int i = x - 1; i <= x + 1; i++)
			{
				for (int j = y - 1; j <= y + 1; j++)
				{
					if (temp[i][j] != -1)
					{
						temp[i][j] = 1;


						if (game[i][j] == 0)
						{

							show(i, j, n);

						}
					}
				}
			}

			return 1;
		}


		else
		{

			
			system("cls");
			red();
			wprintf(L"\nYou Lost!\n\n");


			reset();
			wprintf(L"     ");

			for (int i = 0; i < n; i++)
			{
				if (i < 10)	wprintf(L" %d    ", i);
				else wprintf(L"%d    ", i);
			}

			wprintf(L"\n");



			for (int i = 0; i < n; i++)
			{
				orange();
				if (i < 10) wprintf(L" %d", i);
				else wprintf(L"%d", i);
				reset();
				wprintf(L" | ");


				for (int j = 0; j < n; j++)
				{
					if (game[i][j] != -1 && game[i][j] != 0)
					{
						if (game[i][j] == 1) cyan();
						if (game[i][j] == 2) greenb();
						if (game[i][j] == 3) dyellow();
						if (game[i][j] == 4) orange();
						if (game[i][j] == 5) pink();
						if (game[i][j] == 6) blue();
						if (game[i][j] == 7) purple();
						if (game[i][j] == 8) red();


						wprintf(L" %d ", game[i][j]);
						reset();
						wprintf(L" | ");

					}
					else if (game[i][j] == 0)
					{
						reset();
						wprintf(L"    | ");
					}
					else if (game[i][j] == -1)
					{
						purple();
						wprintf(L" Ơ ");
						reset();
						wprintf(L" | ");
					}
					else if (temp[i][j] == 0)
					{
						pink();
						wprintf(L" - ");

						reset();
						wprintf(L" | ");
					}
				}
				wprintf(L"\n\n");


				Sleep(300);
				Beep(q, 300);
				//_getch();
				q += 50;



			}
			return 0;

		}


	}


	greenb();
	wprintf(L"\nWrong Order!\n");
	reset();


	return 7;


}



int pName(char n[20])
{


	purple();
	wprintf(L"°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°°•°•°•°•°•°•°°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°°•°•\n\n\n\n\n");



	reset();
	int i = 0;
	wprintf(L"\n\t\t\t\t\t\t\b\byour name is ");

	while(n[i] != '\0')
	{
		wprintf(L"%c", n[i]);
		i++;
	}

	wprintf(L".\n\n\n\n\n\n");


	purple();
	wprintf(L"°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°°•°•°•°•°•°•°°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°°•°•\n\n");




	reset();

	return 0;
}



void pStatus(int a, int b)
{
	int won, lost;
	won = a;
	lost = b;


	pink();
	wprintf(L"°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°°•°•°•°•°•°•°°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°°•°•\n\n");


	reset();
	wprintf(L"\n\n\t\t\t\t\t<<<<<<You won %d times.>>>>>>\n\n\t\t\t\t\t<<<<<<You lost %d times.>>>>>>\n", won, lost);

	pink();
	wprintf(L"\n\n°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°°•°•°•°•°•°•°°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°°•°•\n\n");





}



void ChangeName(char* p)
{


	reset();
	wprintf(L"°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°°•°•°•°•°•°•°°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°°•°•\n\n");



	aqua();
	wprintf(L"\n\n\t\t\t\t\t\b\b\b<<<<<<Enter your New Name:>>>>>>\n\n\n\t\t\t\t\t\t\t\b\b\b\b\b");

	green();
	scanf("%s", p);


	aqua();
	wprintf(L"\n\n\t\t\t\t<<<<You Changed your name successfully.>>>>\n\n\n\n");


	reset();
	wprintf(L"°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°°•°•°•°•°•°•°°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°°•°•\n\n");


}







int Game(int n , char name[], int a, int b)
{
	int bomb = 0, flag, x, y;

	if (n == 9) flag = 10;
	if (n == 12) flag = 20;
	if (n == 20) flag = 50;



	/*Shakht Zamin Bomb ha*/




	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			game[i][j] = 0;
			temp[i][j] = 0;
		}
	}
	if (n == 9) while (bomb < 10)
	{
		int j = rand() % 9;
		int count = 0;
		for (int i = 0; i <= 8; i++)
		{
			if (game[i][j] == -1)
				count++;
		}
		if (count < 3 )
		{
			int i = rand() % 9;
			if (game[i][j] != -1)
			{
				game[i][j] = -1;
				bomb++;
			}
			continue;
		}
	}


	else if (n == 12) while (bomb < 20)
	{
		int j = rand() % 12;
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if (game[i][j] == -1)
				count++;
		}
		if (count < 3)
		{
			int i = rand() %12;
			if (game[i][j] != -1)
			{
				game[i][j] = -1;
				bomb++;
			}
			continue;
		}
	}


	else if (n == 20) while (bomb < 50)
	{
		int j = rand() % 20;
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if (game[i][j] == -1)
				count++;
		}
		if (count < 4)
		{
			int i = rand() % 20;
			if (game[i][j] != -1)
			{
				game[i][j] = -1;
				bomb++;
			}
			continue;
		}
	}



	/*zamin bomb tamam*/








	/*Meghdar Dehi Be Khane Ha*/




	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int a = i - 1; a <= i + 1; a++)
			{
				for (int b = j - 1; b <= j + 1; b++)
				{
					if (a >= 0 && b >= 0 && b < n && a < n)
					{
						if (game[i][j] != -1)
						{
							if (a != i || b != j)
							{
								if (game[a][b] == -1)
								{
									game[i][j]++;
								}
							}
						}
					}
				}
			}
		}
	}




	/*meghdar dahi tamam*/





	char d = 'r';




	/*scan print*/
	
	
	do
	{

		int i = 0;

		system("cls");

		orange();
		wprintf(L"Player :");
		while (name[i] != '\0')
		{
			wprintf(L"%c", name[i]);
			i++;
		}

		aqua();
		wprintf(L"\t\tWin(s) : %d\t\tLose(s) : %d\n\n" , a , b);



		reset();
		wprintf(L"Left Flags : ", flag);


		greenb();
		wprintf(L"%d \x2660\n\n", flag);



		/*print zamin bazi*/



		reset();
		wprintf(L"     ");

		for (int i = 0; i < n; i++)
		{
			if (i < 10)	wprintf(L" %d    ", i );
			else wprintf(L"%d    ", i );
		}

		wprintf(L"\n");



		for (int i = 0; i < n; i++)
		{
			orange();
			if (i < 10) wprintf(L" %d", i );
			else wprintf(L"%d", i );
			reset();
			wprintf(L" | ");


			for (int j = 0; j < n; j++)
			{
				if (temp[i][j] == 1 && game[i][j] != 0)
				{
					if (game[i][j] == 1) cyan();
					if (game[i][j] == 2) greenb();
					if (game[i][j] == 3) dyellow();
					if (game[i][j] == 4) orange();
					if (game[i][j] == 5) pink();
					if (game[i][j] == 6) blue();
					if (game[i][j] == 7) purple();
					if (game[i][j] == 8) red();


					wprintf(L" %d ", game[i][j]);
					reset();
					wprintf(L" | ");

				}
				else if (game[i][j] == 0 && temp[i][j] == 1)
				{
					reset();
					wprintf(L"    | ");
				}
				else if (temp[i][j] == -1)
				{
					red();
					wprintf(L" \x2660 ");
					reset();
					wprintf(L" | ");
				}
				else if (temp[i][j] == 0)
				{
					pink();
					wprintf(L" - ");

					reset();
					wprintf(L" | ");
				}
			}
			wprintf(L"\n\n");
		}








		/*Scan*/






		char r[5], l[5], c[5] , X[10] , Y[10];
	A:
		{
			reset();
			wprintf(L"Enter a number between 0 and %d for row:\n", n - 1);
			green();
			scanf("\t%s", X);

			if (strlen(X) != 1 && strlen(X) != 2)
			{
				wprintf(L"Wrong number!");
				Sleep(1000);
				wprintf(L"Enter one numbers between 0 and %d for row \n", n - 1);
				green();
				scanf("\t%s", X);

			}

			else if (strlen(X) == 2) x = 10* (X[0] - '0') +( X[1] - '0');

			else x = X[0] - '0';

			reset();
			wprintf(L"Enter two numbers between 0 and %d for column:\n", n - 1);
			green();
			scanf("\t%s", Y);


			if (strlen(Y) != 1 && strlen(Y) != 2)
			{
				wprintf(L"Wrong number!");
				Sleep(1000);

				wprintf(L"Enter one numbers between 0 and %d for column \n", n - 1);
				green();
				scanf("\t%s", Y);

			}

			else if (strlen(Y) == 2) y = 10 * (Y[0] - '0') + (Y[1] - '0');


			else y = Y[0] - '0';
		}


	if (x >= n || x < 0 || y >= n || y < 0)
	{
		wprintf(L"Wrong number!");
		goto A;
	} 



	reset();
	wprintf(L"Enter r of l or c :\n\n", n);
 



		d = getch();
		reset();





		/*left click*/

		if (d == 'l' && x < n && y < n)
		{




			/*saratan*/

			if (temp[x][y] == 0 && game[x][y] == 0)
			{

				temp[x][y] = 1;
				show(x, y, n);



			}





			/*bar aval*/

			else if (temp[x][y] == 0)  	temp[x][y] = 1;



			/*tekrari*/

			else if (temp[x][y] == 1)
			{
				greenb();
				wprintf(L"\nThe Square is already selected!\n");

				Sleep(1000);

			}



			/*flag dar*/

			else if (temp[x][y] == -1)
			{
				greenb();
				wprintf(L"\nThe Square is already selected!\nplease remove the flag first.\n");
				Sleep(1000);
			}



		}












		/*right click*/

		else if (d=='r' && x < n && y < n)
		{

			/*Entekhab Flag ya bardashtan*/

			if (flag >= 1 && temp[x][y] == 0)
			{

				temp[x][y] = -1;
				flag--;
			}




			else if (temp[x][y] == -1)
			{
				temp[x][y] = 0;
				flag++;

			}



			/*flag tamam shode*/

			else if ( flag <= 0 && temp[x][y] == 0 && x < n && y < n)
			{
				greenb();
				wprintf(L"No more Flags!\n");
				wprintf(L"Enter two numbers and one charecter :\nEnter a wrong combination again to exit\n");
				Sleep(1000);


				purple();
				scanf("%d\n%d", &x, &y);
				d = getch();








				/*left click*/

				if (d == 'l' && x < n && y < n)
				{




					/*saratan*/

					if (temp[x][y] == 0 && game[x][y] == 0)
					{

						temp[x][y] = 1;
						show(x, y, n);



					}





					/*bar aval*/

					else if (temp[x][y] == 0)  	temp[x][y] = 1;



					/*tekrari*/

					else if (temp[x][y] == 1)
					{
						greenb();
						wprintf(L"The Square is already selected!\n");
						Sleep(1000);

					}



					/*flag dar*/

					else if (temp[x][y] == -1)
					{
						greenb();
						wprintf(L"The Square is already selected!\nplease remove the flag first.\n");
						Sleep(1000);
					}



				}












				/*right click*/

				else if (d == 'r' && x < n && y < n)
				{

					/*Entekhab Flag ya bardashtan*/

					if (flag >= 1 && temp[x][y] == 0)
					{

						temp[x][y] = -1;
						flag--;
					}




					else if (temp[x][y] == -1)
					{
						temp[x][y] = 0;
						flag++;

					}


				}





				/*clear*/

				else if (d == 'c' && x < n && y < n)
				{



					if (clearround(x, y, n) == 0)
						return 0;


				}



				/*close*/


				else
				{

					dyellow();
					wprintf(L"\nYou exited successfully.\n\n");

					return 0;

				}








			}



		}
		




		/*clear*/

		else if (d == 'c' && x < n && y < n)
		{



			if (clearround(x, y , n) == 0)
				return 0;


		}



		/*close*/


		else
		{

	




		dyellow();
		wprintf(L"\nYou exited successfully.\n\n");
		return 0;






		}





		/*check bordan*/


		int count = 0;





		if (n == 9)
		{

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (game[i][j] == -1)
					{
						if (temp[i][j] == -1)
						{
							count++;
						}
					}
				}
			}
			if (count == 10)
			{
				{

					system("cls");


					int g = 500;
					reset();
					wprintf(L"     ");

					for (int i = 0; i < n; i++)
					{
						if (i < 10)	wprintf(L" %d    ", i);
						else wprintf(L"%d    ", i);
					}

					wprintf(L"\n");



					for (int i = 0; i < n; i++)
					{
						orange();
						if (i < 10) wprintf(L" %d", i);
						else wprintf(L"%d", i);
						reset();
						wprintf(L" | ");


						for (int j = 0; j < n; j++)
						{
							if (game[i][j] != -1 && game[i][j] != 0)
							{
								if (game[i][j] == 1) cyan();
								if (game[i][j] == 2) greenb();
								if (game[i][j] == 3) dyellow();
								if (game[i][j] == 4) orange();
								if (game[i][j] == 5) pink();
								if (game[i][j] == 6) blue();
								if (game[i][j] == 7) purple();
								if (game[i][j] == 8) red();


								wprintf(L" %d ", game[i][j]);
								reset();
								wprintf(L" | ");

							}
							else if (game[i][j] == 0)
							{
								reset();
								wprintf(L"    | ");
							}
							else if (game[i][j] == -1)
							{
								purple();
								wprintf(L" \x2660 ");
								reset();
								wprintf(L" | ");
							}
							else if (temp[i][j] == 0)
							{
								pink();
								wprintf(L" - ");

								reset();
								wprintf(L" | ");
							}
						}
						wprintf(L"\n\n");


						Sleep(300);
						Beep(g, 300);
						//_getch();
						g += 30;



					}


					return 1;

				}
			}

			else
			{
				continue;
			}

		}


		else if (n == 12)
		{

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (game[i][j] == -1)
					{
						if (temp[i][j] == -1)
						{
							count++;
						}
					}
				}
			}
			if (count == 20)
			{
				{


					system("cls");

					int g = 500;
					reset();
					wprintf(L"     ");

					for (int i = 0; i < n; i++)
					{
						if (i < 10)	wprintf(L" %d    ", i);
						else wprintf(L"%d    ", i);
					}

					wprintf(L"\n");



					for (int i = 0; i < n; i++)
					{
						orange();
						if (i < 10) wprintf(L" %d", i);
						else wprintf(L"%d", i);
						reset();
						wprintf(L" | ");


						for (int j = 0; j < n; j++)
						{
							if (game[i][j] != -1 && game[i][j] != 0)
							{
								if (game[i][j] == 1) cyan();
								if (game[i][j] == 2) greenb();
								if (game[i][j] == 3) dyellow();
								if (game[i][j] == 4) orange();
								if (game[i][j] == 5) pink();
								if (game[i][j] == 6) blue();
								if (game[i][j] == 7) purple();
								if (game[i][j] == 8) red();


								wprintf(L" %d ", game[i][j]);
								reset();
								wprintf(L" | ");

							}
							else if (game[i][j] == 0)
							{
								reset();
								wprintf(L"    | ");
							}
							else if (game[i][j] == -1)
							{
								purple();
								wprintf(L" \x2660 ");
								reset();
								wprintf(L" | ");
							}
							else if (temp[i][j] == 0)
							{
								pink();
								wprintf(L" - ");

								reset();
								wprintf(L" | ");
							}
						}
						wprintf(L"\n\n");


						Sleep(300);
						Beep(g, 300);
						//_getch();
						g += 30;



					}





					return 1;

				}
			}


			else
			{
				continue;
			}

		}


		else if (n == 20)
		{

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (game[i][j] == -1)
					{
						if (temp[i][j] == -1)
						{
							count++;
						}
					}
				}
			}
			if (count == 50)
			{
				{


					system("cls");

					int g = 500;
					reset();
					wprintf(L"     ");

					for (int i = 0; i < n; i++)
					{
						if (i < 10)	wprintf(L" %d    ", i);
						else wprintf(L"%d    ", i);
					}

					wprintf(L"\n");



					for (int i = 0; i < n; i++)
					{
						orange();
						if (i < 10) wprintf(L" %d", i);
						else wprintf(L"%d", i);
						reset();
						wprintf(L" | ");


						for (int j = 0; j < n; j++)
						{
							if (game[i][j] != -1 && game[i][j] != 0)
							{
								if (game[i][j] == 1) cyan();
								if (game[i][j] == 2) greenb();
								if (game[i][j] == 3) dyellow();
								if (game[i][j] == 4) orange();
								if (game[i][j] == 5) pink();
								if (game[i][j] == 6) blue();
								if (game[i][j] == 7) purple();
								if (game[i][j] == 8) red();


								wprintf(L" %d ", game[i][j]);
								reset();
								wprintf(L" | ");

							}
							else if (game[i][j] == 0)
							{
								reset();
								wprintf(L"    | ");
							}
							else if (game[i][j] == -1)
							{
								purple();
								wprintf(L" \x2660 ");
								reset();
								wprintf(L" | ");
							}
							else if (temp[i][j] == 0)
							{
								pink();
								wprintf(L" - ");

								reset();
								wprintf(L" | ");
							}
						}
						wprintf(L"\n\n");


						Sleep(300);
						Beep(g, 300);
						//_getch();
						g += 30;



					}




					return 1;

				}
			}

			else
			{
				continue;
			}

		}





	} while (game[x][y] != -1 || temp[x][y] == -1  || ( d =='r' && temp[x][y] == 0  && game[x][y] == -1));



	int f = 300;

	/*ckeck bakhtan*/

	system("cls");


	if (game[x][y] == -1)
	{

		if (temp[x][y] == 1)
		{
		
			system("cls");
			red();
			wprintf(L"\nYou Lost!\n\n");


			reset();
			wprintf(L"     ");

			for (int i = 0; i < n; i++)
			{
				if (i < 10)	wprintf(L" %d    ", i);
				else wprintf(L"%d    ", i);
			}

			wprintf(L"\n");



			for (int i = 0; i < n; i++)
			{
				orange();
				if (i < 10) wprintf(L" %d", i);
				else wprintf(L"%d", i);
				reset();
				wprintf(L" | ");


				for (int j = 0; j < n; j++)
				{
					if (game[i][j] != -1 && game[i][j] != 0)
					{
						if (game[i][j] == 1) cyan();
						if (game[i][j] == 2) greenb();
						if (game[i][j] == 3) dyellow();
						if (game[i][j] == 4) orange();
						if (game[i][j] == 5) pink();
						if (game[i][j] == 6) blue();
						if (game[i][j] == 7) purple();
						if (game[i][j] == 8) red();


						wprintf(L" %d ", game[i][j]);
						reset();
						wprintf(L" | ");

					}
					else if (game[i][j] == 0)
					{
						reset();
						wprintf(L"    | ");
					}
					else if (game[i][j] == -1)
					{
						purple();
						wprintf(L" Ơ ");
						reset();
						wprintf(L" | ");
					}
					else if (temp[i][j] == 0)
					{
						pink();
						wprintf(L" - ");

						reset();
						wprintf(L" | ");
					}
				}
				wprintf(L"\n\n");


				Sleep(300);
				Beep(f, 300);
				//_getch();
				f += 50;

			}




			wprintf(L"\n");

			Sleep(5000);
			return 0;





		}



		
	}







}





 


int Play(char name[], int a, int b)
{
	char o[10], o2[10], o1[10] , o3[10];



	reset();

	wprintf(L"************************************************************************************************************************");

	greenb();

	wprintf(L"\n\t\t\t\t\t\t\t\bRules:\n\n\t\t\t\t\t\t\b\b-press l for left click\n\t\t\t\t\t\t\b\b-press r for right click\n\t\t\t\t\t\t\b\b-press c to check your flag\n\t\t\t\t\t\t\b\b-press any other charecter to exit\n\n");



	reset();

	wprintf(L"\n************************************************************************************************************************\n\n");



	aqua();
	wprintf(L"\n\t\t\t\t\t\t\t\bOptions:\n\n\t\t\t\t\t\t\t 9*9\n\n\t\t\t\t\t\t\t12*12\n\n\t\t\t\t\t\t\t20*20\n\n");




	reset();

	wprintf(L"\n************************************************************************************************************************\n\n\n");



	wprintf(L"\t\t\t\t\t\t\t ");

	blue();
	scanf("%s", &o);

	strcpy(o1, "9*9");

	strcpy(o2, "12*12");


	strcpy(o3, "20*20");



	if (strcmp(o, o1) == 0)
	{
		return Game(9 , name , a , b);
	}
	
	else if (strcmp(o, o2) == 0)
	{
		return Game(12 , name , a , b);
	}

	else if (strcmp(o, o3) == 0)
	{
		return Game(20, name, a, b);
	}

	
	else wprintf(L"\t\t\t\t\t\tWrong Qrder!\nPlease Try Again\n");
}







int main()
{
	_setmode(_fileno(stdout),
		_O_U8TEXT);
	
	int  a = 0, b = 0;
	
	char str[20], str1[20], str2[20], str3[20], str4[20], name[20], str5[20];


	orange();

	wprintf(L"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n");



	
	cyan();
	wprintf(L"\n\n\t\t\t\t\t\tEnter your name ");


	aqua();
	wprintf(L": \n\n\n\n\t\t\t\t\t\t\t\b\b");
	

	orange();
	gets(name);
	
	wprintf(L"\n");

	system("cls");




	pink();
	wprintf(L"°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°°•°•°•°•°•°•°°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°°•°•\n\n\n\n");



	cyan();
	wprintf(L"\n\n\n\t\t\t\t\t\t\bWelcome ");


	int i = 0;

	while (name[i] != '\0')
	{
		wprintf(L"%c", name[i]);
		i++;
	}

	wprintf(L" ! ^-^");






	pink();
	wprintf(L"\n\n\n\n\n\n\n°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°°•°•°•°•°•°•°°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°•°°•°•");





	Sleep(2000);

	strcpy(str1, "Name");
	strcpy(str2, "Status");
	strcpy(str3, "ChangeName");
	strcpy(str4, "Play");
	strcpy(str5, "end");



	while (strcmp(str, str5) != 0)
	{

		system("cls");




		//pink();

		//wprintf(L"************************************************************************************************************************");

		purple();
		wprintf(L"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n");




		gray();
		wprintf(L"\n\t1.");

		reset();
		wprintf(L"Info\t:");

		gray();
		wprintf(L"\n\n\n\t\t-");

		dyellow();
		wprintf(L"Name\n");

		gray();
		wprintf(L"\n\n\t\t-");

		greenb();
		wprintf(L"Status\n");

		gray();
		wprintf(L"\n\n\n\t2.");


		reset();
		wprintf(L"Menu\t:\n");

		gray();
		wprintf(L"\n\n\t\t-");

		orange();
		wprintf(L"ChangeName\n");

		gray();
		wprintf(L"\n\n\t\t-");

		purple();
		wprintf(L"Play	\n\n\n\n\t");



		reset();
		wprintf(L"What do  you want to do?\t");

		gray();
		wprintf(L"\n\n\n\n\t\t-");


		cyan();
		
	    scanf("%s", &str);



		system("cls");



		
		if (strcmp(str, str1) == 0) pName(name);

		
		else if (strcmp(str, str2) == 0) pStatus(a, b);
		
		else if (strcmp(str, str3) == 0) ChangeName(name);
		
		else if (strcmp(str, str4) == 0)
		{
			if (Play(name , a , b) == 1)
			{
				a++;


				greenb();
				wprintf(L"\nYou Won!\n\n");


			}


			else b++;
		}
		
		else if(strcmp(str, str5) != 0) wprintf(L"\n\n\n\t\tWrong Qrder!\n\t\tPlease Try Again\n");



		Sleep(3500);
	}
	


	return 0;
}
