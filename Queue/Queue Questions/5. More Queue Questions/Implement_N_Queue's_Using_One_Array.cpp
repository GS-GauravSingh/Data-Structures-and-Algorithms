/*
Question:- Design a Data structure to implement N Queue's using a single array of size S. It should support the following operation,
1. push(x,m) => push x in mth stack. return true is element is pushed else return false.
2. pop(m) => pop the top element from the mth stack, return 01 if stack is empty else return popped element.


Approach 1:- suppose the size of array is N and you need to implement k queues in array of size N. So. what you can do is divide the whole array into equal into k part of equal size and perform operation on it.

Example:-
Array of size N => |__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|
     index =>       0  1   2  3  4  5  6  7  8  - - - -  - -  - - - n-1

Suppose you need to implement K stack in above array,

Length of entire array => N,
divide array into K parts => the length of each part of N/K. After that you can perfor push, pop operation in whichever part you want.

But the biggest drawback of this approach is, it is not space optimized. Suppose you are trying to push elements more than the length of paticular stack i.e., N/k, you cannot do this because you divide array into k part and each part have same length i.e., N/k you cannot push element more than N/k in each part.

Approach 2:- is similar as we seen in N stack in one array.

Array of size N => |__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|
     index =>       0  1   2  3  4  5  6  7  8  - - - -  - -  - - - n-1

suppose we have an array of size N and we need to implement K stacks in it.
So, the additional thing we need is,
     front[K]; // represent index of front element. [k queue's ke jo front element honge unka index store karega ye front[] array].

     rear[K]; // represent index of rear element. [k queue's ke jo rear element honge unka index store karega ye front[] array].

     next[N]; it points to next free space/block.


------------------ Operations ----------------------------------
push:-
steps 1:- check for overflow condition (freespot == -1).
steps 2:- find index, where you want to insert.
          int index = freeSpot;
steps 3:- update freespot. freespot = next[index];
steps 4:-
if(we have to insert first element, [front[k-1] == -1]){
     // update front;
     front = index;
}
else{
     // if it is not the first element.
     Example:- q1.push(3),
               q1.push(5),
               q2.push(7),
               q2.push(8),

               q1.push(17),

     arr:- {3,5,7,9, 17}

     3,5 are elements fo q1, 7,8 are elements fo q2.
     So, Now if you want to push 17 in q1, you need to link 17 with rest of th elements of q1.

     next[rear[k-1]] = index;

}
     // set next[index] = -1, because after pushing value at index there is no free space left.
     next[index] = -1;

     // update rear.
     rear[k-1] = index;

     //insert element
     arr[index] = value;



pop:- 
1. check for underflow condition.
2. find index, int index = front[qn-1];
3. update front. front[qn-1] = next[index];

*/

#include <bits/stdc++.h>
using namespace std;

class KQueue
{
private:
     int n;    // size of array.
     int k;    // k stacks.
     int *arr; // original array.
     int *front;
     int *rear;
     int *next;
     int freeSpot;

public:
     // constructor.
     KQueue(int size, int numberOfStacks)
     {
          n = size;
          k = numberOfStacks;

          arr = new int[n];
          front = new int[k];
          rear = new int[k];
          next = new int[n];

          freeSpot = 0;

          // initializing front and rear.
          for (int i = 0; i < k; i++)
          {
               front[i] = -1;
               rear[i] = -1;
          }

          // initializing next
          for (int i = 0; i < n; i++)
          {
               next[i] = i + 1;
          }
          next[n - 1] = -1;
     }

     // method to push data in nth queue(qn).
     void enqueue(int data, int qn){
          // check for overflow condition
          if(freeSpot == -1){
               cout<<"No Empty space is present.\n";
               return;
          }

          // find index to push element.
          int index = freeSpot;

          // update freespot
          freeSpot = next[index];

          // check if first element is comming to push.
          if(front[qn-1] == -1){
               // upadte front
               front[qn-1] = index;
          }
          else{
               // if it is not the first element.

               // link new element to the previous element of queue.
               next[rear[qn-1]] = index;
          }

          // update next.
          next[index] = -1;

          // update rear.
          rear[qn-1] = index;

          // push element
          arr[index] = data;
     }

     // method to pop front element from the nth queue(qn).
     int dequeue(int qn){
          // chek for underflow condition
          if(front[qn-1] == -1){
               cout<<"Queue Underflow.\n";
               return -1;
          }

          // find index to pop
          int index = front[qn-1];

          // update fornt
          front[qn-1] = next[index];

          // setting up freeSpot
          next[index] = freeSpot;
          freeSpot = index;

          return arr[index];
     }
};

int main()
{
     KQueue q(10, 3);

     q.enqueue(10, 1);
     q.enqueue(15, 1);
     q.enqueue(20, 2);
     q.enqueue(25, 1);

     cout<<q.dequeue(1)<<endl;
     cout<<q.dequeue(2)<<endl;
     cout<<q.dequeue(1)<<endl;
     cout<<q.dequeue(1)<<endl;
}
