#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <vector>

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
void Intro() {
	Player player{
		"Luis",
		1,
		1,
		100,
		100
	};

	cout << "------------ HERO'S QUEST ------------" << endl;
	cout << "The evil Jarenauer has stolen the sacred gem. " << endl;
	cout << "It is your duty as the chosen hero to defeat him and retrieve the gem to restore peace. " << endl;
	cout << " " << endl;
	cout << "You have an enchanted charm that tells you where Jarenauer's lair is " << endl;
	cout << " " << endl;
	cout << "Use the HELP command to show the options " << endl;
	cout << "------------------------------------------------" << endl;
	cout << "May I ask your name, brave hero? ";
	cin >> player.name;
}
void Navigation() {

}