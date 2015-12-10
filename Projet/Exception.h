#pragma once
#include <iostream>
#include <string>

//Auteurs: Nicolas Daigle (7223444), Zachary Paquette (7230016)
//Cours: CSI2772
//Date de remise: 9 Decembre 2015

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


