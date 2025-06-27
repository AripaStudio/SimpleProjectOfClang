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
            int maxId = TodoList_list.Max(item => item.ID);
            if (maxId > 0 )
            {
                return maxId + 1;
            }
            else
            {
                return 1;
            }
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

        public bool Add(string TaskName  , string Titel , string Description , string dueDate , bool IsComplete)
        {
            int ID = GetSumNewID(); 
            if (ID <= 0)
            {
                Console.WriteLine("GetSumNewID is 0");                
            }

            bool checkID = TodoList_list.Any(I => I.TaskName == TaskName && I.ID == ID);
            if (!checkID)
            {
                Console.WriteLine("The task name and ID are duplicated. (please try again with new NameTask)");
                return false;
            }
            if (TaskName == null)
            {
                Console.WriteLine("Name Task Is empty Please Try Again!");
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
            return true;
        }

        public bool Remove(int id)
        {
            if (id <= 0)
            {
                Console.WriteLine("Please Enter a ID Valid (1-2-3-4-5...)");
                return false;
            }

            var RemoveList = TodoList_list.FirstOrDefault(i => i.ID == id);
            try
            {
                TodoList_list.Remove(RemoveList);
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
                Console.WriteLine("error in removeall Task : " , Environment.NewLine + e);
                return false;
            }
        }
        public bool Edit(int id)
        {
            if (id <=  0)
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

            while (true)
            {
                Console.WriteLine($"Edit TaskName : (Enter For No Edit : {editList.TaskName} ");
                //استفاده کردن از 
                // checkIsNullOrWhiteSpaceArrayForCl_List
                // و کامل کردن پروژه و اینکه همین هم برای 
                // D بنویسم 
            }
            return true;
        }

        public int[] checkIsNullOrWhiteSpaceArrayForCl_List(string[] input)
        {
            if (input == null)
            {
                return new int[]{};
            }

            int[] output = [0,0,0,0,0];
            int number = -1;

            foreach (var txt in input)
            {
                number++;
                if (!string.IsNullOrWhiteSpace(txt))
                {
                    
                        output[number] += 1;
                    
                }
            }

            return output;
            
        }

        public bool showall()
        {
            try
            {
                foreach (var list in TodoList_list)
                {
                    Console.WriteLine("ID : ", list.ID);
                    Console.WriteLine("Name : ", list.TaskName);
                    Console.WriteLine("Title : ", list.Title);
                    Console.WriteLine("Description : ", list.Description);
                    Console.WriteLine("dueData : ", list.dueDate);
                    if (list.IsComplete == true)
                    {
                        Console.WriteLine("IsComplete(true) = yes");
                    }
                    else
                    {
                        Console.WriteLine("IsComplete(false) = no");
                    }
                }
            }
            catch (Exception e)
            {
                Console.WriteLine("error in Show all Data in List : "+ Environment.NewLine + e);
                return false;
            }
            return true;
        }

        public CL_List SearchReturnList(int id)
        {
            if (id <= 0)
            {
                Console.WriteLine("Please Enter a ID Valid (1-2-3-4-5...)");
                return new CL_List();
            }
            CL_List list = new CL_List();
            list = TodoList_list.FirstOrDefault(i => i.ID == id);
            if (list == null)
            {
                Console.WriteLine("This List Is empty Please Try Again");
                Console.WriteLine("Or Input in is Not Valid");
                return new CL_List();
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

            Console.WriteLine("ID : " , list.ID);
            Console.WriteLine("Name : " , list.TaskName);
            Console.WriteLine("Title : ", list.Title);
            Console.WriteLine("Description : " , list.Description);
            Console.WriteLine("dueData : " , list.dueDate);
            if (list.IsComplete == true)
            {
                Console.WriteLine("IsComplete(true) = yes");
            }
            else
            {
                Console.WriteLine("IsComplete(false) = no");
            }


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
