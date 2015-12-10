#pragma once
#include <iostream>
#include <string>

using namespace std;

class Exception
{
public:
	Exception(string m) : msg(m) {}
	void setMessage(string m) { msg = m; }
	string getMessage() { return msg; }
	void report()
	{
		cout << "Exception : " << msg << endl;
	}
private:
	string msg; 
};


