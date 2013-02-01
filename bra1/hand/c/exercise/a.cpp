#include <iostream>

#include "message.h"

using namespace std;

int main() {
	cout << INPUT_NOTE << endl;	
	int range, sum = 0;
	cin >> range;

	for(int i = 1; i <= range; i++) {
		if(i % 3 == 0 || i % 5 == 0) {
			sum += i;		
		}		
	}
	cout << "the total sum is " << sum << endl;

	return 0;
}
