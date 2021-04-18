#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include<map>
#include <vector>

using namespace std;

void printPokemon(map<string, vector<string> > pokemon, string name) {
    if (pokemon.find(name) == pokemon.end())
        cout << "Pokemon not found" << endl;
    else {
        map<string, vector<string> >:: iterator it = pokemon.find(name);

        cout << "Name: " << it->first << endl;
        cout << "Pokedex number: " << it->second[31] << endl;
        cout << "Primary Type: " << it->second[35] << endl;
        cout << "Secondary Type: " << it->second[36] << endl;
        cout << "Classification: " << it->second[24] << endl;
        cout << "Height(m): " << it->second[27] << endl;
        cout << "Weight(kg): " << it->second[37] << endl;
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

int main() {
    bool textEntered = false;

    /** data structure setups **/
    ifstream ip("pokemon_blanks_replaced.csv");

    if (!ip.is_open()) cout << "ERROR: file is not open";

    map<string, vector<string> > mapPokemon;
    unordered_map<string, vector<string> > unorderedMapPokemon;
    string name;
    string temp;

    //802 rows
    for (int i = 0; i < 802; i++) {

        vector<string> tempVector;

        //40 colums in one row
        //name is inindex 30
        for (int j = 0; j < 40; j++) {

            if (j == 30) {
                getline(ip, name, ',');

            } else {
                getline(ip, temp, ',');
                tempVector.push_back(temp);
            }
        }
        mapPokemon[name] = tempVector;
        unorderedMapPokemon[name] = tempVector;
        tempVector.clear();
    }

    string pokemon;
    string loop = "y";

    while(loop == "y"){
        cout << "Please enter a pokemon name (make sure to capitalize the first letter): " << endl;
        cin >> pokemon;
        printPokemon(mapPokemon, pokemon);
        cout << "Would you like to search another pokemon? (y/n): " << endl;
        cin >> loop;
    }
}
