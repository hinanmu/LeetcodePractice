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

```
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

