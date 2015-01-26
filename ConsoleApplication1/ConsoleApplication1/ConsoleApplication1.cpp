#include <iostream>
#include "fixed_class.h"

void screenStay();


int main()
{
	using namespace fixedpoint;
	const int p = 8;
	fixed_point<p> b=fixed_point<p>(15.16); 

	float c = fix2float<p>(b.intValue);

	std::cout << c << std::endl;
	screenStay();
	return 0;
}

//======================================================================================//

void screenStay()
{
	using namespace std;
	cout << endl<<"Press any key to exit...";
	cin.clear();
	cin.ignore(255, '\n');
	cin.get();
}