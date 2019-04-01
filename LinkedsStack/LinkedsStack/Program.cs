using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LinkedsStack
{
   public  class Node
    {
       public int data { get; set; }
        public Node next { get; set; }
        public Node()
        {
            next = null;
        }
        public Node(int item,Node link=null)
        {
            data = item;
            next = link;
        }
    }
    class LinkedStack
    {
        public int count { get; set; } 
        public Node top { get; set; }
        public LinkedStack()
        {
            count = 0;
            top = null;
        }
        public bool isEmpty()
        {
            return count == 0;
        }
        public int Size()
        {
            return count;
        }
        public void MakeEmpty()
        {
            count = 0;
            Node temp;
            while (top != null)
            {
                temp = top;
                top = top.next;
                temp = null;
            }
        }
        public void Push(int item)
        {
            Node p = new Node();
            p.data = item;
            p.next = top;
            top = p;
            count++;
        }
        public int Pop()
        {
            if (isEmpty())
            {
                Console.WriteLine("Stack is empty");
                return -1000;
            }
            Node temp = top;
            int res = top.data;
            top = top.next;
            temp = null;
            count--;
            return res;
            
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            LinkedStack ls = new LinkedStack();
            Console.WriteLine(ls.isEmpty());
            Console.WriteLine(ls.Size());
            ls.Push(3);
            ls.Push(4);
            ls.Push(1);
            Console.WriteLine(ls.isEmpty());
            Console.WriteLine(ls.Size());
            LinkedStack ls2 = new LinkedStack();
            while (!ls.isEmpty())
            {
                int c = ls.Pop();
                Console.WriteLine(c);
                ls2.Push(c);
            }
            Console.WriteLine(ls.isEmpty());
            Console.WriteLine(ls.Size());
            Console.WriteLine(ls2.isEmpty());
            Console.WriteLine(ls2.Size());
            while (!ls2.isEmpty())
            {
                int c2 = ls2.Pop();
                Console.WriteLine(c2);
                ls.Push(c2);
            }
            Console.Read();
        }
    }
}
