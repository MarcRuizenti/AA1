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

}
void Navigation() {

}