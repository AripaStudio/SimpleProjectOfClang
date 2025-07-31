module TodoListJsonDlang;

import std.stdio;
import JsonDAP;
import std.typecons; 

alias Optional = Nullable; 


struct TodoList{
	int id;
	string Name;
	string Lastname;
}

void main()
{
	writeln("hello world");
}



class ToDoListManagaer{

	public void LoadOrCreate()
	{

	}

	public void SaveFile()
	{

	}

	public bool Add()
	{
		return true;
	}

	public bool Delete()
	{
		return true;
	}

	public bool Edit()
	{
		return true;
	}

	public bool ShowAll()
	{
		return true;
	}

	public bool Search()
	{
		return true;
	}

	
}