using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinaryTree
{
    public class BinarySearchTree : BinaryTree
    {

        public bool Search(int item)
        {
            return SearchRec(item, root);
        }
        public bool SearchRec(int item, TNode p)
        {
            if (p == null)
            {
                return false;
            }
            if (p.data == item)
            {
                return true;
            }
            else if (p.data > item)
            {
                return SearchRec(item, p.left);
            }
            else
            {
                return SearchRec(item, p.right);
            }
        }
        public void AddNode(int item)
        {

            root = AddNodeRec(item, root);
        }
        public TNode AddNodeRec(int item, TNode p)
        {
            if (p == null)
            {
                p = new TNode(item);
                p.left = p.right = null;
            }
            else if (item < p.data)
            {
                p.left = AddNodeRec(item, p.left);
            }
            else
            {
                p.right = AddNodeRec(item, p.right);
            }
            return p;
        }
        public void DeleteNode(int item)
        {
            if (Search(item))
            {
                root = DeleteNodeRec(item, root);
            }
            else
            {
                Console.WriteLine("Item not found:item not deleted \n");
            }
        }
        public TNode DeleteNodeRec(int item, TNode p)
        {
            if (item < p.data)
            {
                p.left = DeleteNodeRec(item, p.left);
            }
            else if (item > p.data)
            {
                p.right = DeleteNodeRec(item, p.right);
            }
            else
            {
                p = DeleteNodeFound(p);
            }
            return p;
        }
        public TNode DeleteNodeFound(TNode p)
        {
            if (p.left == null)
            {
                TNode temp = p.right;
                p = null;
                return temp;
            }
            else if (p.right == null)
            {
                TNode temp = p.left;
                p = null;
                return temp;
            }
            else
            {
                TNode p1 = p.right;
                while (p1.left != null)
                {
                    p1 = p1.left;

                }
                p.data = p1.data;
                p.right = DeleteNodeRec(p.data, p.right);
            }
            return p;
        }
    }
}
