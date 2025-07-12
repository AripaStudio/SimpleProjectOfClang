using System;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Text.Json;

namespace ToDoListJsonCS
{
    public class CL_TodolistManager
    {
        private static readonly CL_TodolistManager _instance = new CL_TodolistManager();
    
        public const string FileName = "Data.json";
        public List<ToDoList> _todolist;

        private CL_TodolistManager()
        {
            _todolist = new List<ToDoList>();
        }


        public static CL_TodolistManager Instance
        {
            get
            {
                return _instance;
            }
        }


        public async Task<bool> LoadFileOrCreateFile()
        {
            if (File.Exists(FileName))
            {
                try
                {
                    var readJson = await File.ReadAllTextAsync(FileName);
                    _todolist = JsonSerializer.Deserialize<List<ToDoList>>(readJson);
                    Console.WriteLine("Data read successfully.");
                    return true;
                }
                catch (Exception e)
                {
                    Console.WriteLine("Error in Get Data : " + e);
                    return false;
                }
            }
            else
            {
                Console.WriteLine("FileName not Exists Create New File");
                await Save();
                return true;
            }
        }

        public async Task Save()
        {
            try
            {
                JsonSerializerOptions options = new JsonSerializerOptions { WriteIndented = true };
                var json = JsonSerializer.Serialize(_todolist, options);
                var write =  File.WriteAllTextAsync(FileName , json);
                Console.WriteLine("Data Save successfully.");
            }
            catch (Exception e)
            {
                Console.WriteLine("Error in Save Data : " + e);
            }

            
        }

        public bool MainMenu(CL_CRUDmanager instance)
        {
            while (true)
            {
                Console.Write("you can type :");
                string inputUser = Console.ReadLine().ToLower().Trim();
                switch (inputUser)
                {
                    case "1":
                    case "add":
                        Console.Write("Please Enter Name Task : ");
                        string NameTask = Console.ReadLine();
                        Console.Write("Please Enter Title : ");
                        string TitleTask = Console.ReadLine();
                        Console.Write("Please Enter Description : ");
                        string DescriptionTask = Console.ReadLine();
                        Console.Write("Enter Status : ");
                        string StatusTask = Console.ReadLine();
                        Console.Write("Enter IsComplete? Yes No ...");
                        string IsComplete = Console.ReadLine(); 
                        instance.Add(NameTask , TitleTask , DescriptionTask , StatusTask , IsComplete);
                        break;
                    case "2":
                    case "remove":
                        Console.Write("please Enter ID for Remove : ");
                        string strID = Console.ReadLine();
                        int ID = 0;
                        bool checkParse = int.TryParse(strID, out ID);
                        if (!checkParse)
                        {
                            Console.WriteLine("input is Not Valid");
                            Console.WriteLine("Please Try Again ");
                            break;
                        }
                        instance.delete(ID);
                        break;
                    case "3":
                    case "showall":
                        instance.showall();
                        break;
                    case "4":
                    case "search":
                        Console.Write("please Enter ID for Search and Show : ");
                        string s_strID = Console.ReadLine();
                        int s_ID = 0;
                        bool s_checkParse = int.TryParse(s_strID, out s_ID);
                        if (!s_checkParse)
                        {
                            Console.WriteLine("input is Not Valid");
                            Console.WriteLine("Please Try Again ");
                            break;
                        }
                        instance.SearchAndShow(s_ID);
                        break;
                    case "5":
                    case "clear":
                        instance.deleteAll();
                        break;
                    case "6":
                    case "exit":
                        return false;
                        break;
                    case "7":
                    case "help":
                        HelpMenu();
                        break;
                    default:
                        Console.WriteLine("input Not Valid for Help : 7");
                        break;
                }
            }
        }

        public void HelpMenu()
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

            Console.Write("3. Show All Tasks ");
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine("Or : showall");
            Console.ResetColor();

            Console.Write("4. Search Task by ID and Show ");
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine("Or : search");
            Console.ResetColor();

            Console.Write("5. Clear All Tasks ");
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine("Or : clear");
            Console.ResetColor();

            Console.Write("6. Exit ");
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine("Or : exit");
            Console.ResetColor();
        }

    }

    public class ToDoList
    {
        private int _ID;

        public int ID
        {
            get { return _ID; } 
            set
            {
                if (value <= 0 )
                {
                    throw new ArgumentException("ID is null or Is zero");
                }
                _ID = value;
            }}

        public string Name { get; set; }

        public string Title { get; set; }

        public string Description { get; set; }

        public string Status { get; set; }

        public string IsComplete { get; set; }

        
    }
}
