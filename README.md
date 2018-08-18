# Push_swap

The program calculates and displays on the standard output the least amount of instructions that will need to sort in ascending order any given set of random numbers.The learning objectives of this project are rigor, use of C and use of basic algorithms. Especially looking at the complexity of these basic algorithms.

Sorting values is simple. To sort them the fastest way possible is less simple, especially
because from one integers configuration to another, the most efficient sorting algorithm
can differ.

```
git clone https://github.com/Turandotte1/Push_swap.git
cd Push_swap
make
./push_swap 4 2 1 9 9012313
```

You may wanna use -v option in order to vizualize stacks
And you may run checker command in order to verify if stacks are actually sorted

### Rules
The game is constituted of two piles named a and b.<br/>
At the beginning, b is empty and a contains a certain number of integers positives or negatives (without duplicates).<br/>
The goal is to sort a in an increasing way.<br/>
To this end we dispose of the following operations:<br/>

```
(sa) swap a - Swap the first two elements of a.
(sb) swap b - Swap the first two elements of b.
(ss) sa and sb at the same time.
(pa) push a - Take the first element from top of b and put it on a.
(pb) push b - Take the first element from top of a and put it on b.
(ra) rotate a - Shift of a position all elements of a (towards the top, the first element becomes the last).
(rb) rotate b - Shift of a position all elements of b (towards the top, the first element becomes the last).
(rr) ra and rb at the same time.
(rra) reverse rotate a (towards the bottom, the last element becomes the first).
(rrb) reverse rotate b (towards the bottom, the last element becomes the first).
(rrr) rra and rrb at the same time.
```
