[TOC]



## 算法笔记

### 1. 二叉树深度

```java
public class Solution {
    public int TreeDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return Math.max(TreeDepth(root.left) + 1, TreeDepth(root.right) + 1);
        
    }
}
```

### 2.不用加减乘除做加法

加法 = 两个数异或+(num1 & num2) << 1（进位）

知道进位为0，则输出异或值

```java
public class Solution {
    public int Add(int num1,int num2) {
       if (num2 == 0) {
           return num1;
       } 
        return Add(num1 ^ num2, (num1 & num2) << 1);
    }
}
```

### 3. 镜像二叉树

> ```
> 二叉树的镜像定义：源二叉树 
>     	    8
>     	   /  \
>     	  6   10
>     	 / \  / \
>     	5  7 9 11
>     	镜像二叉树
>     	    8
>     	   /  \
>     	  10   6
>     	 / \  / \
>     	11 9 7  5
> ```

```java
public class Solution {
    public void Mirror(TreeNode root) {
        if (root == null) {
            return;
        }
        //全部都反转
        TreeNode tmp = root.left;
        root.left = root.right;
        root.right = tmp;

        if (root != null) {
            Mirror(root.left);
            Mirror(root.right);
        }
    }
}
```

### 4. 变态跳台阶

一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

```java
public class Solution {
    public int JumpFloorII(int target) {
        return (int) Math.pow(2, target-1);
    }
}
```

### 5.求1+2+3+...+n

```java
public class Solution {
    public int Sum_Solution(int n) {
        return (1 + n) * n / 2;
    }
}
```

### 6.构建乘积数组

给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。（注意：规定B[0] = A[1] * A[2] * ... * A[n-1]，B[n-1] = A[0] * A[1] * ... * A[n-2];）

时间复杂度为O（n）,先

B[i] =  A[1] * A[2] *[i-1] 再

B[i] =  B[i] * A[n-1]*...A[i+1]

```java
import java.util.ArrayList;
public class Solution {
    public int[] multiply(int[] A) {
        int[] B = new int[A.length];
        int tmp = 1;
        for (int i = 0; i < A.length; i++) {
            B[i] = tmp;
            tmp *= A[i];
        }
        tmp = 1;
        for (int i = A.length-1; i >= 0; i--) {
            B[i] *= tmp;
            tmp *= A[i];
        }
        return B;
    }
}

//B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]
//从左到右算 B[i]=A[0]*A[1]*...*A[i-1]
//从右到左算B[i]*=A[i+1]*...*A[n-1]
```

### 7.连续子数组的最大和
{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)

```java
public class Solution {
    public int FindGreatestSumOfSubArray(int[] array) {
        int sum = 0;
        int max = -32767;
        for (int i = 0; i < array.length; i++) {
            sum += array[i];
            if (sum > max) {
                max = sum;
            }
            //前面和小于0对当前没有贡献，则清0
            if (sum < 0)  {
                sum = 0;
            }
        }
        return max;
    }
}
```

### 8.用两个栈实现队列

```java
import java.util.Stack;

public class Solution {
    Stack<Integer> stack1 = new Stack<Integer>();
    Stack<Integer> stack2 = new Stack<Integer>();
    
    public void push(int node) {
        stack1.push(node);
    }
    
    public int pop() {
    // 只有当stack2为空时才把stack1中转移到2中
        if (stack2.empty()) {
           int size = stack1.size();
           for (int i = 0; i < size; i++){
              int node = stack1.pop();
              stack2.push(node);
            } 
        }
        return stack2.pop();
    }
}
```

### 9.跳台阶

一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。

f(n) = f(n-1) + f(n-2)

```
public class Solution {
    public int JumpFloor(int target) {
        if (target == 1) {
            return 1;
        }
        if (target == 2) {
            return 2;
        }
        return JumpFloor(target-2) + JumpFloor(target-1);
    }
}
```

### 10.平衡二叉树

判断平衡二叉树

```java
public class Solution {
    private int flag = 1;
    
    public boolean IsBalanced_Solution(TreeNode root) {
        len(root);
        return flag == 0;
    }
    public int len(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int a = len(root.left);
        int b = len(root.right);
        if (Math.abs(a-b) > 1) {
            flag = 0;
        }
        return Math.max(a, b) + 1;
    }
    
}
```

### 11.二进制中1的个数

输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

```
public class Solution {
    public int NumberOf1(int n) {
        int num = 0;
        while (n != 0) {
            if ((n & 1) == 1) {
                num++;
            }
            n = n >>> 1;
        }
        return num;
    }
}
```

```
//每次  n &= (n - 1)，1个个数都会减一
public class Solution {
    public int NumberOf1(int n) {
        int num = 0;
        while (n != 0) {
            num++;
            n &= (n - 1);
        }
        return num;
    }
}
```

### 12. 两个链表的第一个公共结点

输入两个链表，找出它们的第一个公共结点。（注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）

解答：

- 可计算两链表长度差；
- 可以让每个节点走2个不同的圈，使节奏一致

```
/*
public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}*/
public class Solution {
    public ListNode FindFirstCommonNode(ListNode pHead1, ListNode pHead2) {
        ListNode p1 = pHead1;
        ListNode p2 = pHead2;
        while (p1 != p2) {
            p1 = (p1 == null) ? pHead2 : p1.next;
            p2 = (p2 == null) ? pHead1 : p2.next;
        }
        return p1;
        
    }
}
```

### 13.旋转数组的最小数字

把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。



参考 fucking leecode 二分搜索。

```
import java.util.ArrayList;
public class Solution {
    public int minNumberInRotateArray(int [] array) {
        if (array.length == 0) {
            return 0;
        }
        int l = 0;
        int h = array.length - 1;
        int idx = h;
        while (l <= h) {
            int m = (l + h) / 2;
            if (array[m] > array[idx]) {
                l = m + 1;
            }
            else if (array[m] < array[idx]) {
                if (array[m-1] > array[m]) {
                    return array[m];
                }
                h = m - 1;
            }
            else {
                return array[m];
            }
        }
        return 0;
    }
}
```

### 14.链表中环的入口结点

p为相遇节点，此时2*(a + b) = a + b + c + b

则a = c

![图片说明](https://uploadfiles.nowcoder.com/images/20200216/664093853_1581796891319_57DB204B64D4328DA9CB2FC8F955C379)

```java
/*
 public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}
*/
public class Solution {

    public ListNode EntryNodeOfLoop(ListNode pHead)
    {
        
        ListNode p1 = pHead;
        ListNode p2 = pHead;
        ListNode p3 = pHead;
        while (p1 != null && p2 != null) {
            p1 = p1.next;
            if (p2.next != null) {
                p2 = p2.next;
                p2 = p2.next;
            }
            
            //当相遇时，新建p3从头开始走c步
            if (p1 == p2) {
                while (p3 != null && p1 != null) {
                    if (p1 == p3) {
                        return p1;
                    }
                     p1 = p1.next;
                     p3 = p3.next;
                }
            }
        }
        return null;
    }
}
```

### 15.剪绳子

给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1），每段绳子的长度记为k[0],k[1],...,k[m]。请问k[0]xk[1]x...xk[m]可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。



解答

比较所有段数对应的长度，在每段中，满足乘积最大时，每段长度要么都相等，要么相差1

```java
public class Solution {
    public int cutRope(int target) {
        int res = 0;
        for (int i = 2; i <= (target / 2) + 1; i++) {
            int tmp = 0;
            if (target % i == 0) {
                max_v = target / i;
            } else {
                max_v = target / i + 1;
            }
            //得到每段长的最小那个值有几个，比如题目中有1个2
            int a = i * max_v - target;
            //算指数
            int max_mul = (int)Math.pow(max_v, i-a) * (int)Math.pow(max_v-1, a);
            
            if (res < tmp2) {
                res = tmp2;
            }
        }
        return res;
    }
}
```

### 16.数值的整数次方

给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

保证base和exponent不同时为0

```
public class Solution {
    public double Power(double base, int exponent) {
        double t = 1;
        int a = (exponent < 0) ? -exponent : exponent;
        for (int i = 0; i < a; i++) {
            t = t * base;
        }
        if (exponent < 0) {
            t = 1 / t;
        }
        return t;
  }
}
```



### 18.斐波那契数列

非递归实现

```java
public class Solution {
    public int Fibonacci(int n) {
        if (n == 0) {
            return n;
        } else if (n <= 2) {
            return 1;
        }
        int a = 1;
        int b = 1;
        for (int i = 3; i <= n; i++) {
            int temp = b;
            b = a + b;
            a = temp;
        }
        return b;
    }
}
```

### 19.二叉树按行打印

用队列保存

```java
import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;

/*
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
*/
public class Solution {
    ArrayList<ArrayList<Integer> > Print(TreeNode pRoot) {
        Queue<TreeNode> q = new LinkedList<TreeNode> ();
        q.offer(pRoot);
        ArrayList<ArrayList<Integer> > res = new ArrayList<ArrayList<Integer> >();
        int len = 1;
        while (q.peek() != null) {
            ArrayList<Integer> t = new ArrayList<Integer>();
            int tmpLen = 0;
            for (int i = 0; i < len; i++) {
                TreeNode node = q.poll();
                t.add(node.val);
                if (node.left != null) {
                    q.offer(node.left);
                    tmpLen++;
                }
                if (node.right != null) {
                    q.offer(node.right);
                    tmpLen++;
                }
            }
            len = tmpLen;
            res.add(t);
        }
        return res;
    }
    
}
```

### 20. 判断是否为对称的二叉树

得到二叉树每层数据，null值则用一个node替换；在一一对比每行



```java
import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;
/*
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
*/
public class Solution {
    boolean isSymmetrical(TreeNode pRoot)
    {
        Queue<TreeNode> q = new LinkedList<TreeNode> ();
        q.offer(pRoot);
        int len = 0;
        TreeNode nullNode = new TreeNode(32767);
        while (q.peek() != null) {
            ArrayList<Integer> t = new ArrayList<Integer>();
            len = q.size();
            for (int i = 0; i < len; i++) {
                TreeNode node = q.poll();
                t.add(node.val);
                if (node == nullNode) {
                    continue;
                }
                
                if (node.left != null) {
                    q.offer(node.left);
                } else {
                    q.offer(nullNode);
                }
                
                if (node.right != null) {
                    q.offer(node.right);
                } else {
                    q.offer(nullNode);
                }
            }
            //这里Integer比较要用equals方法
            for (int i = 0; i < t.size() / 2; i++) {
                if(!t.get(i).equals(t.get(t.size()-1-i))) {
                 return false;
                }
            }
        }
        return true;
    }
}
```

### 21.数字在排序数组中出现的次数

先用二分搜索找到最左侧的值，在从此处开始往后遍历



```
public class Solution {
    public int GetNumberOfK(int [] array , int k) {
        if (array.length == 0) {
            return 0;
        }
        int l = 0;
        int h = array.length - 1;
        int num = 0;
        int min = h;
        while(l <= h) {
            int m = l + (h - l) / 2;
            if (array[m] == k) {
                h = m - 1;
                if (m < min) {
                    min = m;
                }
            } else if (array[m] < k){
                l = m + 1;
            } else if (array[m] > k) {
                h = m - 1;
            }
        }
        
        for (int i = min; i <= array.length - 1; i++) {
            if (array[i] == k) {
                num++;
            }
            else {
                break;
            }
        }
        return num;
    }
}
```

### 22.反转链表

每次只改一个节点的方向，一个节点

```java
/*
public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}*/
public class Solution {
    public ListNode ReverseList(ListNode head) {
        if (head == null) {
            return null;
        }
        if (head.next == null) {
           return head;
       }
        
        ListNode p = null;
        ListNode q = null;
        while (head.next.next != null) {
           q = head;
            head = head.next;
           q.next = p;
           p = q;
           
       }
       q = head;
       head = head.next;
       q.next = p;
       head.next = q;
       return head;
    }
}
```

### 23.二叉树中序某个节点的下一个结点

给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。



解答

- 如果节点右节点不为空
  - 则先往右节点找一次，在一直左节点往下，知道为null返回
- 如果节点右节点为空
  - 如果节点为父节点的左节点，则直接返回父节点
  - 如果节点为父节点的右节点，则把此节点当作null情况下返回父节点的下一个，一次匹配
  - 如果最后走到了根节点，说明目标节点为中序遍历的最后一个

```java
/*
public class TreeLinkNode {
    int val;
    TreeLinkNode left = null;
    TreeLinkNode right = null;
    TreeLinkNode next = null;

    TreeLinkNode(int val) {
        this.val = val;
    }
}
*/
public class Solution {
    public TreeLinkNode GetNext(TreeLinkNode pNode)
    {
        //如果节点右节点不为空
        //则先往右节点找一次，在一直左节点往下，知道为null返回
        if (pNode.right != null) {
            pNode = pNode.right;
            while (pNode.left != null) {
                pNode = pNode.left;
            }
            return pNode;
        }
        
        //如果节点右节点为空
        //如果节点为父节点的左节点，则直接返回父节点
        //如果节点为父节点的右节点，则把此节点当作null情况下返回父节点的下一个，一次匹配 		//如果最后走到了根节点，说明目标节点为中序遍历的最后一个
        while (pNode.next != null) {
            if (pNode.next.left == pNode) {
                return pNode.next;
            }
            else if (pNode.next.right == pNode) {
                if (pNode.next.next == null) {
                    return null;
                }
                pNode = pNode.next;
            }
        }
        return pNode.right;
        
    }
}
```

### 24.链表导数第K个节点

```java
/*
public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}*/
public class Solution {
    public ListNode FindKthToTail(ListNode head,int k) {
        int num = 0;
        ListNode tmp = head;
        while (num < k) {
            if (head == null) {
                return null;
            }
            num++;
            head = head.next;
        }
        while (head != null) {
            head = head.next;
            tmp = tmp.next;
        }
        return tmp;
    }
}
```

### 25.包含min函数的栈

定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。

注意：保证测试中不会当栈为空的时候，对栈调用pop()或者min()或者top()方法。



解答

使用两个栈，一个存数，一个存当前最小值

```
import java.util.Stack;

public class Solution {
    private Stack<Integer> stack1;
    private Stack<Integer> stack2;
    private int top1;
    
    public Solution() {
       stack1 = new Stack();
       stack2 = new Stack();
       stack2.push(32767);
    }
    
    public void push(int node) {
        stack1.push(node);
        top1 = node;
        int top2 = stack2.peek();
        
        if (top2 > node) {
            stack2.push(node);
        }
        else {
            stack2.push(top2);
        }
    }
    
    public void pop() {
        if(!stack1.empty()) {
            stack1.pop();
            stack2.pop(); 
        }
    }
    
    public int top() {
        return top1;
    }
    
    public int min() {
        int min = stack2.peek();
        return min;
    }
}
```

### 26.字符流中第一个不重复的字符

请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。



解答

用大数组作为hash数组存储字符出现的次数

```java
public class Solution {
    
    private String s = "";
    private int[] hash = new int[128];
    
    //Insert one char from stringstream
    public void Insert(char ch)
    {
        s += ch;
        hash[ch]++;
    }
  //return the first appearence once char in current stringstream
    public char FirstAppearingOnce()
    {
        for (int i = 0; i < s.length(); i++) {
            if (hash[s.charAt(i)] == 1) {
                return s.charAt(i);
            }
        }
        return '#';
    }
}
```



### 27.数组中只出现一次的数字

一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。



解答

首先记录所有的异或值，异或值则为两个数的异或值，查看异或值那个位置为1（肯定有至少一个位置为1，因为两个数不同，根绝这个位置的不同则可把原来的数分成两拨，每一波异或则为求值）

```java
//num1,num2分别为长度为1的数组。传出参数
//将num1[0],num2[0]设置为返回结果
public class Solution {
    public void FindNumsAppearOnce(int [] array,int num1[] , int num2[]) {
        int a = 0;
        for (int i = 0; i < array.length; i++) {
            a = a ^ array[i];
        }
        int idx = 1;
        while ((idx & a)==0) {
            idx = idx << 1;
        }
        int result1 = 0;
        int result2 = 0;
        for (int i = 0; i < array.length; i++) {
            if ((array[i] & idx) == 0) {
               result1 = result1 ^ array[i];
            } else {
               result2 = result2 ^ array[i];
            }
        }
        num1[0] = result1;
        num2[0] = result2;
    }
}
```

### 28.栈的压入、弹出序列

输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）



解答

模拟栈的pop，当栈顶和pop序列头相同时则pop，否则压栈，最后栈空则合法

```java
import java.util.*;

public class Solution {
    public boolean IsPopOrder(int [] pushA,int [] popA) {
        Stack<Integer> s = new Stack();
        int i = 0;
        int j = 0;
        for (; i < pushA.length; i++) {
            s.push(pushA[i]);
            
            while (!s.empty() && s.peek() == popA[j]) {
                s.pop();
                j++;
            }
        }
        
        if (!s.empty()) {
            return false;
        } else {
            return true;
        }
        
    }
}
```

### 29.和为S的两个数字

输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。



解答

使用双指针扫描

```java
import java.util.*;

public class Solution {
    public ArrayList<Integer> FindNumbersWithSum(int [] array,int sum) {
        ArrayList<Integer> a = new ArrayList();
        
        int l = 0;
        int h = array.length-1;
        int mul = 32767;
        int m = 32767;
        int n = 0;
        while (l <= h) {
            if (array[l] + array[h] < sum) {
                l++;
            } else if (array[l] + array[h] > sum) {
                h--;
            } else if (array[l] + array[h] == sum) {
                if (array[l] * array[h] < mul) {
                    m = array[l];
                    n = array[h];
                    mul = array[l] * array[h];
                }
                l++;
                h--;
            }
        }
        if (m == 32767) {
            return a;
        }
        a.add(m);
        a.add(n);
        return a;
    }
}
```

### 30.二叉搜索树与双向链表

输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。



```java
import java.util.ArrayList;
/**
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
*/
public class Solution {
    private ArrayList<TreeNode> a = new ArrayList();
    
    public void pre(TreeNode root) {
        if (root == null) {
             return;
         }
        pre(root.left);
        a.add(root);
        pre(root.right);
    }
    
    public TreeNode Convert(TreeNode pRootOfTree) {
        if (pRootOfTree == null) {
            return null;
        }
        
        pre(pRootOfTree);
        TreeNode preNode = a.get(0);
        preNode.left = null;
        for (int i = 1; i < a.size(); i++) {
            TreeNode node = a.get(i);
            preNode.right = node;
            node.left = preNode;
            preNode = node;
        }
        return a.get(0);
    }
}
```

### 31.第一个只出现一次的字符

在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.



解答

使用一个128大小的数组作为hash数组

```java
public class Solution {
    public int FirstNotRepeatingChar(String str) {
        int[] a = new int[128];
        for (int i = 0; i < str.length(); i++) {
            a[str.charAt(i)] += 1;
        }
        for (int i = 0; i < str.length(); i++) {
            if (a[str.charAt(i)] == 1) {
                return i;
            }
        }
        return -1;
    }
}
```

### *32.数组中出现次数超过一半的数字

数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。



解答

超过一半的这个数在数组中分布，最多相差一个数且有两个数连着

```java
public class Solution {
    public int MoreThanHalfNum_Solution(int [] array) {
        int cnt = 0;
        int pre = array[0];
        for (int i = 0; i < array.length; i++) {
            if (array[i] == pre) {
                cnt++;
            } else {
                cnt--;
                if (cnt == 0) {
                    pre = array[i];
                    cnt = 1;
                }
            }
        }
        
        cnt = 0;
        for (int i = 0; i < array.length; i++) {
            if (array[i] == pre) {
                cnt++;
            }
        }
        if (cnt > array.length / 2) {
            return pre;
        } else {
            return 0;
        }
    }
}
```

### 33.和为S的连续正数序列

小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!



解答：

分为偶数个和奇数个判断，通过continue过滤掉不合法的，合法的直接赋值

```
import java.util.ArrayList;
public class Solution {
    public ArrayList<ArrayList<Integer> > FindContinuousSequence(int sum) {
        ArrayList<ArrayList<Integer> > res = new ArrayList<ArrayList<Integer> >();
        for (int i = sum / 2 + 1; i >= 2; i--) {
            if (i % 2 == 1) {
                if (sum % i != 0 || (sum / i - i / 2) <= 0) {
                    continue;
                }
            } else {
                if (sum % (i / 2) != 0 || sum / (i / 2) % 2 != 1 || (((sum / i) - ((i / 2)-1)) <= 0)) {
                    continue;
                }
            }
            
            ArrayList<Integer> t = new ArrayList<Integer> ();
            int a = sum / i;
            int cnt = 0;
            while (cnt < i) {
                t.add(a - ((i+1) / 2 - 1) + cnt);
                cnt++;
            }
            res.add(t);
        }
        return res;
    }
}
```

### 34.表示数值的字符串

请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。



```java
import java.io.*;

public class Solution {
    public boolean isNumeric(char[] str) {
        try {
            String s = String.valueOf(str);
            float a = Float.parseFloat(s);
            return true;
        } catch (Exception e){
            return false;
        }
    }
}
```

### 35.从上往下打印二叉树

层序遍历



```java
import java.util.*;
/**
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
*/
public class Solution {
    public ArrayList<Integer> PrintFromTopToBottom(TreeNode root) {
        ArrayList<Integer> a = new ArrayList();
        if (root == null) {
            return a;
        }
        Queue<TreeNode> q = new LinkedList();
        q.offer(root);
        while (!q.isEmpty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                TreeNode node = q.poll();
                a.add(node.val);
                if (node.left != null) {
                    q.offer(node.left);
                }
                if (node.right != null) {
                    q.offer(node.right);
                }
            }
        }
        return a;
    }
}
```

### 36. 二叉树中和为某一值的路径

输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)



解答

注意在result.add时new一个对象，不然对象在更改原来值也会更改

```java
import java.util.ArrayList;
/**
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
*/
public class Solution {
    private ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
    private ArrayList<Integer> a = new ArrayList<Integer>();
    
    public void path(TreeNode root,int target) {
        if (root == null || target - root.val < 0) {
            return;
        }
        a.add(root.val);
        target = target - root.val;
        
        if (root.left == null && root.right == null) {
            if (target == 0) {
            //注意注意注意注意注意注意
                res.add(new ArrayList(a));
            }
        }
        path(root.left, target);
        path(root.right, target);
        a.remove(a.size()-1);
    }
    
    public ArrayList<ArrayList<Integer>> FindPath(TreeNode root,int target) {
        path(root, target);
        return res;
    }
}
```

### 37.从尾到头打印链表

输入一个链表，按链表从尾到头的顺序返回一个ArrayList。



解答

反转链表

```java
/**
*    public class ListNode {
*        int val;
*        ListNode next = null;
*
*        ListNode(int val) {
*            this.val = val;
*        }
*    }
*
*/
import java.util.ArrayList;
public class Solution {
    public ArrayList<Integer> printListFromTailToHead(ListNode head) {
        ArrayList<Integer> a = new ArrayList();
        if (head == null) {
            return a;
        }
        
        ListNode p = null;
        ListNode q = null;
        while (head.next != null) {
            q = head.next;
            head.next = p;
            p = head;
            head = q;
        }
        head.next = p;
        
        while (head != null) {
            a.add(head.val);
            head = head.next;
        }
        return a;
    }
}
```

### 38.替换空格

请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

```
public class Solution {
    public String replaceSpace(StringBuffer str) {
        StringBuffer res = new StringBuffer();
        String s = str.toString();
    	for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ') {
                res.append("%20");
            }
            else {
                res.append(s.charAt(i));
            }
        }
        return res.toString();
    }
}
```

### 39.二叉搜索树的后序遍历序列

输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。



解答

找到根，再把数组分为两个部分

```java
public class Solution {
    public boolean VerifySquenceOfBST(int [] a) {
        if (a.length == 0) {
            return false;
        }
        return v(a, 0, a.length - 1);
    }
    
    public boolean v(int [] a, int l, int h) {
        if (l >= h) {
            return true;
        }
        int root = a[h];
        int m = l;
        int i = l;
        while (a[i] < root && i < h) {
            i++;
        }
        m = i;
        for (; i < h; i++) {
            if (a[i] < root) {
                return false;
            }
        }
        
        return v(a, l, m - 1) && v(a, m, h - 1);
    }
}
```

### 40.二叉搜索树的第k个结点

给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）  中，按结点数值大小顺序第三小结点的值为4。



解答

中序遍历

```java

/*
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
*/
public class Solution {
    private int cnt = 0;
    private TreeNode res = null;
    
    void midOrder(TreeNode pRoot, int k) {
        if (pRoot == null) {
            return;
        }
        
        midOrder(pRoot.left, k);
        cnt++;
        if (cnt == k) {
            this.res = pRoot;
            return;
        }
        midOrder(pRoot.right, k);
    }
    
    TreeNode KthNode(TreeNode pRoot, int k)
    {
        midOrder(pRoot, k);
        return this.res;
    }
    
}
```

### 41.树的子结构

输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）



解答

原函数确定两个根

新建一个函数判断确定的两个root的子树是否符合



```java
/**
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
*/
public class Solution {
    public boolean judge(TreeNode root1,TreeNode root2) {
        if (root2 == null) {
            return true;
        }
        if (root1 == null) {
            return false;
        }
        if (root1.val == root2.val) {
            return judge(root1.left, root2.left) && judge (root1.right, root2.right);
        } else {
            return false;
        }
    }
    
    public boolean HasSubtree(TreeNode root1,TreeNode root2) {
        if (root1 == null || root2 == null) {
            return false;
        }
        
        //确定根
        if (root1.val == root2.val) {
            //判断根的子树是否符合
            if (judge(root1, root2)) {
                return true;
            }   
        } 
        return HasSubtree(root1.left, root2) || HasSubtree(root1.right, root2);
    }
}
```

### 42.按之字形顺序打印二叉树

请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。



解答

每扫一层新建用Stack保存下层节点

```java
import java.util.*;

/*
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
*/
public class Solution {
    public ArrayList<ArrayList<Integer> > Print(TreeNode pRoot) {
        ArrayList<ArrayList<Integer> > res = new ArrayList<ArrayList<Integer> >();
       if (pRoot == null) {
           return res;
       }
        
        Stack<TreeNode> s = new Stack();
        s.push(pRoot);
        int direction = 0;
        while (!s.empty()) {
            ArrayList<Integer>  a = new ArrayList<Integer>();
            Stack<TreeNode> st = new Stack();
            int len = s.size();
            for (int i = 0; i < len; i++) {
                TreeNode t = s.pop();
                a.add(t.val);
                if (direction == 0) {
                    if (t.left != null) {
                        st.push(t.left);
                    }
                    if (t.right != null) {
                        st.push(t.right);
                    }
                } else if (direction == 1) {
                    if (t.right != null) {
                        st.push(t.right);
                    } 
                    if (t.left != null) {
                        st.push(t.left);
                    }
                }
            }
            s = st;
            if (direction == 0) {
                direction = 1;
            } else {
                direction = 0;
            }
            res.add(a);
        }
        return res;
    }

}
```

### 43.重建二叉树

输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。



根据前序和中序把数组分开

```java
/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode construct(int [] pre,int [] in, int l, int h, int m, int n) {
        if (l > h || m > n) {
            return null;
        }
        int root = pre[l];
        TreeNode node = new TreeNode(root);
        for (int i = m; i <= n; i++) {
            if (in[i] == root) {
                node.left = construct(pre, in, l+1, l+(i-m), m, i-1);
                node.right = construct(pre, in, l+(i-m)+1, h, i+1, n);
            }
        }
        return node;
    }
        
    public TreeNode reConstructBinaryTree(int [] pre,int [] in) {
        return construct(pre, in, 0, pre.length-1, 0, in.length-1);
    }
}
```

### *44.数据流中的中位数

如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。



解答

使用优先队列建立一个大顶堆和小顶堆，大顶堆保存前一半值，小顶堆保存后一半值

每次insert时，奇数时，直接插入小顶堆right中，再把right中的头顶弹出到left中，

偶数时，直接插入大顶堆left中，再把left中的头顶弹出到right

```
import java.util.*;

public class Solution {
    private PriorityQueue<Integer> right = new PriorityQueue<>();
    private PriorityQueue<Integer> left = new PriorityQueue(new Comparator<Integer>(){
        @Override
        public int compare(Integer o1, Integer o2) {
            return o2 - o1;
        }
    });
    private int cnt = 0;
    public void Insert(Integer num) {
        if (cnt % 2 == 0) {
            right.add(num);
            left.add(right.poll());
        } else {
            left.add(num);
            right.add(left.poll());
        }
        cnt++;
    }

    public Double GetMedian() {
        if (cnt % 2 == 1) {
            return (double)left.peek();
        } else {
            return (double)(left.peek() + right.peek()) / 2;
        }
    }


}
```

### **45. 滑动窗口的最大值

给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。



解答

使用一个双端队列按照当前最多size个从大到小排列的值的idx

队列头部为当前的最大值idx，实时维护队列，当扫描的i比头部idx值超多size时，弹出，此时新头部变为最大idx

```java
import java.util.*;

public class Solution {
    public ArrayList<Integer> maxInWindows(int [] num, int size)
    {
        LinkedList<Integer> idx = new LinkedList();
        ArrayList<Integer> res = new ArrayList();
        if (size <= 0) {
            return res;
        }
        
        for (int i = 0; i < num.length; i++) {
        	//把小于num[i]的值都弹出，因为不需要了
            while (!idx.isEmpty() && num[i] > num[idx.peekLast()]) {
                idx.pollLast();
            } 
            idx.add(i);
            
            //失效弹出处理
            if ((i - idx.peekFirst()) > size - 1) {
                idx.pollFirst();
            }
            if (i >= size - 1) {
                res.add(num[idx.peekFirst()]);
            }
        }
        return res;
    }
}
```

### *46.序列化二叉树

请实现两个函数，分别用来序列化和反序列化二叉树

二叉树的序列化是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，从而使得内存中建立起来的二叉树可以持久保存。序列化可以基于先序、中序、后序、层序的二叉树遍历方式来进行修改，序列化的结果是一个字符串，序列化时通过 某种符号表示空节点（#），以 ！ 表示一个结点值的结束（value!）。

二叉树的反序列化是指：根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。



解答

使用先序遍历构建序列化串，每个数用！隔开

使用split方法把串根据！分开

反序列化时记录当前扫到第几个数idx，当左子树都扫完时，下一个即为右子树序号

```java
import java.util.*;
/*
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
*/
public class Solution {
    
    String Serialize(TreeNode root) {
        if (root == null) {
            return "#";
        } else {
            return root.val + "!" + Serialize(root.left) + "!" + Serialize(root.right);
        }
  }
    
    private int idx = -1;
    private String[] s = new String[0];
    
    TreeNode Deserialize(String str) {
        if (s.length == 0) {
            s = str.split("!");
        }
        
        idx++;
        TreeNode root = null;
        if (!s[idx].equals("#")) {
            root =  new TreeNode(Integer.parseInt(s[idx]));
            root.left = Deserialize(str);
            root.right = Deserialize(str);
        }
        return root;
   }
}
```

### 47.把字符串转换成整数

将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0



解答

要考虑到数字越界的可能

int值区间[-2147483648, 2147483647]

```
public class Solution {
    public int StrToInt(String str) {
        int flag = 1;

        int v = 0;
        for (int i = 0; i < str.length(); i++) {
            if ((str.charAt(i) == '-') && i == 0) {
                flag = 0;
            } else if ((str.charAt(i) == '+') && i == 0) {
                flag = 1;
            } else if (str.charAt(i) >= '0' && str.charAt(i) <= '9') {
                if (v == Integer.MAX_VALUE / 10 && (str.charAt(i) - '0') >= 8) {
                    if ((str.charAt(i) - '0') == 8 && flag == 0) {
                        return Integer.MIN_VALUE;
                    } else {
                        return 0;
                    }
                } else if (v > Integer.MAX_VALUE / 10){
                    return 0;
                }
                v = v * 10 + str.charAt(i) - '0';
            } else {
                return 0;
            }
        }
        if (flag == 0) {
            v = -v;
        }
        return v;
    }
}
```

### 48.最小的K个数

输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。



解答

用堆

```
import java.util.*;

public class Solution {
    public ArrayList<Integer> GetLeastNumbers_Solution(int [] input, int k) {
        ArrayList<Integer> a = new ArrayList<Integer>();
        if (k > input.length) {
            return a;
        }
        PriorityQueue<Integer> q = new PriorityQueue();
        for (int i = 0; i < input.length; i++) {
            q.offer(input[i]);
        }
        
        while (k != 0) {
            int n = q.poll();
            a.add(n);
            k--;
        }
        return a;
    }
}
```

### ***49.丑数

把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。



解答

- 三个变量维护乘以2，3，5后还未加入丑数数组的，前方数的下标

- 一旦有最小值加入丑数数组，则查看是否满足三个下标乘以2，3，5，满足则说明当前下标乘以2，3，5已加入数组，下标已无用，下标加1

```java
public class Solution {
    public int GetUglyNumber_Solution(int index) {
        if (index <= 0) {
            return 0;
        }
        int[] num = new int[index];
        num[0] = 1;
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;
        int i = 1;
        while (i < index) {
            num[i] = Math.min(num[p2]*2, Math.min(num[p3]*3, num[p5]*5));
            if (num[i] % 2 == 0) p2++;
            if (num[i] % 3 == 0) p3++;
            if (num[i] % 5 == 0) p5++;
            i++;
        }
        
        return num[index-1];
    }
}
```

### 50.矩阵中的路径

请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 例如 

![image-20200416000345375](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20200416000345375.png)矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。



解答

用一个变量保存是否被访问过，满足行，列不超出，当前字符串相等，visitied为0再往下递归；

```java
public class Solution {
    private int[] v;
    public boolean path(char[] matrix, int rows, int cols, char[] str, int i, int j) {
        int row = i / cols;
        int col = i % cols;
        if (row >= 0 && row < rows && col >= 0 && col < cols && v[i] == 0 && matrix[i] == str[j]) {
            if (j == str.length - 1){
                return true;
            }
            int i1 = (row + 1) * cols + col;
            int i2 = (row - 1) * cols + col;
            int i3 = row * cols + col + 1;
            int i4 = row * cols + col - 1;
            v[i] = 1;
            if (path(matrix, rows, cols, str, i1, j+1) ||
                   path(matrix, rows, cols, str, i2, j+1) ||
                   path(matrix, rows, cols, str, i3, j+1) ||
                   path(matrix, rows, cols, str, i4, j+1)) {
                return true;
            }
            v[i] = 0;
        }
        return false;
    }
    public boolean hasPath(char[] matrix, int rows, int cols, char[] str)
    {
        v = new int [matrix.length];
        for (int i = 0; i < matrix.length; i++) {
            if (matrix[i] == str[0]) {
                if (path(matrix, rows, cols, str, i, 0)) {
                    return true;
                } 
            }
        }
        return false;
    }


}
```

### 51删除链表中重复的结点

在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5



解答

先把最前面重复的给剔除掉，直到找到一个不重复的当作头节点

```
/*
 public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}
*/
public class Solution {
    public ListNode deleteDuplication(ListNode pHead)
    {
        ListNode h = pHead;
        while (h != null) {
            int v = h.val;
            int len = 1;
            while (h.next != null) {
                if(h.next.val == v) {
                    len++;
                    h.next = h.next.next;
                } else {
                    break;
                }
            }
            if (len > 1) {
                h = h.next;
                pHead = h;
            } else {
                break;
            }
        }
        if (h == null) {
            return null;
        }
        int v = h.val;
        ListNode pre = null;
        int flag = 0;
        while (h.next != null) {
            if (h.next.val == v) {
                h.next = h.next.next;
                flag = 1;
            } else {
                if (flag == 1) {
                    pre.next = h.next;
                    flag = 0;
                } else {
                    pre = h;
                }
                h =  h.next;
                v = h.val;
            }
        }
        if (flag == 1) {
            pre.next = null;
        }
        return pHead;
    }
}
```

### 52.复杂链表的复制

输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）



解答

- 一用hashmap

- 多次遍历

  - 注意原始链表不能改变，新链表生成的同时原链表也要还原

  ![图片说明](https://uploadfiles.nowcoder.com/images/20190817/1687_1566007452847_156049DB72618CDDC4D5C4002CBC6403)

```java
/*
public class RandomListNode {
    int label;
    RandomListNode next = null;
    RandomListNode random = null;

    RandomListNode(int label) {
        this.label = label;
    }
}
*/
public class Solution {
public RandomListNode Clone(RandomListNode pHead) {
        if (pHead == null) {
            return null;
        }
        RandomListNode h = pHead;
        while (h != null) {
            RandomListNode r = new RandomListNode(h.label);
            RandomListNode t = h;
            h = h.next;
            t.next = r;
            r.next = h;
        }
        h = pHead;
        while (h != null) {
            RandomListNode r = h.next;
            if (h.random != null) {
                r.random = h.random.next;
            } else {
                r.random = null;
            }
            h = r.next;
        }
    	//用于还原原始链表
        RandomListNode pre = pHead;
        pHead = pHead.next;
        h = pHead;
        while (h.next != null) {
            pre.next = h.next;
            pre = pre.next;
            h.next = h.next.next;
            h = h.next;
        }
        pre.next = null;
        return pHead;
    }
}
```

### 53.字符串的排列

输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。



解答

f(a,b,c) = a f(b,c)+bf(a,c)+cf(b,a)

- 对字符串首字母交换n次（第一次不交换）

```java
import java.util.*;
public class Solution {
    
     public ArrayList<String> Permutation(String str) {
        StringBuilder asb = new StringBuilder(str);
        ArrayList<String> a = p(asb);
        return a;
    }
    
    public ArrayList<String> p(StringBuilder str) {
        ArrayList<String> a = new ArrayList<String>();
        if (str.length() == 0) {
            return a;
        }
        if (str.length() == 1) {
            a.add(str.toString());
            return a;
        }
        char c = str.charAt(0);
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == c && i != 0) {
                continue;
            }
            char c1 = str.charAt(i);
            str.setCharAt(i, c);
            ArrayList<String> a1 = p(new StringBuilder(str.substring(1)));
            for (int j = 0; j < a1.size(); j++) {
                a.add(c1+a1.get(j));
            }
            str.setCharAt(i, c1);
        }
        Collections.sort(a);
        return a;
    }
}
```

### 54.字符串匹配

```java
public class Solution {
    public boolean match(char[] str, char[] pattern)
    {
        int m = str.length;
        int n = pattern.length;
        boolean [][] a = new boolean[m+1][n+1];
        a[0][0] = true;
        
        // 初始化，假设str为空串时的状态，如果p中出现*也是能够匹配的
        for (int j = 1; j <= pattern.length; j++) {
            if(pattern[j-1] == '*') {
               a[0][j] = a[0][j-2];
            }
        }
        for (int i = 1; i <= str.length; i++) {
            for (int j = 1; j <= pattern.length; j++) {
              //如果当前时匹配的，则当前状态和上一状态保持一致，不管上一状态是什么
                if (str[i-1] == pattern[j-1] || pattern[j-1] == '.') {
                    a[i][j] = a[i-1][j-1];
                } if (pattern[j-1] == '*') {
                //如果当前p为*，则看str当前字符和*前面字符是否匹配，不匹配了则假设*作用0次，因此a[i][j] = a[i][j-2]
                    if (str[i-1] != pattern[j-2]) {
                       a[i][j] = a[i][j-2];
                    }
                 //如果当前p为*，则看str当前字符和*前面字符是否匹配，匹配了则*作用了多次，或一次，或0次
                    if (str[i-1] == pattern[j-2] || pattern[j-2] == '.') {
                        a[i][j] = a[i-1][j] || a[i][j-1] || a[i][j-2];
                        
                    }
                }
            }
            
        }
        return a[m][n];
    }
}
```

### 55. 翻转单词序列

牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？



```java
import java.util.*;

public class Solution {
    public String ReverseSentence(String str) {
        ArrayList<String> a = new ArrayList();
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == ' ') {
                a.add(sb.toString());
                sb.setLength(0);
            } else {
                sb.append(str.charAt(i));
            }
        }
        a.add(sb.toString());
        String s = "";
        for (int i = a.size() - 1; i >= 0; i--) {
            s = s + a.get(i);
            if (i != 0) {
                s = s + " ";
            }
        }
        return s;
        
    }
}
```

### 56.顺时针打印矩阵

输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.





```
import java.util.ArrayList;
public class Solution {
    public ArrayList<Integer> printMatrix(int [][] matrix) {
       int m = 0;
       int n = 0;
       int num1 = matrix.length;
        int num2 = matrix[0].length;
        ArrayList<Integer> a = new ArrayList<Integer>();
        while (true) {
            for (int i = m; i < m+num2; i++) {
                a.add(matrix[n][i]);
            }
            num1--;
            if (num1 == 0) return a;
            m = m+num2-1;
            n++;
            for (int i = n; i < n+num1; i++) {
                a.add(matrix[i][m]);
            }
            num2--;
            if (num2 == 0) return a;
            n = n+num1-1;
            m--;
            for (int i = m; i > m-num2; i--) {
                a.add(matrix[n][i]);
            }
            num1--;
            if (num1 == 0) return a;
            m = m - num2 + 1;
            n--;
            for (int i = n; i > n-num1; i--) {
                a.add(matrix[i][m]);
            }
            num2--;
            if (num2 == 0) return a;
            n = n-num1 + 1;
            m++;
        }
        
    }
}
```

### 57. 逆序对

在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007



解答

使用二路归并思想，当左边数组i大于右边数组j时，i到mid中间的数和j都会组成逆序对

![count](https://img-blog.csdnimg.cn/2020042422021811.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0NoZXJpbHM=,size_16,color_FFFFFF,t_70)

```java
public class Solution {
    public int InversePairs(int [] array) {
        return merge(array, 0, array.length-1);
    }
    
    public int merge(int [] array, int l, int h) {
        if (l >= h) {
            return 0;
        }
        int mid = (l + h) / 2;
        int a = merge(array, l, mid);
        int b = merge(array, mid+1, h);
        int c = mergeArray(array, l, h, mid);
        return (a + b + c) % 1000000007;
    }
    
    public int mergeArray(int [] array, int l, int h, int mid) {
        int[] temp = new int[h-l+1];
        int i = l;
        int j = mid + 1;
        int cnt = 0;
        int idx = 0;
        while (i <= mid && j <= h) {
            if (array[i] > array[j]) {
            //当左边数组i大于右边数组j时，i到mid中间的数和j都会组成逆序对
                cnt = (cnt + mid - i + 1) %1000000007;
                temp[idx] = array[j];
                idx++;
                j++;
            } else {
                temp[idx] = array[i];
                idx++;
                i++;
            }
        }
        
        while (i <= mid) {
            temp[idx] = array[i];
            idx++;
            i++;
        }
        while (j <= h) {
            temp[idx] = array[j];
            idx++;
            j++;
        }
        for (idx = 0; idx < temp.length; idx++) {
            array[l] = temp[idx];
            l++;
        }
        
        return cnt;
    }
}
```

### 58.把数组排成最小的数

输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。



解答

重写Comparator对象，把两个数变成字符串相加，看哪个字符串大

```java
import java.util.*;

public class Solution {
    public String PrintMinNumber(int [] numbers) {
        ArrayList<Integer> a = new ArrayList();
        for (int i : numbers) {
            a.add(i);
        }
        
        Collections.sort(a, new Comparator<Integer>() {
            public int compare(Integer o1, Integer o2) {
                String a = String.valueOf(o1);
                String b = String.valueOf(o2);
                String c = a+b;
                String d = b+a;
                return c.compareTo(d);
            }
        });
        StringBuffer sb = new StringBuffer();
        for (Integer i : a) {
            sb.append(String.valueOf(i));
        }
        return sb.toString();
    }
}
```

