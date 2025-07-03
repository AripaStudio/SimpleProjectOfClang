module SimpleTodoListDlang;

import std.stdio;
import TodoListManager;

int main()
{
    writeln("Welecome To TodoList simple Dlang");
    CLTodoListManager mainmenu = new CLTodoListManager();
    mainmenu.MainMenu();
    return 0;
}