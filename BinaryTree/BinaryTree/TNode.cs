using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinaryTree
{
    public class TNode
    {
        public int data { get; set; }
        public TNode left { get; set; }
        public TNode right { get; set; }
        public TNode(int item)
        {
            data = item;
        }
        public TNode()
        {
            data = 0;
            left = right = null;
        }
    }
}
