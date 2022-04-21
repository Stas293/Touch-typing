//
//  main.cpp
//  Course
//
//  Created by Стас Скор on 05.05.2021.
//

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <chrono>

using namespace std;

struct Person {
    void lead();
    void add(int, int);
    void leaderboard();
    int num = 0;
    int level;
    string name;
    int wpm;
    Person(int num = rand() % 100, int lev = 1) {
        name = "player" + to_string(num);
        level = lev;
    };
};

Person users[1000];

void Person::lead(){
    int i = 0;
    ifstream cin("/Users/stasskor/Documents/XCode Projects/Project C/Laba_Project/Course/Course/Leaderboard.txt");
    if (cin.is_open()){
        cin >> num;
        if (num > 0){
            do {
                cin >> users[i].name;
                cin >> users[i].wpm;
                cin >> users[i].level;
                i++;
            }while(!cin.eof());
            cout << "Leaderboard loaded successfully" << endl;
        }
    }
    else
        cout << "File doesn't exist" << endl;
}

void Person::add(int wpm, int lev){
    lead();
    fstream board("/Users/stasskor/Documents/XCode Projects/Project C/Laba_Project/Course/Course/Leaderboard.txt");
    cout << "Type name: ";
    cin >> users[num].name;
    
    num++;
    
    cout << endl;
    if(board.is_open()) {
        board << num << endl;
        
        for (int i = 0; i < num; i++){
            if(i == num - 1){
                board << users[i].name << " " << wpm << " " << lev << endl;
                break;
            }
            board << users[i].name << " " << users[i].wpm << " " << users[i].level << endl;
        }
        
        board.close();
    }
    else
        cout << "Error" << endl;
}

void Person::leaderboard(){
    lead();
    cout << endl << "\t\t\t===================" << endl
         << "\t\t\t    Leaderboard    " << endl
         << "\t\t\t===================" << endl << endl;
                     
    if(num > 0) {
        for(int i = 0; i < num; i++) {
            cout << (i+1) << ") " << "User: " << users[i].name << "; " << "Words Per Minute: " << users[i].wpm << "; " << "Level: " << users[i].level << endl;
        } cout << endl;
    }
    else
        cout << "No data available" << endl;
}

struct Level{
    void level_1();
    void level_2();
    void level_3();
    void level_4();
    void level_5();
    void level_6();
};

struct Theory{
    void level_1();
    void level_2();
    void level_3();
    void level_4();
    void level_5();
    void level_6();
    void Congrats();
};

struct Test{
    void end();
    void results(int, int);
};

void Test::end(){
    Person per;
    int length = 0;
    int incorrect = 0;
    string text, answer, n;
    Theory th;
    th.Congrats();
    getchar();
    ifstream file ("/Users/stasskor/Documents/XCode Projects/Project C/Laba_Project/Course/Course/All.txt");
    vector<string> texts;
    chrono::steady_clock::time_point clock = chrono::steady_clock::now() + chrono::seconds(60);
    
    cout << "You have one minute to test your typing speed" << endl;
    
    int line = -1;
    
    if (file.fail()){
        cout << "Error" << endl;
        return;
    } else if(file.is_open()){
        while(!file.eof()){
            line ++;
            getline(file, text);
            texts.push_back(text);
        }
        while(!(chrono::steady_clock::now() > clock)){
            srand(static_cast<unsigned int>(time(nullptr)));
            n = texts[rand() % line];
            cout << n << endl;
            cin >> answer;
            length = length + (sizeof(n));
            if(answer != n){
                incorrect ++;
                cout << "Incorrect" << endl << endl;
                cout << n << endl;
                cin  >> answer;
            }
        }
        file.close();
        cout << "There is no time left!" << endl;
        if(incorrect == 0){
            cout << "Wow! Incredible! You`re master" << endl;
            users[per.num].level++;
        }
        results(length, incorrect);
    }
}

void Test::results(int x, int y){
    char s;
    Person per;
    Level l;
    int WPM = (x/5)/1.0;
    
    cout << endl;
    cout << "    ==============================" << endl
    << "    =          Results           =" << endl
    << "    ==============================" << endl << endl
    << "Characters typed: " << x << "" << endl
    << "Incorrect words: " << y << "" << endl
    << "Words Per Minute: " << WPM << "" << endl << endl;
    
//e:
    if(users[per.num].level != 8 && y == 0){
        cout << "Would you like to move to the next level? (Y/N)" << endl;
        cin >> s;
        while (s!= 'Y' && s!= 'N'){
            cout << "Error" << endl << "Would you like to move to the next level? (Y/N)" << endl;
            cin >> s;
        }
        if(s == 'N'){
            users[per.num].level--;
        }
//        else if ( s != 'Y'){
//            cout << "Error" << endl << "Would you like to move to the next level?" << endl;
//            goto e;
//        }
     else {
            switch (users[per.num].level){
                case 2:
                    l.level_2();
                    return;
                case 3:
                    l.level_3();
                    return;
                case 4:
                    l.level_4();
                    return;
                case 5:
                    l.level_5();
                    return;
                case 6:
                    l.level_6();
                    return;
                case 7:
                    end();
                    return;
                default:
                    return;
            }
        }
    }
    per.add(WPM, users[per.num].level);
    return;
}

void Level::level_1(){
    Theory th;
    Test t;
    Person per;
    int length = 0;
    int incorrect = 0;
    string text, answer, n;
    th.level_1();
    getchar();
    ifstream file ("/Users/stasskor/Documents/XCode Projects/Project C/Laba_Project/Course/Course/level1.txt");
    vector<string> texts;
    chrono::steady_clock::time_point clock = chrono::steady_clock::now() + chrono::seconds(60);
    
    cout << "You have one minute to test your typing speed" << endl;
    
    int line = -1;
    
    if (file.fail()){
        cout << "Error" << endl;
        return;
    } else if(file.is_open()){
        while(!file.eof()){
            line ++;
            getline(file, text);
            texts.push_back(text);
        }
        while(!(chrono::steady_clock::now() > clock)){
            srand(static_cast<unsigned int>(time(nullptr)));
            n = texts[rand() % line];
            cout << n << endl;
            cin >> answer;
            length = length + (sizeof(n));
            if(answer != n){
                incorrect ++;
                cout << "Incorrect" << endl << endl;
                cout << n << endl;
                cin  >> answer;
            }
        }
        file.close();
        cout << "There is no time left!" << endl;
        if(incorrect == 0){
            users[per.num].level++;
        }
        t.results(length, incorrect);
    }
}

void Level::level_2(){
    Test t;
    Person per;
    int length = 0;
    int incorrect = 0;
    string text, answer, n;
    Theory th;
    th.level_2();
    getchar();
    ifstream file ("/Users/stasskor/Documents/XCode Projects/Project C/Laba_Project/Course/Course/level2.txt");
    vector<string> texts;
    chrono::steady_clock::time_point clock = chrono::steady_clock::now() + chrono::seconds(60);
    
    cout << "You have one minute to test your typing speed" << endl;
    
    int line = -1;
    
    if (file.fail()){
        cout << "Error" << endl;
        return;
    } else if(file.is_open()){
        while(!file.eof()){
            line ++;
            getline(file, text);
            texts.push_back(text);
        }
        while(!(chrono::steady_clock::now() > clock)){
            srand(static_cast<unsigned int>(time(nullptr)));
            n = texts[rand() % line];
            cout << n << endl;
            cin >> answer;
            length = length + (sizeof(n));
            if(answer != n){
                incorrect ++;
                cout << "Incorrect" << endl << endl;
                cout << n << endl;
                cin  >> answer;
            }
        }
        file.close();
        cout << "There is no time left!" << endl;
        if(incorrect == 0){
            users[per.num].level++;
        }
        t.results(length, incorrect);
    }
}

void Level::level_3(){
    Test t;
    Person per;
    int length = 0;
    int incorrect = 0;
    string text, answer, n;
    Theory th;
    th.level_3();
    getchar();
    ifstream file ("/Users/stasskor/Documents/XCode Projects/Project C/Laba_Project/Course/Course/level3.txt");
    vector<string> texts;
    chrono::steady_clock::time_point clock = chrono::steady_clock::now() + chrono::seconds(60);
    
    cout << "You have one minute to test your typing speed" << endl;
    
    int line = -1;
    
    if (file.fail()){
        cout << "Error" << endl;
        return;
    } else if(file.is_open()){
        while(!file.eof()){
            line ++;
            getline(file, text);
            texts.push_back(text);
        }
        while(!(chrono::steady_clock::now() > clock)){
            srand(static_cast<unsigned int>(time(nullptr)));
            n = texts[rand() % line];
            cout << n << endl;
            cin >> answer;
            length = length + (sizeof(n));
            if(answer != n){
                incorrect ++;
                cout << "Incorrect" << endl << endl;
                cout << n << endl;
                cin  >> answer;
            }
        }
        file.close();
        cout << "There is no time left!" << endl;
        if(incorrect == 0){
            users[per.num].level++;
        }
        t.results(length, incorrect);
    }
}

void Level::level_4(){
    Test t;
    Person per;
    int length = 0;
    int incorrect = 0;
    string text, answer, n;
    Theory th;
    th.level_4();
    getchar();
    ifstream file ("/Users/stasskor/Documents/XCode Projects/Project C/Laba_Project/Course/Course/level4.txt");
    vector<string> texts;
    chrono::steady_clock::time_point clock = chrono::steady_clock::now() + chrono::seconds(60);
    
    cout << "You have one minute to test your typing speed" << endl;
    
    int line = -1;
   
    if (file.fail()){
        cout << "Error" << endl;
        return;
    } else if(file.is_open()){
        while(!file.eof()){
            line ++;
            getline(file, text);
            texts.push_back(text);
        }
        while(!(chrono::steady_clock::now() > clock)){
            srand(static_cast<unsigned int>(time(nullptr)));
            n = texts[rand() % line];
            cout << n << endl;
            cin >> answer;
            length = length + (sizeof(n));
            if(answer != n){
                incorrect ++;
                cout << "Incorrect" << endl << endl;
                cout << n << endl;
                cin  >> answer;
            }
        }
        file.close();
        cout << "There is no time left!" << endl;
        if(incorrect == 0){
            users[per.num].level++;
        }
        t.results(length, incorrect);
    }
}

void Level::level_5(){
    Test t;
    Person per;
    int length = 0;
    int incorrect = 0;
    string text, answer, n;
    Theory th;
    th.level_5();
    getchar();
    ifstream file ("/Users/stasskor/Documents/XCode Projects/Project C/Laba_Project/Course/Course/level5.txt");
    vector<string> texts;
    chrono::steady_clock::time_point clock = chrono::steady_clock::now() + chrono::seconds(60);
    
    cout << "You have one minute to test your typing speed" << endl;
    
    int line = -1;
    
    if (file.fail()){
        cout << "Error" << endl;
        return;
    } else if(file.is_open()){
        while(!file.eof()){
            line ++;
            getline(file, text);
            texts.push_back(text);
        }
        while(!(chrono::steady_clock::now() > clock)){
            srand(static_cast<unsigned int>(time(nullptr)));
            n = texts[rand() % line];
            cout << n << endl;
            cin >> answer;
            length = length + (sizeof(n));
            if(answer != n){
                incorrect ++;
                cout << "Incorrect" << endl << endl;
                cout << n << endl;
                cin  >> answer;
            }
        }
        file.close();
        cout << "There is no time left!" << endl;
        if(incorrect == 0){
            users[per.num].level++;
        }
        t.results(length, incorrect);
    }
}

void Level::level_6(){
    Test t;
    Person per;
    int length = 0;
    int incorrect = 0;
    string text, answer, n;
    Theory th;
    th.level_6();
    getchar();
    ifstream file ("/Users/stasskor/Documents/XCode Projects/Project C/Laba_Project/Course/Course/level6.txt");
    vector<string> texts;
    chrono::steady_clock::time_point clock = chrono::steady_clock::now() + chrono::seconds(60);
    
    cout << "You have one minute to test your typing speed" << endl;
    
    int line = -1;
    
    if (file.fail()){
        cout << "Error" << endl;
        return;
    } else if(file.is_open()){
        while(!file.eof()){
            line ++;
            getline(file, text);
            texts.push_back(text);
        }
        while(!(chrono::steady_clock::now() > clock)){
            srand(static_cast<unsigned int>(time(nullptr)));
            n = texts[rand() % line];
            cout << n << endl;
            cin >> answer;
            length = length + (sizeof(n));
            if(answer != n){
                incorrect ++;
                cout << "Incorrect" << endl << endl;
                cout << n << endl;
                cin  >> answer;
            }
        }
        file.close();
        cout << "There is no time left!" << endl;
        if(incorrect == 0){
            users[per.num].level++;
        }
        t.results(length, incorrect);
    }
}

void Theory:: level_1(){
    cout << "The basic concept of fast typing is quickly explained: " << endl
         << "Your fingers take up a fixed starting position, from where you can reach any key you need." << endl
         << "Your left fingers are placed on the keys A, S, D and F." << endl
         << "Your right fingers are on the keys J, K, L and semicolon. Your thumbs are on the space bar." << endl;
    cout << "Let's start with learning how to fast type the characters e, t, a, o." << endl;
    cout << "Press any key to continue" << endl;
    getchar();
}

void Theory:: level_2(){
    cout << "Let's continue with learning how to fast type the characters n, i, h, s, r." << endl;
    cout << "Press any key to continue" << endl;
    getchar();
}

void Theory:: level_3(){
    cout << "Let's continue with learning how to fast type the characters d, l, u, m." << endl;
    cout << "Press any key to continue" << endl;
    getchar();
}

void Theory:: level_4(){
    cout << "Let's continue with learning how to fast type the characters w, c, g, f." << endl;
    cout << "Press any key to continue" << endl;
    getchar();
}

void Theory:: level_5(){
    cout << "Let's continue with learning how to fast type the characters y, p, b, v, k." << endl;
    cout << "Press any key to continue" << endl;
    getchar();
}

void Theory:: level_6(){
    cout << "Let's continue with learning how to fast type the characters `, j, x, q, z." << endl;
    cout << "Press any key to continue" << endl;
    getchar();
}

void Theory:: Congrats(){
    cout << "Wow! You`ve learned how to fast type all of the characters." << endl;
    cout << "Let`s have a final test!" << endl;
    cout << "Press any key to continue" << endl;
    getchar();
}

void choose(){
    int i;
    cout << "What level would you like to choose?(1-7)" << endl;
    cin >> i;
    while( i < 1 || i > 7){
        cout << "Error! Not correct data" << endl << "What level would you like to choose?(1-7)" << endl;
        cin >> i;
    }
    int length = 0;
    int incorrect = 0;
    string text, answer, n;
    ifstream file;
    switch (i){
        case 1:
            file.open("/Users/stasskor/Documents/XCode Projects/Project C/Laba_Project/Course/Course/level1.txt");
            break;
        case 2:
            file.open("/Users/stasskor/Documents/XCode Projects/Project C/Laba_Project/Course/Course/level2.txt");
            break;
        case 3:
            file.open("/Users/stasskor/Documents/XCode Projects/Project C/Laba_Project/Course/Course/level3.txt");
            break;
        case 4:
            file.open("/Users/stasskor/Documents/XCode Projects/Project C/Laba_Project/Course/Course/level4.txt");
            break;
        case 5:
            file.open("/Users/stasskor/Documents/XCode Projects/Project C/Laba_Project/Course/Course/level5.txt");
            break;
        case 6:
            file.open("/Users/stasskor/Documents/XCode Projects/Project C/Laba_Project/Course/Course/level6.txt");
            break;
        case 7:
            file.open("/Users/stasskor/Documents/XCode Projects/Project C/Laba_Project/Course/Course/All.txt");
            break;
        default:
            return;
    }
    vector<string> texts;
    chrono::steady_clock::time_point clock = chrono::steady_clock::now() + chrono::seconds(60);
    
    cout << "You have one minute to test your typing speed" << endl;
    
    int line = -1;
    
    if (file.fail()){
        cout << "Error" << endl;
        return;
    } else if(file.is_open()){
        while(!file.eof()){
            line ++;
            getline(file, text);
            texts.push_back(text);
        }
        while(!(chrono::steady_clock::now() > clock)){
            srand(static_cast<unsigned int>(time(nullptr)));
            n = texts[rand() % line];
            cout << n << endl;
            cin >> answer;
            length = length + (sizeof(n));
            if(answer != n){
                incorrect ++;
                cout << "Incorrect" << endl << endl;
                cout << n << endl;
                cin  >> answer;
            }
        }
        file.close();
        cout << "There is no time left!" << endl;
    }
    
    int WPM = 0;
    
    WPM = (length/5)/ 1.0;
    cout << endl;
    cout << "==============================" << endl
         << "=          Results           =" << endl
         << "==============================" << endl << endl
         << "Characters typed: " << length << "" << endl
         << "Incorrect words: " << incorrect << "" << endl
         << "WPM: " << WPM << "" << endl << endl;
}

int main() {
    Person view;
    Level l;
   
    int choice;
    do{
        cout << "    =================================" << endl
             << "                   MENU" << endl
             << "    =================================" << endl
             << "  1) Start Learning" << endl
             << "  2) Leaderboard" << endl
             << "  3) Choose level" << endl
             << "  4) Exit" << endl << endl;
        cin >> choice;
        
        if (choice == 1) {
            l.level_1();
        } else if (choice == 2) {
            view.leaderboard();
        } else if (choice == 3) {
            choose();
        } else if (choice == 4) {
            return 0;
        } else {
            cout << "Not correct" << endl;
        }
    }while (choice != 4);
}
