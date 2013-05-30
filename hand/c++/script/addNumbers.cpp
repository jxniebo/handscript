#include <iostream>

#include <math.h>

using namespace std;

void printSpan(int start, int end) {
	int step = start < end ? 1 : -1;
	cout << "start from " << start << endl;	

	if(fabs(start - end) < 2) {
		cout << "\tno middle values";
	}
	else {
		for(int middle = start + step; middle != end; middle += step) {
			cout << "\t" << middle;
			if((int)fabs(middle - start) % 5 == 0) cout << endl;
		}
	}

	cout << endl << "end with " << end << endl;
}


int main() {
	cout << "Enter two numbers: " << endl;	
	int v = 200, sum = 0;

	int addV;
	while(cin >> addV) sum += addV;
	cout << "Total sum is: " << sum << endl;

	printSpan(v, sum);

	return 0;
}


class IsPositionMatters {
	public:
		int publicId;
	private:
		string privateId;
};



