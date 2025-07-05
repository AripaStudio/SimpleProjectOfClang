module TodoListManager;
	
import std.stdio;
import ListManager;
import std.string;

class CLTodoListManager
{
	void MainMenu()
	{
		writeln("welcome to TodoList AP with D ");
		HelpDisplay();

		auto listManager = new CL_ListManager();

		while(true)
		{
			write("\nEnter your choice: ");
			string choice = readln.chomp.toLower();

			switch(choice)
			{
				case "1":
				case "add":
					write("Enter Task Name: ");
					string taskName = readln.chomp;
					write("Enter Title: ");
					string title = readln.chomp;
					write("Enter Description: ");
					string description = readln.chomp;
					write("Enter Due Date (e.g., 2025-12-31): ");
					string dueDate = readln.chomp;
					write("Is Complete? (yes/no): ");
					bool isComplete = readln.chomp.toLower() == "yes";

					listManager.Add(taskName, title, description, dueDate, isComplete);
					break;

				case "2":
				case "remove":
					write("Enter Task Name of task to remove: ");
					string removeTaskName = readln.chomp;
					listManager.Remove(removeTaskName);
					break;

				case "3":
				case "edit":
					write("Enter Task Name of task to edit: ");
					string editTaskName = readln.chomp;
					listManager.Edit(editTaskName);
					break;

				case "4":
				case "showall":
					listManager.showall();
					break;

				case "5":
				case "search":
					write("Enter Task Name of task to search: ");
					string searchTaskName = readln.chomp;
					listManager.SearchAndShow(searchTaskName);
					break;

				case "6":
				case "clear":
					write("Are you sure you want to clear all tasks? (yes/no): ");
					if (readln.chomp.toLower() == "yes")
					{
						listManager.removeAll();
					}
					else
					{
						writeln("Operation cancelled.");
					}
					break;

				case "7":
				case "exit":
					writeln("Exiting To-Do List Application. Goodbye!");
					return;

				case "help":
					HelpDisplay();
					break;

				default:
					writeln("Invalid choice. Please try again or type 'help' for options.");
					break;
			}
		}
	}

	void HelpDisplay()
	{
		writeln("\n--- To-Do List Menu ---");
		writeln("------");
		write("1. Add New Task ");				
		writeln("Or : add");
		writeln("------");
		write("2. Remove Task by ID ");		
		writeln("Or : remove");
		writeln("------");		
		write("3. Edit Task by ID ");		
		writeln("Or : edit");
		writeln("------");
		write("4. Show All Tasks ");		
		writeln("Or : showall");		
		write("5. Search Task by ID and Show ");		
		writeln("Or : search");	
		writeln("------");
		write("6. Clear All Tasks ");		
		writeln("Or : clear");
		writeln("------");
		write("7. Exit ");		
		writeln("Or : exit");
		
	}
}