using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Stack_Array
{
    class StackArray
    {
       public  int max { get; set; }
       public  int top { get; set; }
       public  int[] array { get; set; }
       public StackArray(int n)
        {
            max = n;
            top = -1;
            array = new int[max];
        }
        public void MakeEmpty()
        {
            top = -1;
        }
        public bool IsEmpty()
        {
            return top == -1;
        }
        public bool isFull()
        {
            return top == max - 1;
        }
        public int Length()
        {
            return top + 1;
        }
        public void Push(int item)
        {
            if (isFull())
            {
                Console.WriteLine("Memory overflow");
            }
            else
            {
                array[++top] = item;
            }
        }
        public int Pop()
        {
            if (!IsEmpty())
            {
                return array[top--];
            }
            else
            {
                Console.WriteLine("Stack is Empty");
            }
            return -1000000;
        }
    }


    class Program
    {
        static void Main(string[] args)
        {
            StackArray sa = new StackArray(5);
            sa.Push(15);
            sa.Push(20);
            sa.Push(10);
            sa.Push(30);
            Console.WriteLine(sa.IsEmpty());
            Console.WriteLine(sa.isFull());
            Console.WriteLine(sa.Pop());
            sa.Push(30);
            sa.Push(50);
            Console.WriteLine(sa.isFull());

            while (!sa.IsEmpty())
            {
               int  x = sa.Pop();
               
            }
            Console.Read();
        }
    }
}
