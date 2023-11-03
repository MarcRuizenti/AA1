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

enum Items { POTION, BOMB, SWORD, KEY };
struct Player {
	string name;
	int file;
	int column;
	int maxHealth;
	int health;
	vector<Items> inventory;
};

void help();
void go(string direc, Player& player, bool n, bool w, bool e, bool s);
void whatwillyoudo(Player& player, bool n, bool w, bool e, bool s, char m[][SIZE]);
void status(Player& player);
void Intro(Player& player);
void Navigation(Player& player, char map[][SIZE]); 
void Combat(Player& p, char m[][SIZE]);
void pickupItem(Player& p, char map[][SIZE], string collect);
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
		100
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
	cout << "------- COMAND HELP -------" << endl;
	cout << "go + [NORTH | SOUTH | EAST | WEST]" << endl;
	cout << "    " << "The program has control that we went to zones that was 'navigation'. If has an '#', they are not." << endl;
	cout << "pick + [potion | sword | bomb | key]" << endl;
	cout << "    " << "Collect an object that is in actual map zone and adds it to the player inventory." << endl;
	cout << "use + [potion | sword | bomb | key]" << endl;
	cout << " " << endl;
	cout << "ststus" << endl;
	cout << "    " << "The status comand shows your name, health and the inventory" << endl;
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

void status(Player& player) {
	int potions = 0;
	int bomb = 0;
	int sword = 0;
	int key = 0;

	cout << "------------ PLAYER ------------" << endl;
	cout << player.name << endl;
	cout << "--------------------------------" << endl;
	cout << "HP: " << player.health << "/" << player.maxHealth << endl;
	cout << "-----------INVENTORY------------" << endl;
	if (player.inventory.size() != 0) {
		for (int i = 0; i < player.inventory.size(); i++) {
			if (player.inventory[i] == POTION)
				potions++;
			else if (player.inventory[i] == BOMB)
				bomb++;
			else if (player.inventory[i] == SWORD)
				sword++;
			else if (player.inventory[i] == KEY)
				key++;
		}
	}
	cout << "Potions: " << potions << endl;
	cout << "Bomb: " << bomb << endl;
	cout << "Sword: " << sword << endl;
	cout << "Key: " << key << endl;
	cout << "--------------------------------" << endl;
	cout << " " << endl;
}

void Navigation(Player& player, char map[][SIZE]) {
	if (map[player.file][player.column] != 'G' && map[player.file][player.column] != 'O' && map[player.file][player.column] != 'T') {
		cout << "[" << player.name << "]" << " at " << "[" << player.file << ", " << player.column << "]" << endl;

		if (player.file < 5 && player.column < 6)
			cout << "The penchant detects an evil aura at southeast" << endl;
		else if (player.file > 5 && player.column < 6)
			cout << "The penchant detects an evil aura at northeast" << endl;
		else if (player.file > 5 && player.column > 6)
			cout << "The penchant detects an evil aura at northwest" << endl;
		else if (player.file < 5 && player.column > 6)
			cout << "The penchant detects an evil aura at southwest" << endl;
		else if (player.file < 5 && player.column == 6)
			cout << "The penchant detects an evil aura at south" << endl;
		else if (player.file > 5 && player.column == 6)
			cout << "The penchant detects an evil aura at north" << endl;
		else if (player.file == 5 && player.column < 6)
			cout << "The penchant detects an evil aura at east" << endl;
		else if (player.file == 5 && player.column > 6)
			cout << "The penchant detects an evil aura at west" << endl;

		cout << "You can go: ";
		bool north = map[player.file - 1][player.column] != '#';
		bool west = map[player.file][player.column - 1] != '#';
		bool east = map[player.file][player.column + 1] != '#';
		bool south = map[player.file + 1][player.column] != '#';

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

		if (map[player.file][player.column] == 'P')
			cout << "There is a Potion on the floor" << endl;
		else if (map[player.file][player.column] == 'B')
			cout << "There is a Bomb on the floor" << endl;
		else if (map[player.file][player.column] == 'K')
			cout << "There is a Key on the floor" << endl;
		else if (map[player.file][player.column] == 'S')
			cout << "There is a Sword on the floor" << endl;

		if (map[player.file - 1][player.column] == 'P')
			cout << "There is a Potion at north" << endl;
		else if (map[player.file - 1][player.column] == 'B')
			cout << "There is a Bomb at north" << endl;
		else if (map[player.file - 1][player.column] == 'K')
			cout << "There is a Key at north" << endl;
		else if (map[player.file - 1][player.column] == 'S')
			cout << "There is a Sword at north" << endl;
		else if (map[player.file - 1][player.column] == 'G')
			cout << "There is a Goblin at north" << endl;
		else if (map[player.file - 1][player.column] == 'O')
			cout << "There is a Orc at north" << endl;
		else if (map[player.file - 1][player.column] == 'T')
			cout << "There is a Troll at north" << endl;

		if (map[player.file + 1][player.column] == 'P')
			cout << "There is a Potion at south" << endl;
		else if (map[player.file + 1][player.column] == 'B')
			cout << "There is a Bomb at south" << endl;
		else if (map[player.file + 1][player.column] == 'K')
			cout << "There is a Key at south" << endl;
		else if (map[player.file + 1][player.column] == 'S')
			cout << "There is a Sword at south" << endl;
		else if (map[player.file + 1][player.column] == 'G')
			cout << "There is a Goblin at south" << endl;
		else if (map[player.file + 1][player.column] == 'O')
			cout << "There is a Orc at south" << endl;
		else if (map[player.file + 1][player.column] == 'T')
			cout << "There is a Troll at south" << endl;

		if (map[player.file][player.column - 1] == 'P')
			cout << "There is a Potion at west" << endl;
		else if (map[player.file][player.column - 1] == 'B')
			cout << "There is a Bomb at west" << endl;
		else if (map[player.file][player.column - 1] == 'K')
			cout << "There is a Key at west" << endl;
		else if (map[player.file][player.column - 1] == 'S')
			cout << "There is a Sword at west" << endl;
		else if (map[player.file][player.column - 1] == 'G')
			cout << "There is a Goblin at west" << endl;
		else if (map[player.file][player.column - 1] == 'O')
			cout << "There is a Orc at west" << endl;
		else if (map[player.file][player.column - 1] == 'T')
			cout << "There is a Troll at west" << endl;

		if (map[player.file][player.column + 1] == 'P')
			cout << "There is a Potion at east" << endl;
		else if (map[player.file][player.column + 1] == 'B')
			cout << "There is a Bomb at east" << endl;
		else if (map[player.file][player.column + 1] == 'K')
			cout << "There is a Key at east" << endl;
		else if (map[player.file][player.column + 1] == 'S')
			cout << "There is a Sword at east" << endl;
		else if (map[player.file][player.column + 1] == 'G')
			cout << "There is a Goblin at east" << endl;
		else if (map[player.file][player.column + 1] == 'O')
			cout << "There is a Orc at east" << endl;
		else if (map[player.file][player.column + 1] == 'T')
			cout << "There is a Troll at east" << endl;

		whatwillyoudo(player, north, west, east, south, map);
	}
	else {
		currentScene = COMBAT;
	}
}

void Combat(Player& p, char m[][SIZE]) {
	enum raze{GOBLIN, ORC, TROLL};
	struct Enemigos {
		raze raze;
		string name;
		int health;
		int maxHealth;
		int damage;
	};

	raze razeEnemigo;

	Enemigos enemigo[3]{
		{GOBLIN, "Goblin"},
		{ORC, "Orco"},
		{TROLL, "Troll"}
	};

	Enemigos enemigoActual;

	if (m[p.file][p.column] == 'G')
		razeEnemigo = GOBLIN;
	else if (m[p.file][p.column] == 'O')
		razeEnemigo = ORC;
	else if (m[p.file][p.column] == 'T')
		razeEnemigo = TROLL;

	for (int i = 0; i < 3; i++) {
		if (razeEnemigo == enemigo[i].raze)
			enemigoActual = enemigo[i];
	}

	cout << enemigoActual.name << " attacks!" << endl;
	cout << enemigoActual.name << " use Slash!" << endl;
	cout << p.name << " recived 10 damage" << endl;

	p.health -= 10;

	cout << "-------- Entrado a la batalla --------" << endl << endl;
	
	while (true) {
		cout << "[" << p.name << "] HP:[" << p.health << "/" << p.maxHealth << "]" << endl;
		cout << "VS" << endl;
		cout << "[" << enemigoActual.name << "] HP:[" << enemigoActual.health << "/" << enemigoActual.maxHealth << "]" << endl;

	}
	




	m[p.file][p.column] = '.';
	currentScene = NAVIGATION;
	
}

void pickupItem(Player& p, char map[][SIZE], string collect) {
	if (map[p.file][p.column] == 'P' || map[p.file][p.column] == 'B' || map[p.file][p.column] == 'S' || map[p.file][p.column] == 'K') {
		if (collect == "Potion") {
			p.inventory.push_back(POTION);
			map[p.file][p.column] = '.';
		}
		else if (collect == "Bomb") {
			p.inventory.push_back(BOMB);
			map[p.file][p.column] = '.';
		}
		else if (collect == "Sword") {
			p.inventory.push_back(SWORD);
			map[p.file][p.column] = '.';
		}
		else if (collect == "Key") {
			p.inventory.push_back(KEY);
			map[p.file][p.column] = '.';
		}
	}
	else {
		cout << "There is no item" << endl;
	}
}

void go(string direc, Player& player, bool n, bool w, bool e, bool s) {
	if (direc == "east" && e) {
		player.column += 1;
	}
	else if (direc == "west" && w) {
		player.column -= 1;
	}
	else if (direc == "south" && s) {
		player.file += 1;
	}
	else if (direc == "north" && n) {
		player.file -= 1;
	}
}

void whatwillyoudo(Player& player, bool n, bool w, bool e, bool s,char m[][SIZE]) {
	string input;
	cout << "What will you do?: ";
	getline(cin, input);
	cout << " " << endl;

	if (input.empty()) {
		cout << "You didn't enter anything." << endl;
	}
	else {
		// Procesa la entrada seg�n tus necesidades
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
	}

}