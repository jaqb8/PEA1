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
                printFileWarning();
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
    std::cout << "0. Wyjscie" << std::endl;
    std::cout << "Wybor: ";
}

void UI::printFileWarning() {
    std::cout << "Program nie wykonuje sprawdzania danych w pliku wejsciowym!" << std::endl;
    std::cout << "Upewnij sie ze jest on napisany zgodnie z ponizszym schematem:" << std::endl;
    std::cout << "Pierwsza linijka to pojedyncza liczba (calkowita, dodatnia, rozna od zera) oznaczajaca ilosc miast."
              << std::endl;
    std::cout
            << "Kolejne linijki to macierz X na X (X = liczba z pierwszej linijki), kolejne liczby w linijce oddzielone spacja, zawierajace odleglosci pomiedzy miastami (calkowite, dodatnie, rozne od zera). Przekatna macierzy zawiera liczby -1."
            << std::endl << std::endl;
    std::cout << "Przykladowy plik:" << std::endl;
    std::cout << "3" << std::endl << "-1 10 15" << std::endl << "20 -1 5" << std::endl << "25 30 -1" << std::endl
              << std::endl << std::endl;
}