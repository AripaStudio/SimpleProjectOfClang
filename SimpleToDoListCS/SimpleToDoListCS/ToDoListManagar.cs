using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SimpleToDoListCS
{
    public class ToDoListManagar
    {
        public void MainMenu()
        {
            ListManager listManager = ListManager.Instance;

            while (true)
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


                Console.Write("Enter your choice: ");
                string choice = Console.ReadLine().ToLower();

                switch (choice)
                {
                    case "1":
                    case "add":
                        Console.Write("Enter Task Name: ");
                        string taskName = Console.ReadLine();
                        Console.Write("Enter Title: ");
                        string title = Console.ReadLine();
                        Console.Write("Enter Description: ");
                        string description = Console.ReadLine();
                        Console.Write("Enter Due Date (e.g., 2025-12-31): ");
                        string dueDate = Console.ReadLine();
                        Console.Write("Is Complete? (yes/no): ");
                        bool isComplete = Console.ReadLine().ToLower() == "yes";

                        if (listManager.Add(taskName, title, description, dueDate, isComplete))
                        {
                            Console.WriteLine("Task added successfully!");
                        }
                        break;

                    case "2":
                    case "remove":
                        Console.Write("Enter ID of task to remove: ");
                        if (int.TryParse(Console.ReadLine(), out int removeId))
                        {
                            listManager.Remove(removeId);
                        }
                        else
                        {
                            Console.WriteLine("Invalid ID. Please enter a number.");
                        }
                        break;

                    case "3":
                    case "edit":
                        Console.Write("Enter ID of task to edit: ");
                        if (int.TryParse(Console.ReadLine(), out int editId))
                        {
                            listManager.Edit(editId);
                        }
                        else
                        {
                            Console.WriteLine("Invalid ID. Please enter a number.");
                        }
                        break;

                    case "4":
                    case "showall":
                        listManager.showall();
                        break;

                    case "5":
                    case "search":
                        Console.Write("Enter ID of task to search: ");
                        if (int.TryParse(Console.ReadLine(), out int searchId))
                        {
                            listManager.SearchAndShow(searchId);
                        }
                        else
                        {
                            Console.WriteLine("Invalid ID. Please enter a number.");
                        }
                        break;

                    case "6":
                    case "clear":
                        Console.Write("Are you sure you want to clear all tasks? (yes/no): ");
                        if (Console.ReadLine().ToLower() == "yes")
                        {
                            if (listManager.removeAll())
                            {
                                Console.WriteLine("All tasks cleared successfully!");
                            }
                        }
                        else
                        {
                            Console.WriteLine("Operation cancelled.");
                        }
                        break;

                    case "7":
                    case "exit":
                        Console.WriteLine("Exiting To-Do List Application. Goodbye!");
                        return;

                    default:
                        Console.WriteLine("Invalid choice. Please try again.");
                        break;
                }
            }
        }
    }
}
