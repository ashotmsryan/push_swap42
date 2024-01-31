
The aim of this project is sort the data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed I had to manipulate various
types of algorithms and choose the most appropriate solution for an
optimized data sorting.

There are a set of integer values, 2 stacks(a, b), and a set of instructions
to manipulate both stacks. Like
<h3>Instruction set</h3>

| Code  | Instruction  | Action |
| :------------ |:---------------:| -----:|
| sa      | swap a | swaps the 2 top elements of stack a |
| sb      | swap b | swaps the 2 top elements of stack b |
| ss      | swap b + swap a | both sa and sb |
| pa      | push a | moves the top element of stack b at the top of stack a |
| pb      | push b | moves the top element of stack a at the top of stack b |
| ra      | rotate a | shifts all elements of stack a from bottom to top |
| rb      | rotate b | shifts all elements of stack b from bottom to top |
| rr      | rotate a + rotate b | both ra and rb |
| rra      | reverse rotate a | shifts all elements of stack a from top to bottom |
| rrb      | reverse rotate b | shifts all elements of stack b from top to bottom |
| rrr      | reverse rotate a + reverse rotate b | both rra and rrb |

some of these instructions are missing in my project, because of the code

To execute, run the command 'make' and then 
<pre>./push_swap 4 2 "545 8" 11 001 -9</pre>

<h3>It's working...</h3>
<pre>
For 3 args-max 2
For 5 args-max 10
For 100 args-about 550 (+-50)
For 500 args-about 5000 (+-100)</pre>
