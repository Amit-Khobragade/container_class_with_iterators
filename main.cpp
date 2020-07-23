#include <iostream>
#include <string>
#include <iomanip>
#include "ring.h"

using namespace std;

inline void blank_line() { cout << endl << left << setfill( '-' ) << setw( 20 ) << "" << endl; }

int main() {
	ring<string> testring( 3 );
	testring.add( "one" );
	testring.add( "two" );
	testring.add( "three" );
	testring.add( "four" );
	cout << testring;
	blank_line();
	for (auto it = testring.begin(); it != testring.end(); it++)
		cout << *it << endl;
	blank_line();
	for (string s : testring)
		cout << s << endl;
}