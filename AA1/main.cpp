#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <vector>
#include <sstream>

enum Scene { INTRO, NAVIGATION, COMBAT, PICKPITEM };

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

enum Raze { GOBLIN, ORC, TROLL };
struct Enemigos {
	Raze raze;
	string name;
	int health;
	int maxHealth;
	int damage;
};

void help();
void go(string direc, Player& player, bool n, bool w, bool e, bool s);
void whatwillyoudo(Player& player, bool n, bool w, bool e, bool s, char m[][SIZE]);
void status(Player& player);
void Intro(Player& player);
void Navigation(Player& player, char map[][SIZE]);
void Combat(Player& p, char m[][SIZE]);
void pickupItem(Player& p, char map[][SIZE], string collect);
void whatwillyoudocombat(Player& p);
void use(Player& p, string ob);
int main() {
	char map[SIZE][SIZE]{
		{'#','#','#','#','#','#','#','#','#','#'},
		{'#','.','.','P','.','P','.','.','.','#'},
		{'#','#','#','G','#','S','#','#','#','#'},
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
		1,
		1,
		100,
		100,
		0,
		0,
		false,
		false
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
		else {
			return 0;
		}
	}
}

void help() {
	cout << "------- COMAND -------" << endl;
	cout << "go + [NORTH | SOUTH | EAST | WEST]" << endl;
	cout << "    " << "The program has control that we went to zones that was 'navigation'. If has an '#', they are not." << endl;
	cout << "pick + [potion | sword | bomb | key]" << endl;
	cout << "    " << "Collect an object that is in actual map zone and adds it to the player inventory." << endl;
	cout << "use + [potion | sword | bomb | key]" << endl;
	cout << " " << endl;
	cout << "ststus" << endl;
	cout << "    " << "The status comand shows your name, health and the inventory" << endl;
	cout << " " << endl;
	cout << "------- COMAND IN COMBAT -------" << endl;
	cout << "ststus" << endl;
	cout << "    " << "The status comand shows your name, health and the inventory" << endl;
	cout << " " << endl;
	cout << "use + [potion | sword | bomb | key]" << endl;
	cout << " " << endl;
}

void Intro(Player& player) {

	cout << "------------ H E R O ' S  Q U E S T ------------" << endl;
	cout << "The evil Jarenauer has stolen the sacred gem. " << endl;
	cout << "It is your duty as the chosen hero to defeat him and retrieve the gem to restore peace. " << endl;
	cout << " " << endl;
	cout << "You have an enchanted charm that tells you where Jarenauer's lair is " << endl;
	cout << " " << endl;
	cout << "Use the HELP command to show the options " << endl;
	cout << "------------------------------------------------" << endl;
	cout << "May I ask your name, brave hero? ";
	cin >> player.name;
	cin.ignore();
	cout << " " << endl;
	currentScene = NAVIGATION;
}

void Navigation(Player& player, char map[][SIZE]) {
	system("cls");

	if (map[player.Y][player.X] != 'G' && map[player.Y][player.X] != 'O' && map[player.Y][player.X] != 'T') {
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
		bool north = map[player.Y - 1][player.X] != '#';
		bool west = map[player.Y][player.X - 1] != '#';
		bool east = map[player.Y][player.X + 1] != '#';
		bool south = map[player.Y + 1][player.X] != '#';

		if (north) {
			cout << "[NORTH]";
		}
		if (west) {
			cout << "[WEST]";
		}
		if (east) {
			cout << "[EAST]";
		}
		if (south) {
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

		whatwillyoudo(player, north, west, east, south, map);
	}
	else {
		currentScene = COMBAT;
	}
}

void Combat(Player& p, char m[][SIZE]) {



	Raze razeEnemigo;

	Enemigos enemigo[3]{
		{GOBLIN, "Goblin", 30, 30, 5},
		{ORC, "Orco", 60, 60, 10},
		{TROLL, "Troll", 90, 90, 15 }
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

	cout << "-------- Entrado a la batalla --------" << endl << endl;

	while (true) {
		cout << "[" << p.name << "] HP:[" << p.health << "/" << p.maxHealth << "]" << endl;
		cout << "VS" << endl;
		cout << "[" << enemigoActual.name << "] HP:[" << enemigoActual.health << "/" << enemigoActual.maxHealth << "]" << endl;

		whatwillyoudocombat(p);
	}





	m[p.Y][p.X] = '.';
	currentScene = NAVIGATION;

}

void pickupItem(Player& p, char map[][SIZE], string collect) {
	if (map[p.Y][p.X] == 'P' || map[p.Y][p.X] == 'B' || map[p.Y][p.X] == 'S' || map[p.Y][p.X] == 'K') {
		if (collect == "Potion") {
			p.potion += 1;
			map[p.Y][p.X] = '.';
		}
		else if (collect == "Bomb") {
			p.bomb += 1;
			map[p.Y][p.X] = '.';
		}
		else if (collect == "Sword") {
			if (p.sword == false) {
				p.sword = true;
				map[p.Y][p.X] = '.';
			}
			else {
				cout << "You have it" << endl;
			}
		}
		else if (collect == "Key") {
			if (p.key == false) {
				p.key = true;
				map[p.Y][p.X] = '.';
			}
			else {
				cout << "You have it" << endl;
			}
		}
	}
	else {
		cout << "There is no item" << endl;
	}
}

void go(string direc, Player& player, bool n, bool w, bool e, bool s) {
	
	
	if (direc == "east" && e) {
		player.X += 1;
	}
	else if (direc == "west" && w) {
		player.X -= 1;
	}
	else if (direc == "south" && s) {
		player.Y += 1;
	}
	else if (direc == "north" && n) {
		player.Y -= 1;
	}
	else
		cout << "You can't move in this direction" << endl;
}

void use(Player& p, string ob) {
	if (ob == "Potion") {
		p.health += 40;
		cout << "You recovere 40 hp, now you have: " << p.health << "hp" << endl;
	}
	else if (ob == "Bomb") {

	}
	else if (ob == "Sword") {

	}
}

void status(Player& player) {
	

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

void whatwillyoudo(Player& player, bool n, bool w, bool e, bool s, char m[][SIZE]) {
	string input;
	cout << "What will you do?: ";
	getline(cin, input);
	cout << " " << endl;

	if (input.empty()) {
		cout << "You didn't enter anything." << endl;
	}
	else {
		// Procesa la entrada según tus necesidades
		string comando, direction;
		istringstream iss(input);
		iss >> comando >> direction;

		if (comando == "go")
			go(direction, player, n, w, e, s);
		else if (comando == "help")
			help();
		else if (comando == "status")
			status(player);
		else if (comando == "pick")
			pickupItem(player, m, direction);
		else if (comando == "use")
			use(player, direction);
	}

}

void whatwillyoudocombat(Player& p) {

	string input;
	cout << "What will you do?: ";
	getline(cin, input);
	cout << " " << endl;

	if (input.empty()) {
		cout << "You didn't enter anything." << endl;
	}
	else {
		// Procesa la entrada según tus necesidades
		string comando, direction;
		istringstream iss(input);
		iss >> comando >> direction;


		if (comando == "help")
			help();
		else if (comando == "status")
			status(p);
		else if (comando == "use")
			use(p, direction);
	}

}