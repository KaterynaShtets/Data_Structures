using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinaryTree
{
   

    class Program
    {

        static void Main(string[] args)
        {
            BinarySearchTree bst = new BinarySearchTree();
            bst.AddNode(15);
            bst.AddNode(10);
            bst.AddNode(7);
            bst.AddNode(50);
            bst.AddNode(12);
            bst.AddNode(11);
            bst.AddNode(45);
            bst.AddNode(13);
            bst.AddNode(55);
            bst.AddNode(14);
            if (bst.Search(12))
            {
                Console.WriteLine("Found");
            }
            else
            {
                Console.WriteLine("Not found");
            }
            if (bst.Search(60))
            {
                Console.WriteLine("Found");
            }
            else
            {
                Console.WriteLine("Not found");
            }
            bst.Inorder();
            bst.Preorder();
            bst.Postorder();
            int size = bst.Size();
            Console.WriteLine($"The number of  nodes in the tree :{size}");
            if (bst.Search(10))
            {
                bst.DeleteNode(10);
            }
            else
            {
                Console.WriteLine("Item is not in the tree");
            }
            bst.Preorder();
            size = bst.Size();
            Console.WriteLine($"The number of  nodes in the tree :{size}");
            bst.MakeEmpty();
            bst.Preorder();
            size = bst.Size();
            Console.WriteLine($"The number of  nodes in the tree :{size}");
            Console.Read();
        }

    }
}
