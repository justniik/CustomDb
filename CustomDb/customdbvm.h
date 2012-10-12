#pragma once
#ifndef CUSTOMDBVM_H
#define CUSTOMDBVM_H

#include <string>

class customdbvm
{

public:
	void setDatabase(std::string dbnameValue);
	std::string getDatabase();
};

#endif