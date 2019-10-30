
/*
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>




int checkPlayer(int i, int j);
bool checkVert(); //checks to see if a connect 4 has been made vertically
bool checkHoz(); //checks to see if a connect 4 has been made horizontally
bool checkDiagRight(); //checks to see if a connect 4 has been made in a right diagonal
bool checkDiagLeft(); //checks to see if a connect 4 has been made in a right diagonal
bool hasWon();
void printGame();
#define ROW 6
#define COLUMN 7
std::string connect[ROW][COLUMN];

std::string playerTurn = "One";



sf::CircleShape CircleMatrix[ROW][COLUMN];

sf::RectangleShape board;

sf::RectangleShape Buttons[COLUMN];

int global;
int rowStart;

int main() {

	sf::RenderWindow game(sf::VideoMode(1250, 850), "board");
	board.setPosition(50, 10);
	board.setSize(sf::Vector2f(950, 750));
	board.setFillColor(sf::Color::White);

	sf::Texture Buttons;
	Buttons.loadFromFile("Textures/col1.png");


	sf::Sprite interact[COLUMN];
	for (int i = 0; i < COLUMN; i++) {
		interact[i].setTexture(Buttons);
		interact[i].setPosition(sf::Vector2f(100 + i * 125, 25));
	}

	for (int i = 0; i < ROW; i++) {

		for (int j = 0; j < COLUMN; j++) {

			connect[i][j] = "_";
		}

	}


	for (int i = 0; i < ROW; i++) {

		for (int j = 0; j < COLUMN; j++) {

			CircleMatrix[i][j].setFillColor(sf::Color::Black);
			CircleMatrix[i][j].setRadius(40);
			CircleMatrix[i][j].setPosition(sf::Vector2f(100 + j * 125, 75 + i * 110));

		}
	}




	


	
	while (game.isOpen()) {
		sf::Event turnOff;

		while (game.pollEvent(turnOff)) {
			if (turnOff.type == sf::Event::Closed) {
				game.close();
			}

			

			game.clear();
			game.draw(board);
			for (int i = 0; i < ROW; i++) {

				for (int j = 0; j < COLUMN; j++) {

					game.draw(CircleMatrix[i][j]);
				}
			}



			for (int i = 0; i < COLUMN; i++) {
				game.draw(interact[i]);
			}
			game.display();

			
			

			



				if (turnOff.type == sf::Event::MouseButtonPressed) {
					auto mouse_pos = sf::Mouse::getPosition(game);
					auto translated_pos = game.mapPixelToCoords(mouse_pos);
					rowStart = -1;
					for (int i = 0; i < COLUMN; i++) {
						if (interact[i].getGlobalBounds().contains(translated_pos))
						{
							global = i;
							
							
							for (int j = 0; j < ROW; j++) {
								

								if (connect[j][global] == "X" || connect[j][global] == "O") 
								{
									std::cout << "Pick a different choice.\n";
									break;
								}
								
								else if (connect[j][global] == "_")
								{
									rowStart = j;
									continue;
									
								}
								
							}

						}
						if (rowStart != -1) {
							break;
						}
					}

					if (rowStart == -1) {
						continue;
						}


					
				
					if (playerTurn == "One")
					{
						connect[rowStart][global] = "X";
					}
					else if (playerTurn == "Two")
					{
						connect[rowStart][global] = "O";
					}
					
					for (int i = 0; i < ROW; i++) {
						for (int j = 0; j < COLUMN; j++) {
							if (connect[i][j] == "X") {

								CircleMatrix[i][j].setFillColor(sf::Color::Red);

							}

							else if (connect[i][j] == "O") {

								CircleMatrix[i][j].setFillColor(sf::Color::Yellow);
							}
						}
					}
					
					game.clear();
					game.draw(board);
					for (int i = 0; i < ROW; i++) {

						for (int j = 0; j < COLUMN; j++) {

							game.draw(CircleMatrix[i][j]);
						}
					}



					for (int i = 0; i < COLUMN; i++) {
						game.draw(interact[i]);
					}
					game.display();

					if (hasWon() == true) {
						std::cout << "Player " << playerTurn << " has won!" << std::endl;
						system("pause");
						return 0;
					}

					else {
						if (playerTurn == "One") {
							playerTurn = "Two";
							continue;
						}

						else if (playerTurn == "Two") {
							playerTurn = "One";
							continue;
						}
					}
					
				}

		}

	}

}


int checkPlayer(int i, int j) {

	if (connect[i][j] == "X") {
		return 1;
	}
	else if (connect[i][j] == "O") {
		return 2;
	}

	else {
		return 0;
	}
}




bool checkVert() {

	//the nested for loops should be flipped because you want to go up via the rows for every column (i.e. col = 1, go through row 0 through row ROW-4 first)
	for (int col = 0; col < COLUMN; col++)
	{
		for (int row = 0; row <= ROW - 4; row++)
		{
			if (checkPlayer(row, col) == 1 && checkPlayer(row + 1, col) == 1 && checkPlayer(row + 2, col) == 1 && checkPlayer(row + 3, col) == 1) {
				return true;
			}

			else if (checkPlayer(row, col) == 2 && checkPlayer(row + 1, col) == 2 && checkPlayer(row + 2, col) == 2 && checkPlayer(row + 3, col) == 2) {
				return true;
			}
		}
	}
	return false; //this return 2 is here because if the for-loops finish iterating without returning 1, then by default it will return 2
}

bool checkHoz() {

	//the nested for loops should be flipped because you want to go to the right via the columns for each row (i.e. row = 1, go through col 0 through col COLUMN-4 first)
	//FIXED VERSION:
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col <= COLUMN - 4; col++)
		{
			if (checkPlayer(row, col) == 1 && checkPlayer(row, col + 1) == 1 && checkPlayer(row, col + 2) == 1 && checkPlayer(row, col + 3) == 1) {
				return true;
			}

			else if (checkPlayer(row, col) == 2 && checkPlayer(row, col + 1) == 2 && checkPlayer(row, col + 2) == 2 && checkPlayer(row, col + 3) == 2) {
				return true;
			}
		}
	}
	return false; //this return 2 is here because if the for-loops finish iterating without returning 1, then by default it will return 2



}

bool checkDiagRight() {
	for (int row = 0; row < 3; row++) {

		for (int col = 0; col < 4; col++) {

			if (checkPlayer(row, col) == 1 && checkPlayer(row + 1, col + 1) == 1 && checkPlayer(row + 2, col + 2) == 1 && checkPlayer(row + 3, col + 3) == 1) {
				return true;
			}

			else if (checkPlayer(row, col) == 2 && checkPlayer(row + 1, col + 1) == 2 && checkPlayer(row + 2, col + 2) == 2 && checkPlayer(row + 3, col + 3) == 2) {
				return true;

			}


		}
	}
	return false;
}

bool checkDiagLeft() {
	for (int row = 0; row < 3; row++) {

		for (int col = 3; col < COLUMN; col++) {

			if (checkPlayer(row, col) == 1 && checkPlayer(row + 1, col - 1) == 1 && checkPlayer(row + 2, col - 2) == 1 && checkPlayer(row + 3, col - 3) == 1) {
				return true;
			}

			else if (checkPlayer(row, col) == 2 && checkPlayer(row + 1, col - 1) == 2 && checkPlayer(row + 2, col - 2) == 2 && checkPlayer(row + 3, col - 3) == 2) {
				return true;

			}

		}
	}
	return false;

}

bool hasWon() {
	if (checkVert() == true || checkHoz() == true || checkDiagRight() == true || checkDiagLeft() == true) {
		return true;
	}
	else {
		return false;
	}
}


void printGame() {

	std::cout << " __1__ __2__ __3__ __4__ __5__ __6__ __7__  \n";
	std::cout << "|     |     |     |     |     |     |     | \n";
	std::cout << "|__" << connect[5][0] << "__|__" << connect[5][1] << "__|__" << connect[5][2] << "__|__" << connect[5][3] << "__|__" << connect[5][4] << "__|__" << connect[5][5] << "__|__" << connect[5][6] << "__| \n";
	std::cout << "|     |     |     |     |     |     |     | \n";
	std::cout << "|__" << connect[4][0] << "__|__" << connect[4][1] << "__|__" << connect[4][2] << "__|__" << connect[4][3] << "__|__" << connect[4][4] << "__|__" << connect[4][5] << "__|__" << connect[4][6] << "__| \n";
	std::cout << "|     |     |     |     |     |     |     | \n";
	std::cout << "|__" << connect[3][0] << "__|__" << connect[3][1] << "__|__" << connect[3][2] << "__|__" << connect[3][3] << "__|__" << connect[3][4] << "__|__" << connect[3][5] << "__|__" << connect[3][6] << "__| \n";
	std::cout << "|     |     |     |     |     |     |     | \n";
	std::cout << "|__" << connect[2][0] << "__|__" << connect[2][1] << "__|__" << connect[2][2] << "__|__" << connect[2][3] << "__|__" << connect[2][4] << "__|__" << connect[2][5] << "__|__" << connect[2][6] << "__| \n";
	std::cout << "|     |     |     |     |     |     |     | \n";
	std::cout << "|__" << connect[1][0] << "__|__" << connect[1][1] << "__|__" << connect[1][2] << "__|__" << connect[1][3] << "__|__" << connect[1][4] << "__|__" << connect[1][5] << "__|__" << connect[1][6] << "__| \n";
	std::cout << "|     |     |     |     |     |     |     | \n";
	std::cout << "|__" << connect[0][0] << "__|__" << connect[0][1] << "__|__" << connect[0][2] << "__|__" << connect[0][3] << "__|__" << connect[0][4] << "__|__" << connect[0][5] << "__|__" << connect[0][6] << "__| \n";
}
*/
