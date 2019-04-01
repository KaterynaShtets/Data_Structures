using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinaryTree
{
    public class BinaryTree
    {
        public TNode root { get; set; }
        public BinaryTree()
        {
            root = null;
        }
        public bool IsEmpty()
        {
            return root == null;
        }
        public bool IsFull()
        {
            return false;
        }
        public int Size()
        {
            return SizeRec(root);
        }
        public void Preorder()
        {
            Console.WriteLine("Preorder sequence of nodes \n");
            if (root == null)
            {
                Console.WriteLine("tree is empty");
            }
            else
            {
                PreorderRec(root);

            }
        }
        public void PreorderRec(TNode p)
        {
            if (p != null)
            {
                Console.WriteLine(p.data);
                PreorderRec(p.left);
                PreorderRec(p.right);
            }
        }
        public void Inorder()
        {
            Console.WriteLine("Inorder sequence of nodes \n");
            if (root == null)
            {
                Console.WriteLine("tree is Empty");
            }
            else
            {
                InorderRec(root);
            }
        }
        public void InorderRec(TNode p)
        {
            if (p != null)
            {
                InorderRec(p.left);
                Console.WriteLine(p.data);
                InorderRec(p.right);
            }
        }
        public void Postorder()
        {
            Console.WriteLine("Postorder sequenceof nodes: \n");
            if (root == null)
            {
                Console.WriteLine("tree is empty");
            }
            else
            {
                PostOrderRec(root);
            }
        }
        public void PostOrderRec(TNode p)
        {
            if (p != null)
            {
                PostOrderRec(p.left);
                PostOrderRec(p.right);
                Console.WriteLine(p.data);
            }
        }
        public void MakeEmpty()
        {
            TNode p = root;
            MakeEmptyRec(p);
            root = null;
        }
        public void MakeEmptyRec(TNode p)
        {
            if (p != null)
            {
                MakeEmptyRec(p.left);
                MakeEmptyRec(p.right);
                p = null;
            }
        }
        public int SizeRec(TNode p)
        {
            if (p == null)
            {
                return 0;
            }
            else
            {
                return SizeRec(p.left) + SizeRec(p.right) + 1;
            }
        }
    }
}
