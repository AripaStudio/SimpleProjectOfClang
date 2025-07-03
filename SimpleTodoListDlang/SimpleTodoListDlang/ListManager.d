module ListManager;

import std.stdio;
import std.algorithm;
import std.conv;
import std.range;
import std.string;

class CL_List
{
	int ID;
	string TaskName;
	string Title;
	string Description;
	string dueData;
	bool IsComplete;

	this(int id, string taskName, string title, string description, string dueDate, bool isComplete) {
        this.ID = id;
        this.TaskName = taskName;
        this.Title = title;
        this.Description = description;
        this.dueData = dueDate;
        this.IsComplete = isComplete;
    }
}

CL_List[] todolist;

static this()
{
	todolist = [];
}


class CL_ListManager
{
	
	int GetSumNewID()
	{
		if(todolist.length == 0)
		{
			return 1;
		}
		auto maxID = todolist.length;
		int IdInt = to!int(maxID);
		return IdInt;
	}
	
	void Add_List(CL_List list)
	{
		try
		{
			todolist ~= list;

		}catch(Exception e)
		{
			writeln("Error in Add LIst :" , e);			
		}
	}

	bool Add(string TaskName , string Title , string Description , string dueData , bool IsComplete)
	{
		if(stdAP.IsNullOrWhiteSpace(TaskName))
		{
			writeln("Task Name is Emtpy. Please Try Again");
			return false;
		}

		int ID = GetSumNewID();

		if(todolist.any!(t => t.TaskName.icmp(TaskName)))
		{
			writeln("A task with this name already exists.");
			return false;
		}


		// You can also use 'stdAP.checkTaskNameIsexists' for this check, 
		// but 'todolist.any!(t => t.TaskName.icmp(TaskName))' is the standard 
		// and more idiomatic D way to achieve this, offering better performance 
		// and readability.
		//if(stdAP.checkTaskNameIsexists(todolist , TaskName) == stdAP.NullableTypesBool.True)
		//{
		//
		//    writeln("A task with this name already exists.");
		//    return false;
		//}
		
		CL_List list = new CL_List(ID , TaskName, Title , Description , dueData , IsComplete);
		Add_List(list);
		writeln("Task added successfully.");

		return true;
	}

	

}

static class stdAP
{
	static enum NullableTypesBool
	{
		True,
		False,
		Null
	}

	static NullableTypesBool checkTaskNameIsexists(CL_List[] list , string tn)
	{

		if(list.length == 0)
		{
			return NullableTypesBool.Null;
		}
		if(IsNullOrWhiteSpace(tn))
		{
			return NullableTypesBool.Null;
		}				
		string tnSTR = tn.toLower();
		string chSTR = "";
		foreach(ch; list)
		{
			chSTR = ch.TaskName.toLower();
			if(chSTR == tnSTR)
			{
				return NullableTypesBool.True;
			}
		}	
		return NullableTypesBool.False;
	}


	static bool IsNullOrWhiteSpace(string text)
	{
		if(text == null || text == "")
		{
			return true;
		}
		auto output = true;
		foreach(char a ; text)
		{
			if(a != ' ' && a != '\t' && a != '\n')
			{
				output = false;
			}				
			
		}
		return output;
	}
}
