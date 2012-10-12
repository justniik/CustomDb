#include "stdafx.h"


	std::string dbname;
	void customdbvm::setDatabase(std::string dbnameValue)
	{
		dbname = dbnameValue;
	}

	std::string customdbvm::getDatabase()
	{
		return dbname;
	}
