#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <vector>

#define SIZE 10
int currentScene = 0;
using namespace std;

struct Player {
	string name;
	int file;
	int column;
	int maxHealth;
	int health;
	vector<string> inventory;
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

void Navigation() {
	string direction;
	string comando;
	cout << "[" << player.name << "]" << " at " << "[" << player.file << ", " << player.column << "]" << endl;
	
	cout << "You con go: ";
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
	cin >> comando >> direction;

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