/*
Naam: Hidde Camstra
Studentnummer: 1898363
Opdracht in dit bestand: Functies, basis.
*/

#include <iostream> 
#include <vector>
using namespace std;

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

int main(){ 
    // Functies, basis:
    vector<int> n = {37,4,9,4,9,37,3,5,0,4,1};
    int number_of_fours = count(n, 4);
    cout << "Number of fours: " << number_of_fours << "\n";
    
    // Deel 2:
    cout << "Gegeven getal controle: " << vector_controle({0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}) << "\n";
}