#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <locale>

using namespace std;

void filterByName(map<string, vector<string>> map, string str) {
  /*To make sure the search is not case sensitive*/
  locale loc;
  for (size_t i = 0; i < str.length(); i++) {
    str[i] = tolower(str[i], loc);
  }
  /*Iterating through the map (so that the filter is alphabetized) to find
  the names containing the input as a substring*/
  for (auto iter = map.begin(); iter != map.end(); iter++) {
    if (str == "") { //if no filter, prints all the pokemon names
      cout << iter->first << endl;
    } else {
      locale locName;
      string lowercaseName = iter->first; //made new string to not alter the one in the map
      for (size_t i = 0; i < iter->first.length(); i++) {
        lowercaseName[i] = tolower(iter->first[i], locName);
      }
      size_t findInput = lowercaseName.find(str);
      if (findInput != string::npos) {
        cout << iter->first << endl;
      }
    }
  }
}

void printPokemon(map<string, vector<string> > pokemon, string name) {

    auto start = high_resolution_clock::now();

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
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
        << duration.count() << " microseconds" << endl;

}

void printPokemon(unordered_map<string, vector<string> > pokemon, string name) {

    auto start = high_resolution_clock::now();

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
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
        << duration.count() << " microseconds" << endl;
}

int main() {
    bool textEntered = false;

    /** data structure setups **/
    ifstream ip("pokemon blanks replaced.csv");

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

    void filterByName(map<string, vector<string>> map, string str);
    string pokemon;
    /*string loop = "y";

    while(loop == "y"){
        cout << "Please enter a pokemon name: " << endl;
        cin >> pokemon;
        //makes the whole input lowercase
        locale inputLoc;
        for (size_t i = 0; i < pokemon.length(); i++) {
          pokemon[i] = tolower(pokemon[i], inputLoc);
        }
        //capitalizes the first letter so it can find the name correctly
        locale lowercaseLoc;
        pokemon[0] = toupper(pokemon[0], lowercaseLoc);
        locale inputLoc;
        printPokemon(mapPokemon, pokemon);
        cout << "Would you like to search another pokemon? (y/n): " << endl;
        cin >> loop;
    }
}
