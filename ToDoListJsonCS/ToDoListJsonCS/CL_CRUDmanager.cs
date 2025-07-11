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
            int len = manager._todolist.Count + 1;


            return 1;
        }

        public void add ()
        {

        }

        public void delete(int id)
        {

        }

        public void deleteAll()
        {

        }

        public void search(int id)
        {

        }

        public void showall()
        {

        }

    }
}
