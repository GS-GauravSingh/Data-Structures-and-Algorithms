/*

Question:- Given a queue of integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.  

Examples:-

Input :  1 2 3 4
Output : 1 3 2 4

Input : 11 12 13 14 15 16 17 18 19 20
Output : 11 16 12 17 13 18 14 19 15 20

Explanation:- 

Input : 11 12 13 14 15 16 17 18 19 20

step 1:- divide the queue in two halfs.

first half :-  11 12 13 14 15
Second half :- 16 17 18 19 20

Now in answer queue, insert first element from first half and insert first element fron second half, then insert second element from first half and insert second element fron second half and so on.

answer :- 11 16 12 17 13 18 14 19 15 20 


Time complexity:- O(n)  
Space Complexity:- O(n).

Using Stack :-

Step 1:- insert first half elements into stack. 
Step 2:- from stack push first half elements into queue. 
Step 3:- ab queue me jo first half elements hai unko pop kro and queue me push kro.
Step 4:- repeat step 1.
Step 5:- rearrange values.

Exmaple:- 
Input : 11 12 13 14 15 16 17 18 19 20
first half :-  11 12 13 14 15
Second half :- 16 17 18 19 20

Step 1:- insert first half elements into stack. 
    Stack
      15
      14
      13
      12
      11

after this step queue will have on second half elements.

Step 2:- from stack, push first half elements into queue. 
queue :- 16 17 18 19 20 15 14 13 12 11
, after this step our stack is empty.

Step 3:- ab queue me jo first half elements hai unko pop kro and queue me push kro.

before Step 3:- our queue would look like this,
queue :- 16 17 18 19 20 15 14 13 12 11
first half :-  16 17 18 19 20
Second half :- 15 14 13 12 11

after Step 3:- our queue would look like this,
queue :- 15 14 13 12 11 16 17 18 19 20
first half :-  15 14 13 12 11
Second half :- 16 17 18 19 20

Step 4:- repeat step 1.
Step 1:- insert first half elements into stack. 
    Stack
      11
      12
      13
      14
      15

after step 4:- our queue would look like this.
queue :- 16 17 18 19 20

Step 5:- rearrange values.
while(!stack.empty()){
    // now your first half elements is in stack and second half elements in in queue.

    inserting elements of first half from stack into queue.
    inserting elements of second half from queue into queue.
}

queue :- 11 16 12 17 13 18 14 19 15 20

Time complexity:- O(n)  
Space Complexity:- O(n).
*/



#include<bits/stdc++.h>
using namespace std;


// ---------------- Using Queue -----------------------------
// Time complexity:- O(n)  
//Space Complexity:- O(n).
void interLeaveQueue(queue<int> &q){
    // Step 1:-  inserting first halfe elements into new Queue.
    queue<int> firstHalf;
    int firstHalfSize = q.size()/2;
    for (int i = 0; i < firstHalfSize; i++)
    {
        firstHalf.push(q.front());
        q.pop();
    }
    // after thise loop ends, our original queue will contains only elements for second half.

    // Step 2:- while firstHalf queue is not empty, insert insert elements of first half and second half one by one in original queue.
    while (!firstHalf.empty())
    {
        // inserting elements of first half.
        q.push(firstHalf.front());
        firstHalf.pop();

        // inserting elements of second half.
        q.push(q.front());
        q.pop();
    }
}


// ---------------- Using Stack -----------------------------
// Time complexity:- O(n)  
//Space Complexity:- O(n).
void interLeaveQueue_Using_Stack(queue<int> &q){
    // Step 1:- insert first half elements into stack. 
    stack<int> s;
    int firstHalfSize = q.size()/2;
    for (int i = 0; i < firstHalfSize; i++)
    {
        s.push(q.front());
        q.pop();
    }

    // Step 2:- from stack, push first half elements into queue. 
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    // Step 3:- ab queue me jo first half elements hai unko pop kro and queue me push kro.
    firstHalfSize = q.size()/2;
    for (int i = 0; i < firstHalfSize; i++)
    {
        q.push(q.front());
        q.pop();
    }

    // Step 4:- repeat step 1.
    // Step 1:- insert first half elements into stack. 
    firstHalfSize = q.size()/2;
    for (int i = 0; i < firstHalfSize; i++)
    {
        s.push(q.front());
        q.pop();
    }

    // Step 5:- rearrange values.
    while(!s.empty()){
        // inserting elements of first half from stack into queue.
        q.push(s.top());
        s.pop();

        // inserting elements of second half from queue into queue.
        q.push(q.front());
        q.pop();
    }
    
    
}



/* Function to print Queue */
void print(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }cout<<endl;
}


int main(){
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);

    cout<<"Before Interleaving:-\n";
    print(q);

    cout<<"After Interleaving:-\n";
    // interLeaveQueue(q);
    interLeaveQueue_Using_Stack(q);
    print(q);
}