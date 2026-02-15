#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct GameResult {
    string name;
    int score;
    string difficulty;
};
vector<GameResult> games_history;

int generate_number(int min_val, int max_val) {
    return rand() % (max_val - min_val + 1) + min_val;
}

void get_hint(int number, int guess) {
    if (guess < number) cout << "Загаданное число БОЛЬШЕ." << endl;
    else if (guess > number) cout << "Загаданное число МЕНЬШЕ." << endl;
}

int calculate_score(int attempts, int max_attempts, int diff_multiplier) {
    int score = (max_attempts - attempts + 1) * 10 * diff_multiplier;
    return (score < 0) ? 0 : score;
}

void save_game_result(string player_name, int score, string difficulty) {
    games_history.push_back({player_name, score, difficulty});
}

void show_statistics() {
    cout << "СТАТИСТИКА ТЕКУЩЕЙ СЕССИИ" << endl;
    if (games_history.empty()) {
        cout << "Игр еще не было." << endl;
        return;
    }
    for (const auto& game : games_history) {
        cout << "Игрок: " << game.name << " | Очки: " << game.score << " | Сложность: " << game.difficulty << endl;
    }
}

void show_leaderboard() {
    if (games_history.empty()) return;
    
    vector<GameResult> sorted = games_history;
    sort(sorted.begin(), sorted.end(), [](const GameResult& a, const GameResult& b) {
        return a.score > b.score;
    });

    cout << "ТАБЛИЦА ЛИДЕРОВ" << endl;
    for (int i = 0; i < min((int)sorted.size(), 3); i++) {
        cout << i + 1 << ". " << sorted[i].name << " - " << sorted[i].score << " очков" << endl;
    }
}

void play_game(string difficulty = "легкий") {
    string name;
    cout << "Введите ваше имя: ";
    cin >> name;

    int max_val, max_attempts, multiplier;
    
    if (difficulty == "тяжелый") {
        max_val = 100; max_attempts = 5; multiplier = 3;
    } else if (difficulty == "средний") {
        max_val = 50; max_attempts = 7; multiplier = 2;
    } else {
        max_val = 20; max_attempts = 10; multiplier = 1;
    }

    int target = generate_number(1, max_val);
    int guess, attempts = 0;
    bool won = false;

    cout << "Угадайте число от 1 до " << max_val << ". У вас " << max_attempts << " попыток." << endl;

    while (attempts < max_attempts) {
        attempts++;
        cout << "Попытка " << attempts << ". Ваш вариант: ";
        cin >> guess;

        if (guess == target) {
            int score = calculate_score(attempts, max_attempts, multiplier);
            cout << "ПОЗДРАВЛЯЕМ! Вы угадали число за " << attempts << " попыток. Очки: " << score << endl;
            save_game_result(name, score, difficulty);
            won = true;
            break;
        } else {
            get_hint(target, guess);
        }
    }

    if (!won) cout << "Вы проиграли! Загаданное число было: " << target << endl;
}

int main() {
    srand(time(0));

    int menu_choice;
    do {
        cout << "МЕНЮ ИГРЫ" << endl;
        cout << "1. Легкий уровень (1-20)" << endl;
        cout << "2. Средний уровень (1-50)" << endl;
        cout << "3. Тяжелый уровень (1-100)" << endl;
        cout << "4. Статистика и лидеры" << endl;
        cout << "0. Выход" << endl;
        cout << "Выбор: ";
        cin >> menu_choice;

        switch (menu_choice) {
            case 1: play_game("легкий"); break;
            case 2: play_game("средний"); break;
            case 3: play_game("тяжелый"); break;
            case 4: 
                show_statistics(); 
                show_leaderboard(); 
                break;
        }
    } while (menu_choice != 0);

    return 0;
}
