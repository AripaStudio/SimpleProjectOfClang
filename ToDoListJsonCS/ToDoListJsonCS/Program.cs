// See https://aka.ms/new-console-template for more information

// C# and D for Example 

using ToDoListJsonCS;

CL_TodolistManager todolist = CL_TodolistManager.Instance;

Console.WriteLine("welcome to Todolist");
HelpMenu();
while (true)
{   
    var check = todolist.MainMenu();
    if (!check)
    {
        break;
    }
}


void HelpMenu()
{
    Console.WriteLine("\n--- To-Do List Menu ---");
    Console.Write("1. Add New Task ");
    Console.ForegroundColor = ConsoleColor.Yellow;
    Console.WriteLine("Or : add");
    Console.ResetColor();

    Console.Write("2. Remove Task by ID ");
    Console.ForegroundColor = ConsoleColor.Yellow;
    Console.WriteLine("Or : remove");
    Console.ResetColor();

    Console.Write("3. Edit Task by ID ");
    Console.ForegroundColor = ConsoleColor.Yellow;
    Console.WriteLine("Or : edit");
    Console.ResetColor();

    Console.Write("4. Show All Tasks ");
    Console.ForegroundColor = ConsoleColor.Yellow;
    Console.WriteLine("Or : showall");
    Console.ResetColor();

    Console.Write("5. Search Task by ID and Show ");
    Console.ForegroundColor = ConsoleColor.Yellow;
    Console.WriteLine("Or : search");
    Console.ResetColor();

    Console.Write("6. Clear All Tasks ");
    Console.ForegroundColor = ConsoleColor.Yellow;
    Console.WriteLine("Or : clear");
    Console.ResetColor();

    Console.Write("7. Exit ");
    Console.ForegroundColor = ConsoleColor.Yellow;
    Console.WriteLine("Or : exit");
    Console.ResetColor();
}
