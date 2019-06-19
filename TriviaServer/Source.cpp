#include <iostream>
#include "JsonPacketSerializer.h"

#define PRINT_BYTES(BUFF) for (auto it = BUFF.begin(); it != BUFF.end(); it++) cout << *it << " - " << (int)*it << endl;

using namespace std;

int main()
{	
	cout << "Error Response Test" << endl;

	ErrorResponse test = { "Hello World" };
	vector<char> bytes = JsonPacketSerializer::serializeResponse(test);

	PRINT_BYTES(bytes);

	cout << "Login/Signup Response Test" << endl;

	LoginResponse test2 = { LOGIN_SUCCESS };
	vector<char> bytes2 = JsonPacketSerializer::serializeResponse(test2);

	PRINT_BYTES(bytes2);
	
	system("pause");

	return 0;
}
