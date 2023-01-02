# Min-Stack-Implementation
<strong>What is a Min Stack</strong><br>
A min stack is a stack that always tracks where the minimum value in the stack is. This value can be retrieved in O(1) time.

<strong>Implementation</strong><br>
The main features that are implemented are your basic stack functions: push, pop, and top. A min stack also has the ability to return the
minimum value in the stack at any time in O(1) time.

The implementation is completed through creating two classes: MinStack and stack_element. The min stack stores elements of type stack_element.
This design decision was made because I needed a way to keep track of the next smallest value after the smallest value just in case the smallest value was popped
from the stack. A stack_element consists of a value and the next smallest value after itself. 

Not all stack_elements have a next smallest element though since if I have the minimum value already on the stack and push larger values, it is pointless to 
keep track or point to these larger values since they will never be minimum values. 

Essentially, the stack_element class basically acts as a linked list to keep track of minimum values.
