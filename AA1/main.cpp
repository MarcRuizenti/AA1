#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <vector>


enum Scene { INTRO, NAVIGATION, COMBAT, BOSS};

#define SIZE 10
int currentScene = INTRO;
using namespace std;


struct Player {
	string name;
	int Y;
	int X;
	int maxHealth;
	int health;
	int potion;
	int bomb;
	bool sword;
	bool key;
};

enum Raze { GOBLIN, ORC, TROLL, DEMON };
struct Enemigos {
	Raze raze;
	string name;
	int health;
	int maxHealth;
	int damage;
};


void whatwillyoudo(Player& player, bool n = false, bool w = false, bool e = false, bool s = false, char m[][SIZE] = {});
void whatwillyoudoCombat(Player& player, Enemigos& ene);
void Intro(Player& player);
void Navigation(Player& player, char map[][SIZE]);
void Combat(Player& p, char m[][SIZE]);
void Boss(Player& p);


int main() {
	char map[SIZE][SIZE]{
		{'#','#','#','#','#','#','#','#','#','#'},
		{'#','.','.','P','.','P','.','.','.','#'},
		{'#','#','#','G','#','S','#','#','P','#'},
		{'#','.','.','.','#','#','#','#','#','#'},
		{'#','.','T','.','#','J','#','.','B','#'},
		{'#','.','.','.','#','L','#','.','.','#'},
		{'#','#','.','#','#','.','#','T','T','#'},
		{'#','P','G','#','#','O','#','.','.','#'},
		{'#','.','.','.','.','K','.','.','B','#'},
		{'#','#','#','#','#','#','#','#','#','#'},
	};


	Player player{
		"Luis",
		4,
		5,
		100,
		100,
		0,
		0,
		false,
		true
	};

	while (true) {
		if (currentScene == INTRO) {
			Intro(player);
		}
		else if (currentScene == NAVIGATION) {
			Navigation(player, map);
		}
		else if (currentScene == COMBAT) {
			Combat(player, map);
		}
		else if (currentScene == BOSS) {
			Boss(player);
		}

		else {
			return 0;
		}
	}
}

void Intro(Player& player) {

	cout << "------------ H E R O ' S  Q U E S T ------------" << endl;
	cout << "The protagonist must go through an adventure that will lead him to encounter difficulties." << endl << endl;
	cout << "On his journey he will find tools to fight against the monsters," << endl;
	cout << "that await him until he reaches the final objective, the demon" << endl;
	cout << "threatens to wipe out all humans if they do not heed his requests." << endl << endl;
	cout << "As a hero you must defeat him to save the world from despair." << endl << endl;
	cout << "Use the HELP command to show the options " << endl;
	cout << "------------------------------------------------" << endl;
	cout << "May I ask your name, brave hero? ";
	cin >> player.name;
	cin.ignore();
	cout << " " << endl;
	currentScene = NAVIGATION;
}

void Navigation(Player& player, char map[][SIZE]) {

	if (map[player.Y][player.X] == 'J')
		currentScene = BOSS;
	else if (map[player.Y][player.X] != 'G' && map[player.Y][player.X] != 'O' && map[player.Y][player.X] != 'T') {
		system("cls");

		cout << "[" << player.name << "]" << " at " << "[" << player.X << ", " << player.Y << "]" << endl;

		if (player.Y < 5 && player.X < 6)
			cout << "The penchant detects an evil aura at southeast" << endl;
		else if (player.Y > 5 && player.X < 6)
			cout << "The penchant detects an evil aura at northeast" << endl;
		else if (player.Y > 5 && player.X > 6)
			cout << "The penchant detects an evil aura at northwest" << endl;
		else if (player.Y < 5 && player.X > 6)
			cout << "The penchant detects an evil aura at southwest" << endl;
		else if (player.Y < 5 && player.X == 6)
			cout << "The penchant detects an evil aura at south" << endl;
		else if (player.Y > 5 && player.X == 6)
			cout << "The penchant detects an evil aura at north" << endl;
		else if (player.Y == 5 && player.X < 6)
			cout << "The penchant detects an evil aura at east" << endl;
		else if (player.Y == 5 && player.X > 6)
			cout << "The penchant detects an evil aura at west" << endl;

		cout << "You can go: ";
		bool north = map[player.Y - 1][player.X] == '#' || map[player.Y - 1][player.X] == 'L';
		bool west = map[player.Y][player.X - 1] == '#' || map[player.Y - 1][player.X] == 'L';
		bool east = map[player.Y][player.X + 1] == '#' || map[player.Y - 1][player.X] == 'L';
		bool south = map[player.Y + 1][player.X] == '#';

		if (!north) {
			cout << "[NORTH]";
		}
		if (!west) {
			cout << "[WEST]";
		}
		if (!east) {
			cout << "[EAST]";
		}
		if (!south) {
			cout << "[SOUTH]";
		}
		cout << endl;


		if (map[player.Y][player.X] == 'P')
			cout << "There is a Potion on the floor" << endl;
		else if (map[player.Y][player.X] == 'B')
			cout << "There is a Bomb on the floor" << endl;
		else if (map[player.Y][player.X] == 'K')
			cout << "There is a Key on the floor" << endl;
		else if (map[player.Y][player.X] == 'S')
			cout << "There is a Sword on the floor" << endl;

		if (map[player.Y - 1][player.X] == 'P')
			cout << "There is a Potion at north" << endl;
		else if (map[player.Y - 1][player.X] == 'B')
			cout << "There is a Bomb at north" << endl;
		else if (map[player.Y - 1][player.X] == 'K')
			cout << "There is a Key at north" << endl;
		else if (map[player.Y - 1][player.X] == 'S')
			cout << "There is a Sword at north" << endl;
		else if (map[player.Y - 1][player.X] == 'G')
			cout << "There is a Goblin at north" << endl;
		else if (map[player.Y - 1][player.X] == 'O')
			cout << "There is a Orc at north" << endl;
		else if (map[player.Y - 1][player.X] == 'T')
			cout << "There is a Troll at north" << endl;
		else if (map[player.Y - 1][player.X] == 'L')
			cout << "There is a lock door in north" << endl;
		else if (map[player.Y - 1][player.X] == 'J')
			cout << "There is a devyl aura is too potent in north" << endl;

		if (map[player.Y + 1][player.X] == 'P')
			cout << "There is a Potion at south" << endl;
		else if (map[player.Y + 1][player.X] == 'B')
			cout << "There is a Bomb at south" << endl;
		else if (map[player.Y + 1][player.X] == 'K')
			cout << "There is a Key at south" << endl;
		else if (map[player.Y + 1][player.X] == 'S')
			cout << "There is a Sword at south" << endl;
		else if (map[player.Y + 1][player.X] == 'G')
			cout << "There is a Goblin at south" << endl;
		else if (map[player.Y + 1][player.X] == 'O')
			cout << "There is a Orc at south" << endl;
		else if (map[player.Y + 1][player.X] == 'T')
			cout << "There is a Troll at south" << endl;

		if (map[player.Y][player.X - 1] == 'P')
			cout << "There is a Potion at west" << endl;
		else if (map[player.Y][player.X - 1] == 'B')
			cout << "There is a Bomb at west" << endl;
		else if (map[player.Y][player.X - 1] == 'K')
			cout << "There is a Key at west" << endl;
		else if (map[player.Y][player.X - 1] == 'S')
			cout << "There is a Sword at west" << endl;
		else if (map[player.Y][player.X - 1] == 'G')
			cout << "There is a Goblin at west" << endl;
		else if (map[player.Y][player.X - 1] == 'O')
			cout << "There is a Orc at west" << endl;
		else if (map[player.Y][player.X - 1] == 'T')
			cout << "There is a Troll at west" << endl;

		if (map[player.Y][player.X + 1] == 'P')
			cout << "There is a Potion at east" << endl;
		else if (map[player.Y][player.X + 1] == 'B')
			cout << "There is a Bomb at east" << endl;
		else if (map[player.Y][player.X + 1] == 'K')
			cout << "There is a Key at east" << endl;
		else if (map[player.Y][player.X + 1] == 'S')
			cout << "There is a Sword at east" << endl;
		else if (map[player.Y][player.X + 1] == 'G')
			cout << "There is a Goblin at east" << endl;
		else if (map[player.Y][player.X + 1] == 'O')
			cout << "There is a Orc at east" << endl;
		else if (map[player.Y][player.X + 1] == 'T')
			cout << "There is a Troll at east" << endl;

		whatwillyoudo(player, !north, !west, !east, !south, map);
		
	}
	else {
		currentScene = COMBAT;
	}
}

void Combat(Player& p, char m[][SIZE]) {

	Raze razeEnemigo = ORC;

	Enemigos enemigo[3]{
		{GOBLIN, "Goblin", 30, 30, 5},
		{ORC, "Orco", 80, 80, 15},
		{TROLL, "Troll", 60, 60, 10}
	};

	Enemigos enemigoActual;

	if (m[p.Y][p.X] == 'G')
		razeEnemigo = GOBLIN;
	else if (m[p.Y][p.X] == 'O')
		razeEnemigo = ORC;
	else if (m[p.Y][p.X] == 'T')
		razeEnemigo = TROLL;

	for (int i = 0; i < 3; i++) {
		if (razeEnemigo == enemigo[i].raze)
			enemigoActual = enemigo[i];
	}

	cout << enemigoActual.name << " attacks!" << endl;
	cout << enemigoActual.name << " use Slash!" << endl;
	cout << p.name << " recived " << enemigoActual.damage * 2 << " damage" << endl;

	p.health -= enemigoActual.damage * 2;
	
	system("pause");

	cout << "------------ En batalla ------------" << endl;

	while (true) {
		system("cls");

		cout << "[" << p.name << "] HP:[" << p.health << "/" << p.maxHealth << "]" << endl;
		cout << "VS" << endl;
		cout << "[" << enemigoActual.name << "] HP:[" << enemigoActual.health << "/" << enemigoActual.maxHealth << "]" << endl;

		whatwillyoudoCombat(p, enemigoActual);

		if (enemigoActual.health < 0)
			enemigoActual.health = 0;


		if (enemigoActual.health != 0) {
			cout << enemigoActual.name << " attack and you loss " << enemigoActual.damage << "Hp" << endl;
			p.health -= enemigoActual.damage;
		}
		else {
			cout << "You kill a " << enemigoActual.name << endl;
		}

		if (p.health < 0)
			p.health = 0;

		if (enemigoActual.health == 0) {
			cout << "You win!!!!!" << endl;
			currentScene = NAVIGATION;
			m[p.Y][p.X] = '.';
			system("pause");
			return;
		}
		else if (p.health == 0) {
			cout << "GAME OVER!!!!!" << endl;
			currentScene = 124;
			return;
		}	
		
		system("pause");
	}
}

void whatwillyoudo(Player& player, bool n, bool w, bool e, bool s, char m[][SIZE]) {
	string input;
	cout << "What will you do?: ";
	getline(cin, input);

	if (input.empty()) {
		cout << "You didn't enter anything." << endl;
	}
	else {
		string comando, direction;
		size_t space_pos = input.find(' ');

		if (space_pos != string::npos) {
			comando = input.substr(0, space_pos);
			direction = input.substr(space_pos + 1);
		}
		else {
			comando = input;
		}

		for (int i = 0; i < comando.size(); i++) {
			if (comando[i] >= 'A' && comando[i] <= 'Z') {
				comando[i] += ' ';
			}
		}
		if (!(direction.empty())) {
			for (int i = 0; i < direction.size(); i++) {
				if (direction[i] >= 'A' && direction[i] <= 'Z') {
					direction[i] += ' ';
				}
			}
		}


		if (comando == "go") {

			if (direction == "east" && e) {
				cout << player.name << " move to east" << endl;
				player.X += 1;
			}
			else if (direction == "west" && w) {
				cout << player.name << " move to west" << endl;
				player.X -= 1;
			}
			else if (direction == "south" && s) {
				cout << player.name << " move to south" << endl;
				player.Y += 1;
			}
			else if (direction == "north" && n) {
				cout << player.name << " move to north" << endl;
				player.Y -= 1;
			}
			else {
				cout << "You can't move in this direction" << endl;
			}

		}
		else if (comando == "help") {
			cout << "------- COMAND -------" << endl;
			cout << "go + [NORTH | SOUTH | EAST | WEST]" << endl;
			cout << "    " << "The program has control that we went to zones that was 'navigation'. If has an '#', they are not." << endl;
			cout << "pick + [potion | sword | bomb | key]" << endl;
			cout << "    " << "Collect an object that is in actual map zone and adds it to the player inventory." << endl;
			cout << "use + [potion | sword | bomb | key]" << endl;
			cout << " " << endl;
			cout << "status" << endl;
			cout << "    " << "The status comand shows your name, health and the inventory" << endl;
			cout << " " << endl;
			cout << "punch" << endl;
			cout << "    " << "Base attack" << endl << endl;
		}
		else if (comando == "status") {
			cout << "------------ PLAYER ------------" << endl;
			cout << player.name << endl;
			cout << "--------------------------------" << endl;
			cout << "HP: " << player.health << "/" << player.maxHealth << endl;
			cout << "-----------INVENTORY------------" << endl;

			cout << "Potions: " << player.potion << endl;
			cout << "Bomb: " << player.bomb << endl;
			if (player.sword == true)
				cout << "Sword: Yes" << endl;
			else
				cout << "Sword: No" << endl;
			if (player.key == true)
				cout << "Key: Yes" << endl;
			else
				cout << "Key: No" << endl;

			cout << "--------------------------------" << endl;
			cout << " " << endl;
		}
		else if (comando == "pick") {

			if (m[player.Y][player.X] == 'P' && direction == "potion") {
				cout << player.name << " pick a potion" << endl;
				player.potion += 1;
				m[player.Y][player.X] = '.';
			}
			else if (m[player.Y][player.X] == 'B' && direction == "bomb") {
				cout << player.name << " pick a bomb" << endl;
				player.bomb += 1;
				m[player.Y][player.X] = '.';
			}
			else if (m[player.Y][player.X] == 'S' && direction == "sword") {
				if (player.sword == false) {
					cout << player.name << " pick a sword" << endl;
					player.sword = true;
					m[player.Y][player.X] = '.';
				}
				else {
					cout << "You have it" << endl;
				}	
			}
			else if (m[player.Y][player.X] == 'K' && direction == "key") {
				if (player.key == false) {
					cout << player.name << " pick the key" << endl;
					player.key = true;
					m[player.Y][player.X] = '.';
				}
				else {
					cout << "You have it" << endl;
				}
			}
			else {
				cout << "This item is not here" << endl;
			}
		}			
		
		else if (comando == "use") {
			if (direction == "potion") {
				if (player.health == player.maxHealth) {
					cout << "You have a max heath" << endl;
					player.potion -= 1;
					cout << "You used the potion" << endl;
				}
				else {
					if (player.health + 40 < player.maxHealth) {
						player.health += 40;
						cout << "You recover 40Hp, now you have: " << player.health << "Hp" << endl;
						player.potion -= 1;
					}
					else {
						cout << "You recover " << player.maxHealth - player.health << "Hp, now you have : " << player.health + (player.maxHealth - player.health) << "Hp" << endl;
						player.health = player.health + (player.maxHealth - player.health);
						player.potion -= 1;
					}
				}
			}
			else if (direction == "bomb") {
				cout << "This item can inly use in combat" << endl;
			}
			else if (direction == "sword") {
				cout << "This item can only use in combat" << endl;
			}
			else if (direction == "key") {
				if (player.key) {
					if (m[player.Y - 1][player.X] == 'L') {
						cout << "Unlock de door" << endl;
						m[player.Y - 1][player.X] = '.';
					}
				}
				else {
					cout << "You not have key" << endl;
				}
			}

		}
		else if (comando == "punch") {
			cout << "You dodn't stay in combat" << endl;
		}
		else {
			cout << "Not valid command" << endl;
		}
	}
	if (m[player.Y][player.X] != 'G' && m[player.Y][player.X] != 'O' && m[player.Y][player.X] != 'T')
		system("pause");
}

void whatwillyoudoCombat(Player& player, Enemigos& ene) {
	string input;
	cout << "What will you do?: ";
	getline(cin, input);

	if (input.empty()) {
		cout << "You didn't enter anything." << endl;
	}
	else {
		string comando, direction;
		size_t space_pos = input.find(' '); 

		if (space_pos != string::npos) { 
			comando = input.substr(0, space_pos); 
			direction = input.substr(space_pos + 1); 
		}
		else {
			comando = input; 
		}

		for (int i = 0; i < comando.size(); i++) {
			if (comando[i] >= 'A' && comando[i] <= 'Z') {
				comando[i] += ' ';
			}
		}
		if (!(direction.empty())) {
			for (int i = 0; i < direction.size(); i++) {
				if (direction[i] >= 'A' && direction[i] <= 'Z') {
					direction[i] += ' ';
				}
			}
		}

		if (comando == "go") 
			cout << "You didn't do this, you stay in combat" << endl;
	
		else if (comando == "help") {
			cout << "------- COMAND -------" << endl;
			cout << "go + [NORTH | SOUTH | EAST | WEST]" << endl;
			cout << "    " << "The program has control that we went to zones that was 'navigation'. If has an '#', they are not." << endl;
			cout << "pick + [potion | sword | bomb | key]" << endl;
			cout << "    " << "Collect an object that is in actual map zone and adds it to the player inventory." << endl;
			cout << "use + [potion | sword | bomb | key]" << endl;
			cout << " " << endl;
			cout << "status" << endl;
			cout << "    " << "The status comand shows your name, health and the inventory" << endl;
			cout << " " << endl;
			cout << "punch" << endl;
			cout << "    " << "Base attack" << endl << endl;
		
			cout << "You lose the turn" << endl;
		}
		else if (comando == "status") {
			cout << "------------ PLAYER ------------" << endl;
			cout << player.name << endl;
			cout << "--------------------------------" << endl;
			cout << "HP: " << player.health << "/" << player.maxHealth << endl;
			cout << "-----------INVENTORY------------" << endl;

			cout << "Potions: " << player.potion << endl;
			cout << "Bomb: " << player.bomb << endl;
			if (player.sword == true)
				cout << "Sword: Yes" << endl;
			else
				cout << "Sword: No" << endl;
			if (player.key == true)
				cout << "Key: Yes" << endl;
			else
				cout << "Key: No" << endl;

			cout << "--------------------------------" << endl;
			cout << " " << endl;
			
			cout << "You lose the turn" << endl;
		}
		else if (comando == "pick") 
				cout << "You didn't do this, you stay in combat" << endl;
		else if (comando == "use") {
			if (direction == "potion") {
				if (player.health == player.maxHealth)
					cout << "You have a max heath" << endl;
				else {
					if (player.health + 40 < player.maxHealth) {
						player.health += 40;
						cout << "You recover 40Hp, now you have: " << player.health << "Hp" << endl;
					}
					else {
						cout << "You recover " << player.maxHealth - player.health << "Hp, now you have : " << player.health + (player.maxHealth - player.health) << "Hp" << endl;
						player.health = player.health + (player.maxHealth - player.health);
						
					}
				}
			}
			else if (direction == "bomb") {
				cout << "Boooooomb!!!!" << endl;
				cout << ene.name << " lost 100Hp" << endl;
				ene.health -= 100;

			}
			else if (direction == "sword") {
				if (player.sword == false) {
					cout << "Don't have sword" << endl;
				}
				else {
					cout << "Zas!!!" << endl;
					cout << ene.name << " lost 40Hp" << endl;
					ene.health -= 40;
				}
			}
			else if (direction == "key")
				cout << "This item can't use in combat" << endl;
		}
		else if (comando == "punch") {

			cout << "Punch a " << ene.name << " and loss 10Hp" << endl;
			ene.health -= 10;

		}
		else {
			cout << "Not valid command" << endl;
		}
	}

}

void Boss(Player& p) {
	Enemigos boss{
		DEMON,
		"Demon",
		290,
		290,
		20
	};
	
	
	while (true) {
		system("cls");

		cout << "                           ,-." << endl;
		cout << "      ___,---.__          /'|`\\          __,---,___" << endl;
		cout << "   ,-'    \\`    `-.____,-'  |  `-.____,-'    //    `-." << endl;
		cout << "  ,'       |          ~'\\      /`~           |        `." << endl;
		cout << " /      ___//             `. ,'          ,  , \\___      \\ " << endl;
		cout << "|    ,-'   `-._    _        |        ,    __,-'   `-.    |" << endl;
		cout << "|   /         /\\_  `   .    |    ,      _/ \\         \\   |" << endl;
		cout << "\\  |          \\ \\`-.___ \\   |   / ___,-'/ /           |  /" << endl;
		cout << " \\  \\          | `._   `\\\\  |  //'   _,' |           /  /" << endl;
		cout << "  `-.\\        /'  _ `---'' , . ``---'  _ `\\         /,-'" << endl;
		cout << "     ``      /     \    ,='/ \`=.    /      \\       ''" << endl;
		cout << "            |__   /|\_,--.,-.--,--._/|\   __|" << endl;
		cout << "            /  `./  \\\\`\\ |  |  | /,//'\\,'  \\ " << endl;
		cout << "           /   /     ||--+--|--+-/-|    \\   \\ " << endl;
		cout << "          |   |     /'\\_\\_\\ | /_/_/`\\    |   |" << endl;
		cout << "           \\   \\__, \\_     `~'     _/ .__/   /" << endl;
		cout << "            `-._,-'   `-._______,-'   `-._,-'" << endl << endl;

		cout << "[" << p.name << "] HP:[" << p.health << "/" << p.maxHealth << "]" << endl;
		cout << "VS" << endl;
		cout << "[" << boss.name << "] HP:[" << boss.health << "/" << boss.maxHealth << "]" << endl;

		whatwillyoudoCombat(p, boss);

		if (boss.health < 0)
			boss.health = 0;


		if (boss.health != 0) {
			cout << boss.name << " attack and you loss " << boss.damage << "Hp" << endl;
			p.health -= boss.damage;
		}
		else {
			cout << "You kill a " << boss.name << endl;
		}

		if (p.health < 0)
			p.health = 0;

		if (boss.health == 0) {
			cout << "Congrats, you pass the game!!!!!" << endl;
			currentScene = 10;
			system("pause");
			return;
		}
		else if (p.health == 0) {
			cout << "GAME OVER!!!!!" << endl;
			currentScene = 124;
			return;
		}
		system("pause");
	}
}