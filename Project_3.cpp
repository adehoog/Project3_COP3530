// Project 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include<map>
#include <vector>
#include <TGUI/TGUI.hpp>

using namespace std;

void printPokemon(map<string, vector<string> > pokemon, tgui::EditBox::Ptr pokemonName, tgui::ChatBox::Ptr& display) {
    tgui::String temp = pokemonName->getText();
    string name = temp.toStdString();
    display->removeAllLines();
    if (pokemon.find(name) == pokemon.end()) {
        cout << "Pokemon not found" << endl;
        display->addLine("Error: Pokemon not found. Please try again.");
    }
    else {
        map<string, vector<string> >:: iterator it = pokemon.find(name);

        cout << "Name: " << it->first << endl;
        cout << "Pokedex number: " << it->second[31] << endl;
        cout << "Primary Type: " << it->second[35] << endl;
        cout << "Secondary Type: " << it->second[36] << endl;
        cout << "Classification: " << it->second[24] << endl;
        cout << "Height(m): " << it->second[27] << endl;
        cout << "Weight(kg): " << it->second[37] << endl;

        display->addLine("Name: " + it->first);
        display->addLine("Pokedex number: " + it->second[31]);
        display->addLine("Primary Type: " + it->second[35]);
        display->addLine("Secondary Type: " + it->second[36]);
        display->addLine("Classification: " + it->second[24]);
        display->addLine("Height(m): " + it->second[27]);
        display->addLine("Weight(kg): " + it->second[37]);
    }

}

void printPokemon(unordered_map<string, vector<string> > pokemon, string name) {

    if (pokemon.find(name) == pokemon.end())
        cout << "Pokemon not found" << endl;
    else {
        unordered_map<string, vector<string> >::iterator it = pokemon.find(name);

        cout << "Name: " << it->first << endl;
        cout << "Pokedex number: " << it->second[31] << endl;
        cout << "Primary Type: " << it->second[35] << endl;
        cout << "Secondary Type: " << it->second[36] << endl;
        cout << "Classification: " << it->second[24] << endl;
        cout << "Height(m): " << it->second[27] << endl;
        cout << "Weight(kg): " << it->second[37] << endl;
    }

}

<<<<<<< HEAD

int main() {
    ifstream ip;
    ip.open("pokemon_blanks_replaced.csv", std::ifstream::in);
=======
int main()
{
    bool textEntered = false;

    /** data structure setups **/
    ifstream ip("pokemon blanks replaced.csv");
>>>>>>> 3be67262d3cc1e30cbcc22cfd3c8d40078487b08

    if (!ip.is_open()) cout << "ERROR: file is not open" << endl;

    map<string, vector<string> > mapPokemon;
    unordered_map<string, vector<string> > unorderedMapPokemon;
    string name;
    string temp;

    //802 rows
    for(int i = 0; i< 802; i++) {

        vector<string> tempVector;

            //40 colums in one row
            //name is inindex 30
            for (int j = 0; j < 40; j++) {

                if (j == 30) {
                    getline(ip, name, ',');

                }
                else {
                    getline(ip, temp, ',');
                    tempVector.push_back(temp);
                }
            }
            mapPokemon[name] = tempVector;
            unorderedMapPokemon[name] = tempVector;
            tempVector.clear();

    }

<<<<<<< HEAD
    //for (auto member : pokemon)
       // cout << member.first << " " << member.second.size() << endl;

   // cout << "pokemon map size is: " << pokemon.size()<<endl;
    printPokemon(mapPokemon, "Bulbasaur");
    cout << endl;
    printPokemon(unorderedMapPokemon, "Bulbasaur");
    /*Mariana's code*/
    /*1) cin pokemon name to get pokemon
    2) create function that returns all names*/
    bool searching = true;
    string stop = ".";
    string input = "";
    while(searching) {
      getline(cin, input); //the input string will be whatever the user types in the interface
      if (input == stop) { //somehow connect this to search button
        searching = false;
      } else {
        cout << input << " processed :)" << endl;
      }
    }
    return 0;
=======
    /** window setup**/
    sf::RenderWindow window{{750, 550}, "Pokedex"};
    tgui::GuiSFML gui{window};
    gui.setTarget(window);

    /** background **/
    sf::Texture background;
    background.loadFromFile("pokedex_background.png");
    sf::Sprite pokedex;
    pokedex.setTexture(background);
    pokedex.scale(sf::Vector2f(1.5f, 1.5f));

    /** instructions **/
    auto instructions = tgui::ChatBox::create();
    instructions->setSize(250, 250);
    instructions->setTextSize(15);
    instructions->setPosition(470, 200);
    instructions->setLinesStartFromTop();
    instructions->addLine("Welcome to our data structures final project!");
    instructions->addLine("Enter a Pokemon name into the search bar and press enter.");
    instructions->addLine("Make sure to capitalize the first letter of the Pokemon's name and spell it correctly or the search will not work properly!");
    gui.add(instructions);

    /** search bar **/
    auto searchBar = tgui::EditBox::create();
    searchBar->setSize(150, 25);
    searchBar->setTextSize(12);
    searchBar->setPosition(470, 170);
    searchBar->setDefaultText("type to search...");
    gui.add(searchBar);

    /** search button **/
    auto button = tgui::Button::create("Search");
    button->setSize(50, 25);
    button->setPosition(625, 170);
    button->onPress([=, &textEntered]{textEntered = true;});
    gui.add(button);

    /** Pokemon info **/
    tgui::ChatBox::Ptr pokemonInfo = tgui::ChatBox::create();
    pokemonInfo->setSize(315, 320);
    pokemonInfo->setTextSize(15);
    pokemonInfo->setPosition(30, 150);
    pokemonInfo->setLinesStartFromTop();
    gui.add(pokemonInfo);


    /** window loop **/
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            gui.handleEvent(event);

            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(pokedex);
        if(textEntered){
            printPokemon(mapPokemon, searchBar, pokemonInfo);
            textEntered = false;
        }
        gui.draw();

        window.display();
    }
>>>>>>> 3be67262d3cc1e30cbcc22cfd3c8d40078487b08
}
