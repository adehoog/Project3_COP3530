// Project 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include<map>
#include <vector>
#include <TGUI/TGUI.hpp>
#include <chrono>

using namespace std;

string formatString(string input){
    /** formats pokemon input so first letter is upper and rest is lower **/
    //makes the whole input lowercase
    locale inputLoc;
    for (size_t i = 0; i < input.length(); i++) {
        input[i] = tolower(input[i], inputLoc);
    }
    //capitalizes the first letter so it can find the name correctly
    locale lowercaseLoc;
    input[0] = toupper(input[0], lowercaseLoc);
    return input;
}

void printPokemon(map<string, vector<string> > pokemon, tgui::EditBox::Ptr pokemonName, tgui::ChatBox::Ptr& display, tgui::ChatBox::Ptr& eff) {
    tgui::String temp = pokemonName->getText();
    string name = formatString(temp.toStdString());
    display->removeAllLines();
    eff->removeAllLines();

    auto start = std::chrono::high_resolution_clock::now();

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
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
    cout << "Efficiency: " << duration.count() << " microseconds" << endl;
    eff->addLine("Efficiency: " + to_string(duration.count()) + + " microseconds");
} 

void printPokemon(unordered_map<string, vector<string> > pokemon, tgui::EditBox::Ptr pokemonName, tgui::ChatBox::Ptr& display, tgui::ChatBox::Ptr& eff) {
    tgui::String temp = pokemonName->getText();
    string name = formatString(temp.toStdString());
    display->removeAllLines();
    eff->removeAllLines();

    auto start = std::chrono::high_resolution_clock::now();

    if (pokemon.find(name) == pokemon.end()) {
        cout << "Pokemon not found" << endl;
        display->addLine("Error: Pokemon not found. Please try again.");
    }
    else {
        unordered_map<string, vector<string> >::iterator it = pokemon.find(name);

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
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
    cout << "Efficiency: " << duration.count() << " microseconds" << endl;
    eff->addLine("Efficiency: " + to_string(duration.count()) + + " microseconds");
}

int main()
{
    bool textEntered = false;
    string mode = "none";

    /** data structure setups **/
    ifstream ip("pokemon blanks replaced.csv");

    if (!ip.is_open()) cout << "ERROR: file is not open";

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
    instructions->setPosition(470, 250);
    instructions->setLinesStartFromTop();
    instructions->addLine("Welcome to our data structures final project!");
    instructions->addLine("First, select to search with a map mode or an unordered map.");
    instructions->addLine("Then, enter a Pokemon name into the search bar and press search.");
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

    /** mode buttons **/
    auto mapMode = tgui::RadioButton::create();
    mapMode->setSize(25, 25);
    mapMode->setText("Map");
    mapMode->setPosition(470, 210);
    mapMode->onCheck([=, &mode]{mode = "map";});
    gui.add(mapMode);
    auto unmapMode = tgui::RadioButton::create();
    unmapMode->setSize(25, 25);
    unmapMode->setText("Unordered Map");
    unmapMode->setPosition(550, 210);
    unmapMode->onCheck([=, &mode]{mode = "unmap";});
    gui.add(unmapMode);

    /** Pokemon info **/
    tgui::ChatBox::Ptr pokemonInfo = tgui::ChatBox::create();
    pokemonInfo->setSize(315, 320);
    pokemonInfo->setTextSize(15);
    pokemonInfo->setPosition(30, 150);
    pokemonInfo->setLinesStartFromTop();
    gui.add(pokemonInfo);

    /** efficiency **/
    tgui::ChatBox::Ptr efficiency = tgui::ChatBox::create();
    efficiency->setSize(315, 50);
    efficiency->setTextSize(15);
    efficiency->setPosition(30, 300);
    efficiency->setLinesStartFromTop();
    gui.add(efficiency);

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
            if(mode == "none"){
                pokemonInfo->removeAllLines();
                pokemonInfo->addLine("Please enter a pokemon and select map or unordered map");
                textEntered = false;
            }
            else{
                if(mode == "map"){
                    printPokemon(mapPokemon, searchBar, pokemonInfo, efficiency);
                    textEntered = false;
                }
                else{ //unordered map
                    printPokemon(unorderedMapPokemon, searchBar, pokemonInfo, efficiency);
                    textEntered = false;
                }
            }
        }
        gui.draw();

        window.display();
    }
}
