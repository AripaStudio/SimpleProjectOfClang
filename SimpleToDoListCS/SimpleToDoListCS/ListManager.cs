using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Channels;
using System.Threading.Tasks;
using Microsoft.VisualBasic;

namespace SimpleToDoListCS
{
    public class ListManager
    {
        public static readonly Lazy<ListManager> lazyInstance = new Lazy<ListManager>(() => new ListManager());


        public ListManager()
        {
            TodoList_list = new List<CL_List>();
        }

        

        public int GetSumNewID()
        {
            if (!TodoList_list.Any())
            {
                return 1;
            }
            int maxId = TodoList_list.Max(item => item.ID);
            return maxId + 1;
        }

        public void Add_LIST(CL_List list)
        {
            try
            {
                TodoList_list.Add(list);
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
            }
        }

        public bool Add(string TaskName, string Titel, string Description, string dueDate, bool IsComplete)
        {
            if (string.IsNullOrWhiteSpace(TaskName))
            {
                Console.WriteLine("Task Name Is empty. Please Try Again!");
                return false;
            }

            int ID = GetSumNewID();

            if (TodoList_list.Any(t => t.TaskName.Equals(TaskName, StringComparison.OrdinalIgnoreCase))) 
            {
                Console.WriteLine("A task with this name already exists. Please try again with a new name.");
                return false;
            }



            CL_List list = new CL_List();
            list.ID = ID;
            list.TaskName = TaskName;
            list.Title = Titel;
            list.Description = Description;
            list.dueDate = dueDate;
            list.IsComplete = IsComplete;

            Add_LIST(list);
            Console.WriteLine("Task added successfully.");
            return true;
        }

        public bool Remove(int id)
        {

            try
            {
                TodoList_list.Clear();
                Console.WriteLine("Successfully completed.");
                return true;
            }
            catch (Exception e)
            {
                Console.WriteLine("error in Remove List || error : " + Environment.NewLine + e);
                return false;
            }

        }


        public bool removeAll()
        {
            try
            {
                TodoList_list.RemoveAll(task => task.ID >= 0);
                return true;
            }
            catch (Exception e)
            {
                Console.WriteLine("error in removeall Task : ", Environment.NewLine + e);
                return false;
            }
        }
        public bool Edit(int id)
        {
            if (id <= 0)
            {

                Console.WriteLine("Please Enter a ID Valid (1-2-3-4-5...)");
                return false;
            }

            var editList = TodoList_list.FirstOrDefault(c => c.ID == id);
            if (editList == null)
            {
                Console.WriteLine("this ID is Not Valid");
                Console.WriteLine("Please Try Again");
                return false;
            }


            Console.WriteLine($"Edit Task Name: (Press Enter to keep current: {editList.TaskName})");
            string inputTaskName = Console.ReadLine();
            if (!string.IsNullOrWhiteSpace(inputTaskName))
            {
                editList.TaskName = inputTaskName;
            }
            Console.WriteLine($"Edit Title: (Press Enter to keep current: {editList.Title})");
            string inputTitle = Console.ReadLine();
            if (!string.IsNullOrWhiteSpace(inputTitle))
            {
                editList.Title = inputTitle;
            }
            Console.WriteLine($"Edit Description: (Press Enter to keep current: {editList.Description})");
            string inputDescription = Console.ReadLine();
            if (!string.IsNullOrWhiteSpace(inputDescription))
            {
                editList.Description = inputDescription;
            }

            Console.WriteLine($"Edit DueData: (Press Enter to keep current: {editList.dueDate})");
            string inputDueData = Console.ReadLine();
            if (!string.IsNullOrWhiteSpace(inputDueData))
            {
                editList.dueDate = inputDueData;
            }


            Console.WriteLine($"Edit IsComplete (please Enter (yes/no): (Press Enter to keep current: {editList.IsComplete})");
            string inputIsComplete = Console.ReadLine().ToLower();
            if (!string.IsNullOrWhiteSpace(inputTitle))
            {
                if (inputIsComplete == "yes")
                {
                    editList.IsComplete = true;
                }
                else if (inputIsComplete == "no") 
                {
                    editList.IsComplete = false;
                }
                else
                {
                    Console.WriteLine("Invalid input for 'Is Complete'. Keeping the current status.");
                }

            }





            Console.WriteLine("-----------------------------------");
            Console.WriteLine("Task updated successfully!");
            return true;
        }

        public bool showall()
        {
            if (!TodoList_list.Any())
            {
                Console.WriteLine("No tasks to display.");
                return false;
            }
            try
            {
                foreach (var list in TodoList_list)
                {
                    Console.WriteLine($"ID: {list.ID}");
                    Console.WriteLine($"Name: {list.TaskName}"); 
                    Console.WriteLine($"Title: {list.Title}"); 
                    Console.WriteLine($"Description: {list.Description}");
                    Console.WriteLine($"Due Date: {list.dueDate}"); 
                    Console.WriteLine($"Is Complete: {(list.IsComplete ? "yes" : "no")}"); 
                    Console.WriteLine("-----------------------------------");
                }
                return true; 
            }
            catch (Exception e)
            {
                Console.WriteLine("Error in Show all Data in List : " + Environment.NewLine + e);
                return false;
            }
        }

        public CL_List SearchReturnList(int id)
        {
            if (id <= 0)
            {
                Console.WriteLine("Please Enter a ID Valid (1-2-3-4-5...)");
                return null;
            }
            CL_List list = new CL_List();
            list = TodoList_list.FirstOrDefault(i => i.ID == id);
            if (list == null)
            {
                Console.WriteLine("Task not found or list is empty. Please Try Again or check input.");
                return null;
            }

            return list;
        }

        public bool SearchAndShow(int id)
        {

            if (id <= 0)
            {
                Console.WriteLine("Please Enter a ID Valid (1-2-3-4-5...)");
                return false;
            }
            CL_List list = new CL_List();
            list = TodoList_list.FirstOrDefault(i => i.ID == id);
            if (list == null)
            {
                Console.WriteLine("This List Is empty Please Try Again");
                Console.WriteLine("Or Input in is Not Valid");
                return false;
            }

            Console.WriteLine($"ID: {list.ID}");
            Console.WriteLine($"Name: {list.TaskName}");
            Console.WriteLine($"Title: {list.Title}");
            Console.WriteLine($"Description: {list.Description}");
            Console.WriteLine($"Due Date: {list.dueDate}");
            Console.WriteLine($"Is Complete: {(list.IsComplete ? "yes" : "no")}");
            Console.WriteLine("-----------------------------------");


            return true;
        }


        public static ListManager Instance
        {
            get { return lazyInstance.Value; }
        }

        public List<CL_List> TodoList_list { get; private set; }

    }

    public class CL_List
    {
        public int ID { get; set; }
        public string TaskName { get; set; }


        public string Title { get; set; }

        public string Description { get; set; }

        public string dueDate { get; set; }

        public bool IsComplete { get; set; }

    }


}
