/*
Special Stack 

Easy Accuracy: 50.0% Submissions: 46466 Points: 2
Design a data-structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin()
 which should return minimum element from the SpecialStack. Your task is to complete all the functions, using stack data-Structure.


Example 1:

Input:
Stack: 18 19 29 15 16
Output: 15
Explanation:
The minimum element of the stack is 15.
 


Your Task:
Since this is a function problem, you don't need to take inputs. You just have to complete 5 functions, push() which takes the stack and an integer x 
as input and pushes it into the stack; pop() which takes the stack as input and pops out the topmost element from the stack; isEmpty() which takes 
the stack as input and returns true/false depending upon whether the stack is empty or not; isFull() which takes the stack and the size of the stack  as 
input and returns true/false depending upon whether the stack is full or not (depending upon the given size); getMin() which takes the stack as 
input and returns the minimum element of the stack. 
Note: The output of the code will be the value returned by getMin() function.


Expected Time Complexity: O(N) for getMin, O(1) for remaining all 4 functions.
Expected Auxiliary Space: O(1) for all the 5 functions.


Constraints:
1 = N = 104
*/

#include<iostream>
#include<stack>
using namespace std;
void push(int a);
bool isFull(int n);
bool isEmpty();
int pop();
int getMin();
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty()){
		    pop();
		}
		while(!isFull(n)){
			cin>>a;
			push(a);
		}
		cout<<getMin()<<endl;
	}
}// } Driver Code Ends
/*Complete the function(s) below*/
void push(int a)
{
//add code here.
s.push(a);
}
bool isFull(int n)
{
//add code here.
if(s.size() == n)
return true;
else return false;
}
bool isEmpty()
{
//add code here.
return s.empty();
}
int pop()
{
//add code here.
int el = s.top();
s.pop();
return el;

}
int getMin()
{
//add code here.
int min = s.top();
s.pop();

while(!s.empty()){
if(s.top() < min)
min = s.top();
s.pop();
}

return min;
}


