/*
Naam: Hidde Camstra
Studentnummer: 1898363
Opdracht in dit bestand: Functies, basis, Functies, palingdroom, Vector, Vector sorteren.
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


// Vector:

vector<int> positive1(vector<int> numbers){
    for(unsigned int i=0; i<numbers.size(); i++){
        if(numbers[i] < 0){
            numbers[i] *= -1;
        }
    }
    return numbers;
}

void positive2(vector<int> & numbers){
    for(unsigned int i=0; i<numbers.size(); i++){
        if(numbers[i] < 0){
            numbers[i] *= -1;
        }
    }
}

vector<int> positive3(const vector<int> & numbers){
    vector<int> newNumbers = numbers;

    for(unsigned int i=0; i<newNumbers.size(); i++){
        if(newNumbers[i] < 0){
            newNumbers[i] *= -1;
        }
    }
    return newNumbers;
}

/*Schrijf een functie die van een gegeven vector controleert of de getallen zijn gesorteerd van laag naar hoog. 
Bedenk zelf een goede naam voor de functie en wat de functie teruggeeft.*/

bool check_if_sorted(vector<int> numbers){
    for (size_t i = 0; i < numbers.size() - 1; i++)
    {
        // debug
        //cout << "numbers[i]: " << numbers[i] << " numbers[i + 1]: " << numbers[i + 1] << "\n";
        if(numbers[i] > numbers[i + 1]){
            return false;
        }
    }
    return true;
}

/* 

Schrijf een programma dat de gebruiker vraagt om een reeks getallen in te voeren door steeds één getal te geven.

Als de gebruiker een negatief getal geeft, dan is de reeks compleet.
Stop de getallen in een vector.
Het negatieve getal neem je niet mee in de vector.
Het programma print vervolgens op het scherm

of de reeks gesorteerd is,
wat de gemiddelde waarde is,
wat zijn minimum waarde is en
hoeveel getallen de reeks bevat.
Zorg ervoor dat in de main()-functie zo min mogelijk code staat. Maak gebruik van je code van de eerdere opdrachten.

*/

void my_program(){
    vector<int> my_vector;
    int my_int;
    cout << "\nGive int pls: "; //  get input
    cin >> my_int;
    my_vector.push_back(my_int);

    //cout << "print my int: " << my_int << "\n";

    while (true)
    {
        if (my_int >= 0){ // got positive number
            cout << "\nGive int pls: "; //  get new input
            cin >> my_int;
            if (my_int >= 0){
                my_vector.push_back(my_int);
            }
        }
        else{ // got negative number
            float total = 0;
            int smallest_number = my_vector[0];
            for (size_t i = 0; i < my_vector.size(); i++)
            {
                total += my_vector[i];
                //cout << "my total: " << total << "\n";
                if (my_vector[i] < smallest_number){
                    smallest_number = my_vector[i];
                }
            }
            
            // print results:
            cout << "\n";
            cout << "De vector is gesorteerd (1 = true, 0 = false): " << check_if_sorted(my_vector) << "\n";
            cout << "Gemiddelde van vector: " << total / my_vector.size() << "\n";
            cout << "Kleinste getal van vector: " << smallest_number << "\n";
            cout << "Aantal waardes van vector: " << my_vector.size() << "\n";
            cout << "\n";
            return;
        }
    }
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

    // Vector:
    /*
    
    2.3A: Beschrijf in één zin wat de functie positive1() doet.

    antwoord: vraagt om een vector van ints, loopt er volledig doorheen, checkt of elk getal niet negatief is en als het getal dat wel is dan maakt die hem positief.


    2.3B: De functie positive2() heeft geen return-statement. Hoe geeft de functie zijn resultaat terug?
    
    antwoord: heeft geen return-waarde, maar past de oorspronkelijke vector aan.
    
    2.3C: De drie functies vervullen alle drie ongeveer dezelfde taak. Ze verschillen voornamelijk in hun functiedeclaratie. 
    [^1] Noem van elke functie een voordeel van de functiedeclaratie. [^1] Ook wel functiehandtekening of prototype genoemd.

    positive1(): De functie is een mix van snel en overzichtelijk. Sneller dan 3. Maar meer overzichtelijk dan 2. En je kunt vector retournen dus makkelijk gebruiken.

    positive2(): De vector wordt rechtstreeks doorgegeven. Dit lijkt mij sneller

    positive3(): De originele vector wordt niet gewijzigd, en een nieuwe vector wordt gegeven. Wat overzichtelijker is.


    2.3D: Welke functie heeft in dit geval je voorkeur? Geef minimaal één argument.
    antwoord: mijn voorkeur gaat uit naar de derde functie, omdat het aanmaken van een nieuwe vector maakt het overzichtelijker naar mijn mening.

    */
    //Opdracht 2.13 Gesorteerde vector:

    cout << "Check if sorted: " << check_if_sorted({0,1,2,3,4}) << "\n"; // sorted
    cout << "Check if sorted: " << check_if_sorted({37,4,9,4,9,37,3,5,0,4,1}) << "\n"; // no sort :(

    //Opdracht 2.14 Vector Input:
    my_program();
}