/*
Naam: Hidde Camstra
Studentnummer: 1898363
Opdracht in dit bestand: Functies, basis, Functies, palingdroom.
*/

#include <iostream> 
#include <vector>
#include <string>
using namespace std;

// Functies, basis:

int count(const vector<int> & numbers, const int x) {
    int y = 0;

    for (size_t i = 0; i < numbers.size(); i++)
    {
        //cout << numbers[i];
        if (numbers[i] == x){
            y++;
        }
        //cout << y;
    }

    return y;
}

bool vector_controle(vector<int> gegeven_int){
    int aantal_nullen = count(gegeven_int, 0);
    int aantal_enen = count(gegeven_int, 1);
    
    if (aantal_nullen + aantal_enen == gegeven_int.size() && aantal_enen > aantal_nullen && aantal_nullen < 13){
        return true;
    }
    else{
        return false;
    }
}

// Functies, palindroom:

/*Schrijf een functie reverse() die een string omdraait.

Je mag hiervoor geen nieuwe string of vector aanmaken en
je mag niet gebruik maken van de swap-functie die wordt gegeven door C++ (libraries).
Je mag hiervoor wel een nieuwe tijdelijke character variabele gebruiken*.
Zorg dat de functie werkt in de onderstaande functie isPalindroom().
Test de functie met de volgende woorden: stekkerdoos, Halloween, lepel, flesje en bommelding*.*/

string reverse(string my_word){
    char my_char = 'a';
    //cout << "my word: " << my_word << "\n";
    
    int init_size = my_word.size();
    //cout << "size of word: " << init_size << "\n";

    for (size_t i = 0; i < init_size; i++)
    {
        // debug
        //cout << "my i : " << i << "\n";
        
        // actual code
        my_char = my_word[init_size - (i + 1)];
        my_word += my_char;
        
        // debug
       // cout << "my current char: " << my_char << "\n";
        //cout << "my current word: " << my_word << "\n";
    }

    my_word.erase(0, init_size);

    return my_word;
}

bool isPalindroom(const string& word){
    string orginalWord = word;
    orginalWord = reverse(orginalWord);

    //cout << "original: " << orginalWord << " my word: " << word << "\n";
    for(unsigned int i=0; i<word.size(); i++){
        if(word[i] != orginalWord[i]){
        return false;
        }
    }
    return true;
}

/* De bovenstaande gegeven functie isPalindroom() is eigenlijk niet zo heel mooi. 
Het is namelijk helemaal niet nodig om de reverse functie te gebruiken. 
Schrijf je eigen isPalindroom() functie die zonder het woord om te draaien of te kopieren controleert of het woord een palindroom is. 
Hint: word[word.size-1] geeft de laatste letter van het woord.*/

bool my_is_palingdroom(string my_cool_word){
    string orginalWord = my_cool_word;

    for(unsigned int i=0; i<my_cool_word.size(); i++){
        // debug
        //cout << "my_cool_word[i]: " << my_cool_word[i] << " orginalWord[my_cool_word.size() - i -1: " << orginalWord[my_cool_word.size() - i -1] << "\n";
        if(my_cool_word[i] != orginalWord[my_cool_word.size() - i -1]){
        return false;
        }
    }
    return true;
}


int main(){ 
    // Functies, basis:
    vector<int> n = {37,4,9,4,9,37,3,5,0,4,1};
    int number_of_fours = count(n, 4);
    cout << "Number of fours: " << number_of_fours << "\n";
    
    // Deel 2:
    cout << "Gegeven getal controle: " << vector_controle({0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}) << "\n";

    // Functies, palindroom:
    // 2.12 A:
    cout << "palin: " << isPalindroom("stekkerdoos") << "\n";
    cout << "palin: " << isPalindroom("halloween") << "\n";
    cout << "palin: " << isPalindroom("lepel") << "\n";
    cout << "palin: " << isPalindroom("flesje") << "\n";
    cout << "palin: " << isPalindroom("bommelding") << "\n";

    // 2.12 B:
    cout << "my palin: " << my_is_palingdroom("stekkerdoos") << "\n";
    cout << "my palin: " << my_is_palingdroom("halloween") << "\n";
    cout << "my palin: " << my_is_palingdroom("lepel") << "\n";
    cout << "my palin: " << my_is_palingdroom("flesje") << "\n";
    cout << "my palin: " << my_is_palingdroom("bommelding") << "\n";
}