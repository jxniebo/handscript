#include <iostream>
#include "message.h"

using namespace std;
int main() {
	cout << DIVIDE_LINE << endl << PROGRAM_FUNC_LABEL << PROGRAM_FUNC_FIGURE1 << endl;
	cout << INPUT_NOTE << endl;

	int value;
	cin >> value;
	int tmp = value;
	int count = 0;
	while(tmp != 0) {
		tmp &= tmp - 1;		
		count++;
	}

	cout << "There are " << count << " of 1 in binary value of " << value << endl;
	return 0;
}
