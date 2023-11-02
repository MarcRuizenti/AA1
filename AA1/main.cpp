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
void whatwillyoudo(Player& player, bool n, bool w, bool e, bool s);
void status(Player& player);
void Intro(Player& player);
void Navigation(Player& player, char map[][SIZE]); 
void Combat();
void PickupItem();
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
			Combat();
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
	cout << "[" << player.name << "]" << " at " << "[" << player.file << ", " << player.column << "]" << endl;
	
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
	
	whatwillyoudo(player, north, west, east, south);
}

void Combat() {

}

void PickupItem(Player p, char map[][SIZE], string cllect) {
	
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

void whatwillyoudo(Player& player, bool n, bool w, bool e, bool s) {
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
			go(direction, player, n, w ,e ,s);
		else if (comando == "help")
			help();
		else if (comando == "status")
			status(player);
	}

}