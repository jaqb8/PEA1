//
// Created by kubaa on 01.11.2019.
//

#include "UI.h"
#include <limits>

using namespace std;

UI::UI() : TravellingSalesmanProblem(make_shared<TSP>()), BF(TravellingSalesmanProblem), BnB(TravellingSalesmanProblem) {}

void UI::start() {
    char selection = 0;
    string path;
    unsigned long noOfVertices = 0;
    int range = 0;
    string output;

    do {
        printMenu();
        cin >> selection;
        cout << endl;

        switch (selection) {
            case '1':
                cout << "Podaj sciezke pliku: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, path);

                try {
                    TravellingSalesmanProblem->loadTSP(path);
                } catch (const runtime_error &e) {
                    cerr << e.what() << endl;
                }
                break;
            case '2':
                output = TravellingSalesmanProblem->printData();
                cout << output << endl;
                break;
            case '3':
                try {
                    output = BF.showInfoBeforeRunning();
                    cout << output << endl;
                    output = BF.run();
                    cout << output << endl;
                } catch (const runtime_error &e) {
                    cerr << e.what() << endl;
                }
                break;
            case '4':
                try {
                    output = BnB.showInfoBeforeRunning();
                    cout << output << endl;
                    output = BnB.run();
                    cout << output << endl;
                } catch (const runtime_error &e) {
                    cerr << e.what() << endl;
                }
                break;
            case '5':
                try {
                    runTestMenu();
                } catch (const runtime_error &e) {
                    cerr << e.what() << endl;
                }

        }
    } while (selection != '0');
}

void UI::printMenu() {
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "--- PROBLEM KOMIWOJAZERA ---" << std::endl;
    std::cout << "1. Wczytaj macierz wierzcholkow z pliku" << std::endl;
    std::cout << "2. Wyswietl macierz wierzcholkow" << std::endl;
    std::cout << "3. Uruchom algorytm Brute-force" << std::endl;
    std::cout << "4. Uruchom algorytm Branch&Bound" << std::endl;
    std::cout << "5. Testy" << std::endl;
    std::cout << "0. Wyjscie" << std::endl;
    std::cout << "Wybor: ";
}

void UI::printTestMenu() {
    std::cout << "--- TESTY ---" << std::endl;
    std::cout << "1. Test nr 1 (" << test.getTestName('1') << ")" << std::endl;
    std::cout << "2. Test nr 2 (" << test.getTestName('2') << ")" << std::endl;
    std::cout << "3. Test nr 3 (" << test.getTestName('3') << ")" << std::endl;
    std::cout << "4. Test nr 4 (" << test.getTestName('4') << ")" << std::endl;
    std::cout << "5. Test nr 5 (" << test.getTestName('5') << ")" << std::endl;
    std::cout << "6. Test nr 6 (" << test.getTestName('6') << ")" << std::endl;
    std::cout << "0. Powrót" << std::endl;
    std::cout << "Wybór: ";
}

void UI::runTestMenu() {
    test.openFile();

    char selection = 0;
    std::string output;

    do {
        printTestMenu();

        std::cin >> selection;
        std::cout << std::endl;

        switch (selection) {
            case '1':
                try {
                    output = test.test1();
                    std::cout << output << std::endl;
                } catch (const std::runtime_error &e) {
                    std::cerr << e.what() << std::endl;
                }
                break;

            case '2':
                try {
                    output = test.test2();
                    std::cout << output << std::endl;
                } catch (const std::runtime_error &e) {
                    std::cerr << e.what() << std::endl;
                }
                break;

            case '3':
                try {
                    output = test.test3();
                    std::cout << output << std::endl;
                } catch (const std::runtime_error &e) {
                    std::cerr << e.what() << std::endl;
                }
                break;

            case '4':
                try {
                    output = test.test4();
                    std::cout << output << std::endl;
                } catch (const std::runtime_error &e) {
                    std::cerr << e.what() << std::endl;
                }
                break;

            case '5':
                try {
                    output = test.test5();
                    std::cout << output << std::endl;
                } catch (const std::runtime_error &e) {
                    std::cerr << e.what() << std::endl;
                }
                break;

            case '6':
                try {
                    output = test.test6();
                    std::cout << output << std::endl;
                } catch (const std::runtime_error &e) {
                    std::cerr << e.what() << std::endl;
                }
                break;

            case '0':
                break;

            default:
                std::cerr << "Wybrana opcja nie istnieje!" << std::endl;
                break;
        }
    } while (selection != '0');

    test.closeFile();
}