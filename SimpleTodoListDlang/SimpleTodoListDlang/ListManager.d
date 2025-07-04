module ListManager;

import std.stdio;
import std.algorithm;
import std.conv;
import std.range;
import std.string;
import std.array;

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
	

	bool Remove(string TaskName)
	{
		if (stdAP.IsNullOrWhiteSpace(TaskName))
		{
			writeln("Task Name is Emtpy. Please Try Again");
			return false;
		}		
		
		try
		{
			
			todolist = todolist.filter!(f => f.TaskName == TaskName).array;
			writeln("Task Deleted successfully.");
			return true;
		}catch(Exception e)
		{
			writeln("error in Remove List || error : \n" , e);
			return false;
		}
	}

	bool removeAll()
	{
		try
		{
			todolist.length = 0;
			writeln("Task Deleted all successfully.");
			return true;
		}catch(Exception e)
		{
			writeln("error in Remove All List || error : \n" , e);
			return false;
		}
	}

	bool Edit(string TaskName)
	{
		if(stdAP.IsNullOrWhiteSpace(TaskName))
		{
			writeln("Please Enter a TaskName Valid(for showall command you can type : help)");
			writeln("or List is Empty , Please Add Task");
			return false;
		}
		auto editList = stdAP.FindList_Todolist(TaskName , todolist);
		if(editList.ID == -1)
		{
			writeln("List Not Found OR Not Complete Please Try Again");
			return false;
		}

		writefln("Edit Task Name: (Press Enter to keep current: %s)", editList.TaskName);
		string inputTaskName = readln.chomp;
		if (!stdAP.IsNullOrWhiteSpace(inputTaskName))
		{
			editList.TaskName = inputTaskName;
		}

		writefln("Edit Title: (Press Enter to keep current: %s)", editList.Title);
		string inputTitle = readln.chomp;
		if (!stdAP.IsNullOrWhiteSpace(inputTitle))
		{
			editList.Title = inputTitle;
		}

		writefln("Edit Description: (Press Enter to keep current: %s)", editList.Description);
		string inputDescription = readln.chomp;
		if (!stdAP.IsNullOrWhiteSpace(inputDescription))
		{
			editList.Description = inputDescription;
		}

		writefln("Edit DueData: (Press Enter to keep current: %s)", editList.dueData);
		string inputDueData = readln.chomp;
		if (!stdAP.IsNullOrWhiteSpace(inputDueData))
		{
			editList.dueData = inputDueData;
		}

		writefln("Edit IsComplete (please Enter (yes/no): (Press Enter to keep current: %s" , editList.IsComplete);
		string inputIsComplete = readln.chomp;
		if(!stdAP.IsNullOrWhiteSpace(inputIsComplete))
		{
			if(inputIsComplete == "yes")
			{
				editList.IsComplete = true;
			}else if (inputIsComplete == "no")
			{
				editList.IsComplete = false;
			}else
			{
				writeln("Invalid input for 'Is Complete'. Keeping the current status.");
			}
		}


		return true;
	}

	bool showall()
	{
		if(todolist.length == 0)
		{
			writeln("No Tasks to disply.");
			return false;
		}
		try
		{
			foreach(list; todolist)
			{
				writefln("ID : %d" , list.ID);
				writefln("Name: %s" , list.TaskName);
				writefln("Title: %s" , list.Title);
				writefln("Description: %s" , list.Description);
				writefln("dueData: %s" , list.dueData);
				writefln("Is Complete: %s" , list.IsComplete);
				writeln("---------------------------------");
			}
			return true;
		}catch(Exception e)
		{
			writeln("Error in show all Data in list : \n" , e);
			return false;
		}
	}

	bool SearchAndShow(string TaskName)
	{
		if(stdAP.IsNullOrWhiteSpace(TaskName) || todolist.length == 0)
		{
			writeln("Please Enter a TaskName Valid(for showall command you can type : help)");
			writeln("or List is Empty , Please Add Task");
			return false;
		}
		try
		{
			foreach(list; todolist)
			{
				if(list.TaskName == TaskName)
				{
					writefln("ID : %d" , list.ID);
					writefln("Name: %s" , list.TaskName);
					writefln("Title: %s" , list.Title);
					writefln("Description: %s" , list.Description);
					writefln("dueData: %s" , list.dueData);
					writefln("Is Complete: %s" , list.IsComplete);
					writeln("---------------------------------");
				}
			}
			return true;
		}catch(Exception e)
		{
			writeln("Error in Searching : " , e);
			return false;
		}
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
		
	static CL_List FindList_Todolist(string TaskName , CL_List[] lists)
	{
		CL_List output = new CL_List(-1 , "" , "" , "" , "" , false);
		if(IsNullOrWhiteSpace(TaskName))
		{	
			return output;
		}
		if(lists.length == 0)
		{
			return output;
		}
		foreach(list; lists)
		{
			if(list.TaskName == TaskName)
			{
				output.ID = list.ID;
				output.TaskName = list.TaskName;
				output.Title = list.Title;
				output.Description = list.Description;
				output.dueData = list.dueData;
				output.IsComplete = list.IsComplete;
				break;
			}
		}
		if(output.ID == -1)
		{
			writeln("Error in FindListTodolist");
			return output;
		}
		return output;
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
