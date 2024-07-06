#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;

void easynewgame(ifstream &fin,ifstream &finn, ofstream &pause, char **board,ofstream &high,char *name);

void mediumnewgame(ifstream &fin, ifstream &finn, ofstream &pause, char **board, ofstream &high, char *name);

void hardnewgame(ifstream &fin, ifstream &finn, ofstream &pause, char **board, ofstream &high, char* name);

void resumegame(ifstream &fin, ifstream &finn, ofstream &pause, char **board, ofstream &high, char* name);

void highscore(ifstream &high);

int main()
{
	char name[10] = { '\0' };

	cout << "\t\t\t-----------------------------------" << endl;
	cout << "\t\t\t| Welcome to the Word Search Game |" << endl;
	cout << "\t\t\t-----------------------------------" << endl << endl << endl;

	cout << "Note:" << endl;
	cout << "-----" << endl << endl;

	cout << "=> To pause the game at any moment during levels press: P or p " << endl << endl;
	cout << "=> Look for the longest words for eg. In the word stair there is also the word air but only stair will be valid" << endl << endl << endl << endl;

	cout << "Enter Your Name: ";
	cin >> name;

	char**board = new char*[10];

	for (int i = 0; i < 10; i++)
	{
		board[i] = new char[10];
	}

	system("CLS");

	for (int i = 0;; i++)
	{

		char option;

		cout << "      ------------------------" << endl;
		cout << "      |         Menu         |" << endl;
		cout << "      ------------------------" << endl << endl << endl;

		cout << "=> Press N for New Game" << endl;
		cout << "=> Press R to Resume Game" << endl;
		cout << "=> Press H for Highscore Board" << endl;
		cout << "=> Press E to Exit Game" << endl << endl << endl;

		cout << "Enter Your Desired Option: ";
		cin >> option;

		system("CLS");


		if (option == 'N' || option == 'n')
		{
			char level;

			cout << "Select Game Level: " << endl << endl << endl;
			cout << "=> Press E for Easy Game (words in forward sequence in same row and column)" << endl;
			cout << "=> Press M for Medium Game (words in both forward and backward sequence in same row and column) " << endl;
			cout << "=> Press H for Hard Game (words in both forward and backward sequence in rows, columns and diagnals)" << endl << endl << endl;
			cout << "Enter Desired Level You Want To Play: ";
			cin >> level;

			system("CLS");

			if (level == 'E' || level == 'e')
			{
				ifstream fin, finn;
				ofstream pause,high;

				easynewgame(fin, finn, pause, board,high,name);

			}

			else if (level == 'M' || level == 'm')
			{
				ifstream fin, finn;
				ofstream pause, high;

				mediumnewgame(fin, finn, pause, board, high, name);
			}

			else if (level == 'H' || level == 'h')
			{
				ifstream fin, finn;
				ofstream pause, high;

				hardnewgame(fin, finn, pause, board, high, name);
			}
			

		}

		else if (option == 'R' || option == 'r')
		{
			ifstream fin, finn;
			ofstream pause, high;

			resumegame(fin, finn, pause, board, high, name);
		}

		else if (option == 'H' || option == 'h')
		{
			ifstream high;
			highscore(high);
		}

		else if (option == 'E' || option == 'e')
		{
			cout << endl << endl;
			cout << "\t\t\t-----------------------------------------" << endl;
			cout << "\t\t\t|   Thanks For PLaying This Game !!!!   |" << endl;
	        cout << "\t\t\t-----------------------------------------" << endl << endl << endl;

			for (int i = 0; i < 10; i++)
			{
				delete[]board[i];
			}
			delete [] board;
			break;
		}

		else
		{
			cout << "Invalid Option... Enter Again." << endl << endl << endl << endl;
		}

	}
	system("pause");
	return 0;
}

void easynewgame(ifstream &fin, ifstream &finn, ofstream &pause, char **board, ofstream &high,char* name)
{
	fin.open("easyboard.txt");
	pause.open("pause.txt");
	high.open("highscore.txt",ios::app);

	int same, changes,changee;
	char rorc;

	for (int i = 0; i < 10; i++)                              //board reading
	{
		for (int j = 0; j < 10; j++)
		{
			fin >> board[i][j];
		}
	}

	int lives = 3;
	int score = 0;

	for (int k = 0;; k++)                                            //level
	{
		if (k == 0)
		{
			cout << "      -------------------------" << endl;
			cout << "      |       EASY MODE       |" << endl;
			cout << "      -------------------------" << endl << endl << endl;
		}

		if (score == 100)
		{
			cout << "Congrats Level Cleared !!!" << endl << endl;
			high << "=> Easy Game Score for " << name << " is: " << score << endl;
			high.close();
			break;
		}

		else if (lives == 0)
		{
			cout << "Lives Finished !!! Better luck next time." << endl << endl;
			high << "=> Easy Game Score for " << name << " is: " << score << endl;
			high.close();
			break;
		}

		else
		{

			for (int i = 0; i < 10; i++)                             //board printing
			{
				cout << "\t";

				for (int j = 0; j < 10; j++)
				{

					if (board[i][j] == '-')
					{
						cout << '-' << " ";
					}
					else
					{
						cout << board[i][j] << " ";
					}
				}
				cout << endl;
				
			}


			char guess[9] = { '\0' };
			finn.open("dictionaryeasy.txt");
			
			cout <<endl<< "Lives Left: " << lives << "\tScore: " << score;

			cout << endl << endl << "Enter Word (in small letters): ";               //word guessing
			cin >> guess;

			system("CLS");

			if (guess[0] == 'p' && guess[1] == '\0')
			{
				char pselect;

				cout << "      -------------------------" << endl;
				cout << "      |         PAUSE         |" << endl;
				cout << "      -------------------------" << endl << endl << endl;

				cout << "=> Press R to resume. " << endl;
				cout << "=> Press E to exit." << endl;

				cout << endl << "Select your option: ";
				cin >> pselect;

				if (pselect == 'r' || pselect == 'R')
				{
					system("CLS");
					continue;
				}

				else if (pselect == 'e' || pselect == 'E')
				{
					pause << "e" << endl;
					pause << lives << " " << score << endl;

					for (int i = 0; i < 10; i++)                           
					{

						for (int j = 0; j < 10; j++)
						{
							pause << board[i][j];
						}
						pause << endl;

					}
					system("CLS");
					pause.close();
					break;
				}

			}

			bool liveflag = 0;

			for (int q = 0;q<10; q++)
			{
				char read[9] = { '\0' };

				bool flag = 0;
				finn >> read >> rorc >> same >> changes >> changee;

				for (int r = 0; r<9; r++)
				{
					if (read[r] != guess[r])
					{
						flag = 1;
						break;
					}


				}

				if (flag == 0)
				{
					score += 10;
					liveflag = 1;
					
					if (rorc == 'R')
					{
						for (int z = same; z <= same; z++)
						{
							for (int y = changes; y <= changee; y++)
							{
								board[z][y] = '-';
							}
						}
						break;
					}
					else if (rorc == 'C')
					{
						for (int z = same; z <= same; z++)
						{
							for (int y = changes; y <= changee; y++)
							{
								board[y][z] = '-';
							}
						}
						break;
					}
				}


			}

			if (liveflag == 0)
			{
				lives--;
			}

			finn.close();
		}
	}
}

void mediumnewgame(ifstream &fin, ifstream &finn, ofstream &pause, char **board, ofstream &high, char *name)
{

	fin.open("mediumboard.txt");
	pause.open("pause.txt");
	high.open("highscore.txt", ios::app);

	int same, changes, changee;
	char rorc;

	for (int i = 0; i < 10; i++)                              //board reading
	{
		for (int j = 0; j < 10; j++)
		{
			fin >> board[i][j];
		}
	}

	int lives = 3;
	int score = 0;

	for (int k = 0;; k++)                                            //level
	{
		if (k == 0)
		{
			cout << "      -------------------------" << endl;
			cout << "      |     MEDIUM MODE       |" << endl;
			cout << "      -------------------------" << endl << endl << endl;
		}

		if (score == 100)
		{
			cout << "Congrats Level Cleared !!!" << endl << endl;
			high << "=> Medium Game Score for " << name << " is: " << score << endl;
			high.close();
			break;
		}

		else if (lives == 0)
		{
			cout << "Lives Finished !!! Better luck next time." << endl << endl;
			high << "=> Medium Game Score for " << name << " is: " << score << endl;
			high.close();
			break;
		}

		else
		{

			for (int i = 0; i < 10; i++)                             //board printing
			{
				cout << "\t";

				for (int j = 0; j < 10; j++)
				{

					if (board[i][j] == '-')
					{
						cout << '-' << " ";
					}
					else
					{
						cout << board[i][j] << " ";
					}
				}
				cout << endl;

			}


			char guess[9] = { '\0' };
			finn.open("dictionarymedium.txt");

			cout << endl << "Lives Left: " << lives << "\tScore: " << score;

			cout << endl << endl << "Enter Word (in small letters): ";               //word guessing
			cin >> guess;

			system("CLS");

			if (guess[0] == 'p' && guess[1] == '\0')
			{
				char pselect;

				cout << "      -------------------------" << endl;
				cout << "      |         PAUSE         |" << endl;
				cout << "      -------------------------" << endl << endl << endl;
				cout << "=> Press R to resume. " << endl;
				cout << "=> Press E to exit." << endl;

				cout << endl << "Select your option: ";
				cin >> pselect;

				if (pselect == 'r' || pselect == 'R')
				{
					system("CLS");
					continue;
				}

				else if (pselect == 'e' || pselect == 'E')
				{
					pause << "m" << endl;
					pause << lives << " " << score << endl;

					for (int i = 0; i < 10; i++)
					{

						for (int j = 0; j < 10; j++)
						{
							pause << board[i][j];
						}
						pause << endl;

					}
					system("CLS");
					pause.close();
					break;
				}

			}

			bool liveflag = 0;

			for (int q = 0; q<20; q++)
			{
				char read[9] = { '\0' };

				bool flag = 0;
				finn >> read >> rorc >> same >> changes >> changee;

				for (int r = 0; r<9; r++)
				{
					if (read[r] != guess[r])
					{
						flag = 1;
						break;
					}


				}

				if (flag == 0)
				{
					score += 10;
					liveflag = 1;

					if (rorc == 'R')
					{
						for (int z = same; z <= same; z++)
						{
							for (int y = changes; y <= changee; y++)
							{
								board[z][y] = '-';
							}
						}
						break;
					}
					else if (rorc == 'C')
					{
						for (int z = same; z <= same; z++)
						{
							for (int y = changes; y <= changee; y++)
							{
								board[y][z] = '-';
							}
						}
						break;
					}
				}


			}

			if (liveflag == 0)
			{
				lives--;
			}

			finn.close();
		}
	}
}

void hardnewgame(ifstream &fin, ifstream &finn, ofstream &pause, char **board, ofstream &high, char* name)
{

	fin.open("hardboard.txt");
	pause.open("pause.txt");
	high.open("highscore.txt", ios::app);

	int same, changes, changee;
	char rorc;

	for (int i = 0; i < 10; i++)                              //board reading
	{
		for (int j = 0; j < 10; j++)
		{
			fin >> board[i][j];
		}
	}

	int lives = 3;
	int score = 0;

	for (int k = 0;; k++)                                            //level
	{
		if (k == 0)
		{
			cout << "      -------------------------" << endl;
			cout << "      |       HARD MODE       |" << endl;
			cout << "      -------------------------" << endl << endl << endl;
		}

		if (score == 100)
		{
			cout << "Congrats Level Cleared !!!" << endl << endl;
			high << "=> Hard Game Score for " << name << " is: " << score << endl;
			high.close();
			break;
		}

		else if (lives == 0)
		{
			cout << "Lives Finished !!! Better luck next time." << endl << endl;
			high << "=> Hard Game Score for " << name << " is: " << score << endl;
			high.close();
			break;
		}

		else
		{

			for (int i = 0; i < 10; i++)                             //board printing
			{
				cout << "\t";

				for (int j = 0; j < 10; j++)
				{

					if (board[i][j] == '-')
					{
						cout << '-' << " ";
					}
					else
					{
						cout << board[i][j] << " ";
					}
				}
				cout << endl;

			}


			char guess[9] = { '\0' };
			finn.open("dictionaryhard.txt");

			cout << endl << "Lives Left: " << lives << "\tScore: " << score;

			cout << endl << endl << "Enter Word (in small letters): ";               //word guessing
			cin >> guess;

			system("CLS");

			if (guess[0] == 'p' && guess[1] == '\0')
			{
				char pselect;

				cout << "      -------------------------" << endl;
				cout << "      |         PAUSE         |" << endl;
				cout << "      -------------------------" << endl << endl << endl;
				cout << "=> Press R to resume. " << endl;
				cout << "=> Press E to exit." << endl;

				cout << endl << "Select your option: ";
				cin >> pselect;

				if (pselect == 'r' || pselect == 'R')
				{
					system("CLS");
					continue;
				}

				else if (pselect == 'e' || pselect == 'E')
				{
					pause << "h" << endl;
					pause << lives << " " << score << endl;

					for (int i = 0; i < 10; i++)
					{

						for (int j = 0; j < 10; j++)
						{
							pause << board[i][j];
						}
						pause << endl;

					}
					system("CLS");
					pause.close();
					break;
				}

			}

			bool liveflag = 0;

			for (int q = 0; q<20; q++)
			{
				char read[9] = { '\0' };

				bool flag = 0;
				finn >> read >> rorc >> same >> changes >> changee;

				for (int r = 0; r<9; r++)
				{
					if (read[r] != guess[r])
					{
						flag = 1;
						break;
					}


				}

				if (flag == 0)
				{
					score += 10;
					liveflag = 1;

					if (rorc == 'R')
					{
						for (int z = same; z <= same; z++)
						{
							for (int y = changes; y <= changee; y++)
							{
								board[z][y] = '-';
							}
						}
						break;
					}
					else if (rorc == 'C')
					{
						for (int z = same; z <= same; z++)
						{
							for (int y = changes; y <= changee; y++)
							{
								board[y][z] = '-';
							}
						}
						break;
					}

					else if (rorc == 'D')
					{
						int z = same, y = changes;
						for (int i = 0; i < changee; i++)
						{
							board[same][changes] = '-';
							same++;
							changes++;
						}
						break;
					}
				}


			}

			if (liveflag == 0)
			{
				lives--;
			}

			finn.close();
		}
	}
}

void highscore(ifstream &high)
{
	high.open("highscore.txt");
	char line[50] = { '\0' };


	for (int i = 0;i<5; i++)
	{
		if (high.eof())
		{
			break;
		}

		
		high.getline(line,50);

		cout << line << endl;
		
	}

	cout << endl << endl;
}

void resumegame(ifstream &fin, ifstream &finn, ofstream &pause, char **board, ofstream &high, char* name)
{
	fin.open("pause.txt");
	char level;

	fin >> level;

	if (level == 'e')
	{ 

		pause.open("pause.txt");
		high.open("highscore.txt", ios::app);

		int same, changes, changee;
		char rorc;
		int lives ;
		int score ;

		fin >> lives >> score;

		for (int i = 0; i < 10; i++)                              //board reading
		{
			for (int j = 0; j < 10; j++)
			{
				fin >> board[i][j];
			}
		}


		for (int k = 0;; k++)                                            //level
		{
			if (k == 0)
			{
				cout << "      -------------------------" << endl;
				cout << "      |       EASY MODE       |" << endl;
				cout << "      -------------------------" << endl << endl << endl;
			}

			if (score == 100)
			{
				cout << "Congrats Level Cleared !!!" << endl << endl;
				high << "=> Easy Game Score for " << name << " is: " << score << endl;
				high.close();
				break;
			}

			else if (lives == 0)
			{
				cout << "Lives Finished !!! Better luck next time." << endl << endl;
				high << "=> Easy Game Score for " << name << " is: " << score << endl;
				high.close();
				break;
			}

			else
			{

				for (int i = 0; i < 10; i++)                             //board printing
				{
					cout << "\t";

					for (int j = 0; j < 10; j++)
					{

						if (board[i][j] == '-')
						{
							cout << '-' << " ";
						}
						else
						{
							cout << board[i][j] << " ";
						}
					}
					cout << endl;

				}


				char guess[9] = { '\0' };
				finn.open("dictionaryeasy.txt");

				cout << endl << "Lives Left: " << lives << "\tScore: " << score;

				cout << endl << endl << "Enter Word (in small letters): ";               //word guessing
				cin >> guess;

				system("CLS");

				if (guess[0] == 'p' && guess[1] == '\0')
				{
					char pselect;

					cout << "      -------------------------" << endl;
					cout << "      |         PAUSE         |" << endl;
					cout << "      -------------------------" << endl << endl << endl;

					cout << "=> Press R to resume. " << endl;
					cout << "=> Press E to exit." << endl;

					cout << endl << "Select your option: ";
					cin >> pselect;

					if (pselect == 'r' || pselect == 'R')
					{
						system("CLS");
						continue;
					}

					else if (pselect == 'e' || pselect == 'E')
					{
						pause << "e" << endl;
						pause << lives << " " << score << endl;

						for (int i = 0; i < 10; i++)
						{

							for (int j = 0; j < 10; j++)
							{
								pause << board[i][j];
							}
							pause << endl;

						}
						system("CLS");
						pause.close();
						break;
					}

				}

				bool liveflag = 0;

				for (int q = 0; q<10; q++)
				{
					char read[9] = { '\0' };

					bool flag = 0;
					finn >> read >> rorc >> same >> changes >> changee;

					for (int r = 0; r<9; r++)
					{
						if (read[r] != guess[r])
						{
							flag = 1;
							break;
						}


					}

					if (flag == 0)
					{
						score += 10;
						liveflag = 1;

						if (rorc == 'R')
						{
							for (int z = same; z <= same; z++)
							{
								for (int y = changes; y <= changee; y++)
								{
									board[z][y] = '-';
								}
							}
							break;
						}
						else if (rorc == 'C')
						{
							for (int z = same; z <= same; z++)
							{
								for (int y = changes; y <= changee; y++)
								{
									board[y][z] = '-';
								}
							}
							break;
						}
					}


				}

				if (liveflag == 0)
				{
					lives--;
				}

				finn.close();
			}
		}
	}



	else if (level == 'm')
	{
		
		pause.open("pause.txt");
		high.open("highscore.txt", ios::app);

		int same, changes, changee;
		char rorc;

		int lives ;
		int score ;

		fin >> lives >> score;

		for (int i = 0; i < 10; i++)                              //board reading
		{
			for (int j = 0; j < 10; j++)
			{
				fin >> board[i][j];
			}
		}

		

		for (int k = 0;; k++)                                            //level
		{
			if (k == 0)
			{
				cout << "      -------------------------" << endl;
				cout << "      |     MEDIUM MODE       |" << endl;
				cout << "      -------------------------" << endl << endl << endl;
			}


			if (score == 100)
			{
				cout << "Congrats Level Cleared !!!" << endl << endl;
				high << "=> Medium Game Score for " << name << " is: " << score << endl;
				high.close();
				break;
			}

			else if (lives == 0)
			{
				cout << "Lives Finished !!! Better luck next time." << endl << endl;
				high << "=> Medium Game Score for " << name << " is: " << score << endl;
				high.close();
				break;
			}

			else
			{

				for (int i = 0; i < 10; i++)                             //board printing
				{
					cout << "\t";

					for (int j = 0; j < 10; j++)
					{

						if (board[i][j] == '-')
						{
							cout << '-' << " ";
						}
						else
						{
							cout << board[i][j] << " ";
						}
					}
					cout << endl;

				}


				char guess[9] = { '\0' };
				finn.open("dictionarymedium.txt");

				cout << endl << "Lives Left: " << lives << "\tScore: " << score;

				cout << endl << endl << "Enter Word (in small letters): ";               //word guessing
				cin >> guess;

				system("CLS");

				if (guess[0] == 'p' && guess[1] == '\0')
				{
					char pselect;

					cout << "      -------------------------" << endl;
					cout << "      |         PAUSE         |" << endl;
					cout << "      -------------------------" << endl << endl << endl;

					cout << "=> Press R to resume. " << endl;
					cout << "=> Press E to exit." << endl;

					cout << endl << "Select your option: ";
					cin >> pselect;

					if (pselect == 'r' || pselect == 'R')
					{
						system("CLS");
						continue;
					}

					else if (pselect == 'e' || pselect == 'E')
					{
						pause << "m" << endl;
						pause << lives << " " << score << endl;

						for (int i = 0; i < 10; i++)
						{

							for (int j = 0; j < 10; j++)
							{
								pause << board[i][j];
							}
							pause << endl;

						}
						system("CLS");
						pause.close();
						break;
					}

				}

				bool liveflag = 0;

				for (int q = 0; q<20; q++)
				{
					char read[9] = { '\0' };

					bool flag = 0;
					finn >> read >> rorc >> same >> changes >> changee;

					for (int r = 0; r<9; r++)
					{
						if (read[r] != guess[r])
						{
							flag = 1;
							break;
						}


					}

					if (flag == 0)
					{
						score += 10;
						liveflag = 1;

						if (rorc == 'R')
						{
							for (int z = same; z <= same; z++)
							{
								for (int y = changes; y <= changee; y++)
								{
									board[z][y] = '-';
								}
							}
							break;
						}
						else if (rorc == 'C')
						{
							for (int z = same; z <= same; z++)
							{
								for (int y = changes; y <= changee; y++)
								{
									board[y][z] = '-';
								}
							}
							break;
						}
					}


				}

				if (liveflag == 0)
				{
					lives--;
				}

				finn.close();
			}
		}
	}




	else if (level == 'h')
	{

		pause.open("pause.txt");
		high.open("highscore.txt", ios::app);

		int same, changes, changee;
		char rorc;

		int lives ;
		int score ;

		fin >> lives >> score;

		for (int i = 0; i < 10; i++)                              //board reading
		{
			for (int j = 0; j < 10; j++)
			{
				fin >> board[i][j];
			}
		}


		for (int k = 0;; k++)                                            //level
		{

			if (k == 0)
			{
				cout << "      -------------------------" << endl;
				cout << "      |       HARD MODE       |" << endl;
				cout << "      -------------------------" << endl << endl << endl;
			}

			if (score == 100)
			{
				cout << "Congrats Level Cleared !!!" << endl << endl;
				high << "=> Hard Game Score for " << name << " is: " << score << endl;
				high.close();
				break;
			}

			else if (lives == 0)
			{
				cout << "Lives Finished !!! Better luck next time." << endl << endl;
				high << "=> Hard Game Score for " << name << " is: " << score << endl;
				high.close();
				break;
			}

			else
			{

				for (int i = 0; i < 10; i++)                             //board printing
				{
					cout << "\t";

					for (int j = 0; j < 10; j++)
					{

						if (board[i][j] == '-')
						{
							cout << '-' << " ";
						}
						else
						{
							cout << board[i][j] << " ";
						}
					}
					cout << endl;

				}


				char guess[9] = { '\0' };
				finn.open("dictionaryhard.txt");

				cout << endl << "Lives Left: " << lives << "\tScore: " << score;

				cout << endl << endl << "Enter Word (in small letters): ";               //word guessing
				cin >> guess;

				system("CLS");

				if (guess[0] == 'p' && guess[1] == '\0')
				{
					char pselect;


					cout << "      -------------------------" << endl;
					cout << "      |         PAUSE         |" << endl;
					cout << "      -------------------------" << endl << endl << endl;

					cout << "=> Press R to resume. " << endl;
					cout << "=> Press E to exit." << endl;

					cout << endl << "Select your option: ";
					cin >> pselect;

					if (pselect == 'r' || pselect == 'R')
					{
						system("CLS");
						continue;
					}

					else if (pselect == 'e' || pselect == 'E')
					{
						pause << "h" << endl;
						pause << lives << " " << score << endl;

						for (int i = 0; i < 10; i++)
						{

							for (int j = 0; j < 10; j++)
							{
								pause << board[i][j];
							}
							pause << endl;

						}
						system("CLS");
						pause.close();
						break;
					}

				}

				bool liveflag = 0;

				for (int q = 0; q<20; q++)
				{
					char read[9] = { '\0' };

					bool flag = 0;
					finn >> read >> rorc >> same >> changes >> changee;

					for (int r = 0; r<9; r++)
					{
						if (read[r] != guess[r])
						{
							flag = 1;
							break;
						}


					}

					if (flag == 0)
					{
						score += 10;
						liveflag = 1;

						if (rorc == 'R')
						{
							for (int z = same; z <= same; z++)
							{
								for (int y = changes; y <= changee; y++)
								{
									board[z][y] = '-';
								}
							}
							break;
						}
						else if (rorc == 'C')
						{
							for (int z = same; z <= same; z++)
							{
								for (int y = changes; y <= changee; y++)
								{
									board[y][z] = '-';
								}
							}
							break;
						}

						else if (rorc == 'D')
						{
							int z = same, y = changes;
							for (int i = 0; i < changee; i++)
							{
								board[same][changes] = '-';
								same++;
								changes++;
							}
							break;
						}
					}


				}

				if (liveflag == 0)
				{
					lives--;
				}

				finn.close();
			}
		}
	}
}