using System;
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

        public bool MainMenu(string fileName)
        {
            return false;
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

        
    }
}
