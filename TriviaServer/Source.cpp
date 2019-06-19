#include <iostream>
#include "JsonPacketSerializer.h"

using namespace std;

int main()
{	
	ErrorResponse test = { "Hello World" };
	vector<char> bytes = JsonPacketSerializer::serializeResponse(test);

	for (auto it = bytes.begin(); it != bytes.end(); it++)
	{
		cout << *it << " - " << (int)*it << endl;
	}

	system("pause");

	return 0;
}
