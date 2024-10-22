#include "CSZNode.h"
#include <iostream>
#include <fstream>
#include <limits>
using std::cout;
using std::endl;

CityStateZip read_CityStateZip( std::istream& fin ) {
    std::string  city, state;
    unsigned int zip = 0;
    getline( fin, city, ',' );
    getline( fin, state, ',' );
    fin >> zip;
    fin.ignore( std::numeric_limits<std::streamsize>::max( ), '\n' );
    return CityStateZip{city, state, zip}; // creates a temporary CityStateZip object and returns it
}

int main(){
    std::ifstream fin{"city_list.txt"};
if ( !fin ) {
  cout << "Error opening city_list.txt!\n";
  exit( 1 );
}

CSZNode n1{read_CityStateZip( fin )};
CSZNode n2{read_CityStateZip( fin )};

cout << "test CSZNodes:\n";
cout << n1 << endl;
cout << n2 << endl;
cout << endl;

    return 0;
}