#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

class Stats {
public:
    int monster_health;
    int monster_damage;
    int hero_health;
    int hero_damage;
    string monster1_name;
    string monster2_name;
    string result;

    void operation() {
        monster_health = monster_health - hero_damage;
        hero_health = hero_health - monster_damage;
    }

};

void attack(Stats* stat) {
  stat->operation();

        if (stat->hero_health == 0) {
            stat->result = "GAME OVER";
            cout << stat->result;
            return;
        }
        if (stat->monster_health == 0) {
            int max = 100;
            int arm = random()%max;
            cout << "GREAT!HEY, YOU HAVE GOTTEN A ARM " << arm << "! LET'S CONTINUE!";
            cout << stat->result;
            return;
        }
        if (stat->hero_health < 100) {
            cout << "YES, YOU DID THIS! ";
            cout << "OH NO, YOUR HP IS " << stat->hero_health << " BE NEAT ";
            return;
    }
};


int main() {
    Stats stat;
    stat.monster_health = 100;
    stat.monster_damage = 15;
    stat.hero_health = 100;
    stat.hero_damage = 20;
    stat.result;

    stat.operation();
    while (true) {
        cout << "\n 1. Attack! ";
        cout << "\n 2. Exit \n";
        string choose;
        cin >> choose;

        while (choose == "1") {
            attack(&stat);
            break;
        }

        if (choose == "2") {
            break;
        }

        if(stat.hero_health < 0) {
            cout << "YOU DIED";
            break;
        }
    }

  return 0;
}
