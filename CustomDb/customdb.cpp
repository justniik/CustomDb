// CustomDb.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

bool isOpenDB = false;

void CreateDatabase();
void CreateTable(string value);
bool ConnectDB();

sqlite3 *dbfile;
string dbName;
string ext = ".db";
customdbvm setget;
void main()
{
	string tableName;
	cout << "Enter your database name:"<<endl;
	cout << "sqlite3 > ";
	cin >> dbName;
	setget.setDatabase(dbName);
	CreateDatabase();
	cout << "Enter your tableName name:"<<endl;
	cout << "sqlite3 > ";
//	cin >> tableName;
	try
	{
		cin.ignore();
	getline (cin,tableName);
	}
	catch(int i)
	{
		cout <<"exception -------->";
	}
	CreateTable(tableName);
	
	getch();
}

void CreateDatabase()
{
	
	bool test = ConnectDB();

	if(test)
	{
		cout << "Database created successfully "<<endl;
	}
	else
	{
		cout << "Database not created."<<endl;
	}

}

void CreateTable(string value)
{
	try
	{
		std::stringstream strm;
	strm << value;

	string s = strm.str();
	char *str = &s[0];

		sqlite3_stmt *statement;
	int result = 0;

	char *query = str;
	{
		int value = sqlite3_prepare(dbfile,query,-1,&statement,0);

		if(value == SQLITE_OK)
		{
			int res=sqlite3_step(statement);
			result=res;
			sqlite3_finalize(statement);
			cout<<"table created scussfully"<<endl;
		}
		else
		{
			cout<<"table not created."<<endl;
		}
	}

	}
	catch(exception)
	{
		cout << "somthing worng";
	}

}

void InsertValue(string insertvalue)
{
		try
	{
		std::stringstream strm;
	strm << insertvalue;

	string s = strm.str();
	char *str = &s[0];

		sqlite3_stmt *statement;
	int result = 0;

	char *query = str;
	{
		int value = sqlite3_prepare(dbfile,query,-1,&statement,0);

		if(value == SQLITE_OK)
		{
			int res=sqlite3_step(statement);
			result=res;
			sqlite3_finalize(statement);
			cout<<"value inserted successfully";
		}
		else
		{
			cout<<"value not inserted.";
		}
	}

	}
	catch(exception)
	{
		cout << "somthing worng";
	}

}


bool ConnectDB ()
{
	string s = setget.getDatabase()+ext;
	char *str = &s[0];
	if ( sqlite3_open(str, &dbfile) == SQLITE_OK )
	{
		isOpenDB = true;
		return true;
	}		 

	return false;
}

void DisonnectDB ()
{
	if ( isOpenDB == true ) 
	{
		sqlite3_close(dbfile);
	}
}