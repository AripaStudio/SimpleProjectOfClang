using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ToDoListJsonCS
{
    public class CL_CRUDmanager
    {
        public CL_TodolistManager manager = CL_TodolistManager.Instance;

        public int GetNewID()
        {
            if (!manager._todolist.Any())
            {
                return 1;
            }

            int maxID = manager._todolist.Max(item => item.ID);
            return maxID + 1;
        }

        public void Add_LIST(ToDoList list)
        {
            try
            {
                manager._todolist.Add(list);
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
            }
        }

        public bool Add(string TaskName, string Titel, string Description, string dueDate, string IsComplete)
        {
            if (string.IsNullOrWhiteSpace(TaskName))
            {
                Console.WriteLine("Task Name Is empty. Please Try Again!");
                return false;
            }

            int ID = GetNewID();

            if (manager._todolist.Any(t => t.Name.Equals(TaskName, StringComparison.OrdinalIgnoreCase)))
            {
                Console.WriteLine("A task with this name already exists. Please try again with a new name.");
                return false;
            }



            ToDoList list = new ToDoList();
            list.ID = ID;
            list.Name = TaskName;
            list.Title = Titel;
            list.Description = Description;
            list.Status = dueDate;
            list.IsComplete = IsComplete;

            Add_LIST(list);
            Console.WriteLine("Task added successfully.");
            return true;
        }

        public void delete(int id)
        {
            try
            {
                manager._todolist.RemoveAll(i => i.ID == id);
                Console.WriteLine("Task Deleted successfully.");
            }
            catch (Exception e)
            {
                Console.WriteLine("error in Remove List || error : " + Environment.NewLine + e);
            }
        }

        public void deleteAll()
        {
            try
            {
                manager._todolist.Clear();
                Console.WriteLine("Successfully completed.");

            }
            catch (Exception e)
            {
                Console.WriteLine("Error in Delete All Task : " + e);
            }
        }

        public void SearchAndShow(int id)
        {

            if (id <= 0)
            {
                Console.WriteLine("Please Enter a ID Valid (1-2-3-4-5...)");
                return;
            }
            ToDoList list = new ToDoList();
            list = manager._todolist.FirstOrDefault(i => i.ID == id);
            if (list == null)
            {
                Console.WriteLine("This List Is empty Please Try Again");
                Console.WriteLine("Or Input in is Not Valid");
                return;
            }

            Console.WriteLine($"ID: {list.ID}");
            Console.WriteLine($"Name: {list.Name}");
            Console.WriteLine($"Title: {list.Title}");
            Console.WriteLine($"Description: {list.Description}");
            Console.WriteLine($"Due Date: {list.Status}");
            Console.WriteLine($"Is Complete: {(list.IsComplete)}");
            Console.WriteLine("-----------------------------------");
        }

        public void showall()
        {
            if (!manager._todolist.Any())
            {
                Console.WriteLine("No tasks to display.");
                return;
            }
            try
            {
                foreach (var list in manager._todolist)
                {
                    Console.WriteLine($"ID: {list.ID}");
                    Console.WriteLine($"Name: {list.Name}");
                    Console.WriteLine($"Title: {list.Title}");
                    Console.WriteLine($"Description: {list.Description}");
                    Console.WriteLine($"Due Date: {list.Status}");
                    Console.WriteLine($"Is Complete: {(list.IsComplete)}");
                    Console.WriteLine("-----------------------------------");
                }
            }
            catch (Exception e)
            {
                Console.WriteLine("Error in Show all Data in List : " + Environment.NewLine + e);
                return;
            }
        }

    }
}
