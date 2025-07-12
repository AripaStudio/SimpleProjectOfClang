// See https://aka.ms/new-console-template for more information

// C# and D for Example 

using ToDoListJsonCS;

CL_TodolistManager todolist = CL_TodolistManager.Instance;
Console.WriteLine("welcome to Todolist");
CL_CRUDmanager crudm = new CL_CRUDmanager();
todolist.HelpMenu();
while (true)
{   
    var check = todolist.MainMenu(crudm);
    if (!check)
    {
        break;
    }
}


