#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <vector>

#define SIZE 10
int currentScene = 0;
using namespace std;
enum Items {POTION, BOMB, SWORD, KEY};
vector<int> a;
struct Player {
	string name;
	int file;
	int column;
	int maxHealth;
	int health;
	vector<int> inventory;
};

Player player{
	"Luis",
	1,
	1,
	100,
	100
};

char map[SIZE][SIZE]{
	{'#','#','#','#','#','#','#','#','#','#'},
	{'#','@','.','P','.','P','.','.','.','#'},
	{'#','#','#','G','#','S','#','#','M','#'},
	{'#','.','.','.','#','#','#','#','#','#'},
	{'#','.','T','.','#','J','#','.','B','#'},
	{'#','.','.','.','#','L','#','.','.','#'},
	{'#','#','.','#','#','.','#','T','T','#'},
	{'#','P','G','#','#','O','#','.','.','#'},
	{'#','.','.','.','.','K','.','.','B','#'},
	{'#','#','#','#','#','#','#','#','#','#'},
};

void help();
void go();
void whatwillyoudo();
void status();
void Intro();
void Navigation();
void Combat();
void PickupItem();
int main() {
	while (true) {
		if (currentScene == 0) {
			Intro();
		}
		else if (currentScene == 1) {
			Navigation();
		}
		else if (currentScene == 2) {
			Combat();
		}
		else if (currentScene == 3) {
			PickupItem();
		}
		else {
			return 0;
		}
	}
}

void help() {
	cout << "------- COMAND HELP -------" << endl;
	cout << "go + [NORTH | SOUTH | EAST | WEST]" << endl;
	cout << "    " << "El programa debe controlar que vayamos a zonas que sean 'navegables'.Si hay un '#', no lo son." << endl;
	cout << "pick + [potion | sword | bomb | key]" << endl;
	cout << "    " << "Recoge el objeto que hay en la zona de mapa actual y la añade al inventario del jugador." << endl;
	cout << "    " << "Ten en cuenta que si recojo un objeto, ya no me debe informar de que ese objeto está en esa posición del mapa." << endl;
	cout << "use + [potion | sword | bomb | key]" << endl;
}

void Intro() {

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
	cout << " " << endl;
	currentScene = 1;
}

void status() {
	int potions = 0;
	int bomb = 0;
	int sword = 0;
	int key = 0;

	cout << "------------ PLAYER ------------" << endl;
	cout << player.name;
	cout << "--------------------------------" << endl;
	cout << "HP: " << player.health << "/" << player.maxHealth << endl;
	cout << "-----------INVENTORY------------" << endl;
	for (int i = 0; i < player.inventory.size(); i++) {
		if (player.inventory[i] == 1)
			potions++;
		else if (player.inventory[i] == 2)
			bomb++;
		else if (player.inventory[i] == 3)
			sword++;
		else if (player.inventory[i] == 4)
			key++;
	}
	cout << "Potions: " << potions << endl;
	cout << "Bomb: " << bomb << endl;
	cout << "Sword: " << sword << endl;
	cout << "Key: " << key << endl;

}


void Navigation() {
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
	
	whatwillyoudo();
}

void Combat() {

}

void PickupItem() {

}

void go(string direc) {
	if (direc == "east") {
		player.column += 1;
	}
	else if (direc == "west") {
		player.column -= 1;
	}
	else if (direc == "south") {
		player.file += 1;
	}
	else if (direc == "north") {
		player.file -= 1;
	}
}

void whatwillyoudo() {
	string direction;
	string comando;

	cout << "What will you do?: ";
	cin >> comando >> direction;

	if (comando == "go")
		go(direction);
	else if (comando == "help")
		help();
	else if (comando == "status")
		status();


}