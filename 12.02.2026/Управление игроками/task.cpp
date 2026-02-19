#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;
void printPlayers(const list<string>& players) {
    cout << "Текущий список: [ ";
    for (const string& p : players) cout << p << " ";
    cout << "]" << endl;
}

int main() {
    list<string> players;

    players.push_back("Alice");
    players.push_back("Bob");
    cout << "Шаг 1 (Add): "; printPlayers(players);

    auto itAlice = find(players.begin(), players.end(), "Alice");
    if (itAlice != players.end()) {
        players.insert(next(itAlice), "Eve");
    }
    cout << "Шаг 2 (Insert After): "; printPlayers(players);

    auto itBob = find(players.begin(), players.end(), "Bob");
    if (itBob != players.end()) {
        players.erase(itBob);
    }
    cout << "Шаг 3 (Remove): "; printPlayers(players);

    players.push_back("Charlie");
    players.push_back("David");
    cout << "Подготовка к Move: "; printPlayers(players);

    string target = "Alice";
    int steps = 2;
    
    auto itMove = find(players.begin(), players.end(), target);
    if (itMove != players.end()) {
        auto itDest = itMove;

        if (steps > 0) {
            for (int i = 0; i <= steps && itDest != players.end(); ++i) ++itDest;
        } else {
            for (int i = 0; i > steps && itDest != players.begin(); --i) --itDest;
        }
        players.splice(itDest, players, itMove);
        cout << "Шаг 4 (Move " << target << " " << steps << "): ";
    }
    
    printPlayers(players);

    return 0;
}
