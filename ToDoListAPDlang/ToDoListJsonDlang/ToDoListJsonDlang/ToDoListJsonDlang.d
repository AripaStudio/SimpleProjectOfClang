module TodoListJsonDlang;


import std.stdio;
import std.typecons;
import std.conv : to;
import std.string;
import std.algorithm : find, remove, map;
import std.array : array;
import JsonDAP;




alias Optional = Nullable;


struct TodoList
{
	int id;
	string Name;
	string Lastname;
	string NameTask;
	bool IsComplete;
}


class ToDoListManagaer
{
	private TodoList[] _tasks;
	private immutable string _filePath = "tasks.json";

	public this()
	{
		this.LoadOrCreate();
	}

	public void LoadOrCreate()
	{
		if (JsonAP.APexistsFile(_filePath))
		{
			auto optionalTasks = JsonAP.APreadJsonFile!TodoList(_filePath);
			if (!optionalTasks.isNull)
			{
				_tasks = optionalTasks.get;
				writeln("Tasks loaded successfully.");
			}
			else
			{
				writeln("Error loading tasks, creating a new empty list.");
				_tasks = [];
				this.SaveFile();
			}
		}
		else
		{
			writeln("File not found, creating a new empty list.");
			_tasks = [];
			this.SaveFile();
		}
	}

	public bool SaveFile()
	{
		return JsonAP.APwriteJsonFile!TodoList(_filePath, _tasks);
	}

	public bool Add(string name, string lastname, string nameTask)
	{
		int newId = 1;
		if (_tasks.length > 0)
		{
			int maxId = 0;
			foreach (task; _tasks)
			{
				if (task.id > maxId)
				{
					maxId = task.id;
				}
			}
			newId = maxId + 1;
		}

		auto newTask = TodoList(newId, name, lastname, nameTask, false);
		_tasks ~= newTask;
		writeln("Task added with ID: ", newId);
		return this.SaveFile();
	}

	public bool Delete(int id)
	{
		auto foundIndex = _tasks.std.algorithm.searching.countUntil!((task) => task.id == id);
		if (foundIndex == -1)
		{
			writeln("Task with ID ", id, " not found.");
			return false;
		}

		_tasks = _tasks.remove(foundIndex);
		writeln("Task with ID ", id, " deleted.");
		return this.SaveFile();
	}

	public bool Edit(int id, string name, string lastname, string nameTask, bool isComplete)
	{
		auto foundIndex = _tasks.std.algorithm.searching.countUntil!((task) => task.id == id);
		if (foundIndex == -1)
		{
			writeln("Task with ID ", id, " not found for editing.");
			return false;
		}

		auto updatedTask = TodoList(id, name, lastname, nameTask, isComplete);
		_tasks[foundIndex] = updatedTask;
		writeln("Task with ID ", id, " edited.");
		return this.SaveFile();
	}

	public void ShowAll()
	{
		if (_tasks.length == 0)
		{
			writeln("No tasks found.");
			return;
		}

		writeln("--- All Tasks ---");
		foreach (task; _tasks)
		{
			writeln("ID: ", task.id, ", Name: ", task.Name, ", Lastname: ", task.Lastname, ", Task: ", task.NameTask, ", IsComplete: ", task.IsComplete);
		}
		writeln("-----------------");
	}

	public void Search(string searchTerm)
	{
		writeln("--- Search Results for '", searchTerm, "' ---");
		bool found = false;
		foreach (task; _tasks)
		{
			if (task.NameTask.to!string.find(searchTerm).length > 0 || task.Name.to!string.find(searchTerm).length > 0)
			{
				writeln("ID: ", task.id, ", Name: ", task.Name, ", Lastname: ", task.Lastname, ", Task: ", task.NameTask, ", IsComplete: ", task.IsComplete);
				found = true;
			}
		}
		if (!found)
		{
			writeln("No tasks found matching the search term.");
		}
		writeln("---------------------------------------");
	}
}

void help()
{
	writeln("--- Commands ---");
	writeln("help                         : Show this help message.");
	writeln("show                         : Display all tasks.");
	writeln("add <name> <lastname> <task> : Add a new task.");
	writeln("edit <id> <name> <lastname> <task> <isComplete> : Edit an existing task.");
	writeln("delete <id>                  : Delete a task by its ID.");
	writeln("search <term>                : Search for a task.");
	writeln("exit                         : Exit the program.");
	writeln("----------------");
}

void main()
{
	writeln("JSON DAP TodoList Manager");
	auto manager = new ToDoListManagaer();

	help();

	while(true)
	{
		write("Enter command > ");
		string inputLine = readln();
		auto parts = inputLine.strip.split;
		if (parts.length == 0)
		{
			continue;
		}

		string command = parts[0].toLower();

		switch (command)
		{
			case "add":
				if (parts.length >= 4)
				{
					manager.Add(parts[1], parts[2], parts[3..$].join(" "));
				}
				else
				{
					writeln("Invalid add command. Usage: add <name> <lastname> <task>");
				}
				break;
			case "delete":
				if (parts.length == 2)
				{
					try
					{
						int id = parts[1].to!int;
						manager.Delete(id);
					}
					catch (Exception e)
					{
						writeln("Invalid ID. Please enter a number.");
					}
				}
				else
				{
					writeln("Invalid delete command. Usage: delete <id>");
				}
				break;
			case "edit":
				if (parts.length >= 6)
				{
					try
					{
						int id = parts[1].to!int;
						bool isComplete = parts[5].toLower == "true";
						manager.Edit(id, parts[2], parts[3], parts[4], isComplete);
					}
					catch (Exception e)
					{
						writeln("Invalid edit command. Usage: edit <id> <name> <lastname> <task> <isComplete>");
					}
				}
				else
				{
					writeln("Invalid edit command. Usage: edit <id> <name> <lastname> <task> <isComplete>");
				}
				break;
			case "show":
				manager.ShowAll();
				break;
			case "search":
				if (parts.length >= 2)
				{
					manager.Search(parts[1..$].join(" "));
				}
				else
				{
					writeln("Invalid search command. Usage: search <term>");
				}
				break;
			case "help":
				help();
				break;
			case "exit":
				return;
			default:
				writeln("Unknown command. Type 'help' for a list of commands.");
				break;
		}
	}
}

