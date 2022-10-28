# push_swap
<img width="1890" alt="Screen Shot 2022-10-05 at 4 40 51 PM" src="https://user-images.githubusercontent.com/94700601/196174808-9f8b3ee7-c272-4d90-aea3-7fab724f0c31.png"><br />
#### Final Score 117/100 <br />
- Mean: 6 instructions for stack of size 5 <br />
- Mean: 817 instructions for stack of size 100 <br />
- Mean: 5752 instructions for stack of size 500 <br />
<br />
## Challenge

Sort a random list of integers using the smallest number of moves, 2 stacks
and a limited set of operations. <br />
<br />

You start with two empty stacks: **a** and **b**. You are given a random list of integers via command line arguments.
<br />
<br />

Only these moves are allowed:
- `sa` : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
- `sb` : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
- `ss` : `sa` and `sb` at the same time.
- `pa` : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
- `pb` : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
- `ra` : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
- `rb` : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- `rr` : `ra` and `rb` at the same time.
- `rra` : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- `rrb` : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- `rrr` : `rra` and `rrb` at the same time.
<br />

At the end, **stack b** must empty empty and all integers must be in **stack a**, sorted in ascending order. <br />
<br />

## The Project
Create two programs: ```checker``` and ```push_swap```. <br />

The ```checker``` program reads a random list of integers from the stdin, stores them, and checks to see
if they are sorted. <br />
<br />
The ```push_swap``` program calculates the moves to sort the integers – *pushing, popping, swapping* and *rotating* 
them between **stack a** and **stack b** – and displays those directions on the stdout. <br />
<br />
You can pipe ```push_swap``` into ```checker```, and ```checker``` will verify that ```push_swap```'s instructions were successful. 
<br />

Both programs must mandatorily parse input for errors, including empty strings, no parameters, 
non-numeric parameters, duplicates, and invalid/non-existent instructions.

**Push_Swap** must conform to the [42 Norm](https://cdn.intra.42.fr/pdf/pdf/960/norme.en.pdf). <br />
Using normal ```libc``` functions is strictly forbidden. Students are however, allowed to use: ```write```, ```read```, ```malloc```, ```free```, ```exit```. 
It must not have any memory leaks. Errors must be handled carefully. <br />
In no way can it quit in an unexpected manner (segmentation fault, bus error, double free, etc).

## Approach

In an ideal world, I have an optimization part that would take my ```silent list``` of instructions, and clean up every actions that cancel each others such as ```pa / pb``` or ```ra / rra```, but I could not make it work properly, so my program is a tiny bit above the limit number of instructions to get the maximum of points :( 



I stored all integers in a **circular linked list** <br />

```./push_swap``` stores all my moves to my ```silent list```, and print the list of instructions at the end of the program, which ```./checker``` then reads off the ```stdin```. <br />

To use the checker, launch ```./checker```. To push an integer to **stack b**, type ```pb``` and hit ‘enter’. To see if a combination of moves has sorted the stack, type ```control D``` to finish, and the ```./checker``` will display “OK” for sorted or “KO” for unsorted. <br />

To sort my stack I used 3 different algorithms: one for 5 numbers or less, quicksort for more than 5 numbers, and insertion to optimise before to apply quicksort on ```b```. I hardcoded every combination of list of 4 numbers that had more than 5 instructions, in order to get 5 instructions maximum when sorting 4. <br />

For quicksort, I find the ideal pivot by storing all my chunk into an array, that I sort using a basic insertion sort, in order to get the value store at 1/2 of my array. I push everything below the median into ```stack b``` and call it recursively until I have less than 6 numbers in ```stack a``` for the first round, and less than 3 numbers to sort for the next rounds. Then I apply Quicksort to the last chunk that has been pushed to ```b```, tho before o partition I first check if the first or second number of my stack is the max or previous max of ```b```, in order to push it back to ```a```.<br />

## Usage
Run ```make```.

The **checker** program is used as follows:
```c
  ./checker 5 2 3 1 4
```
```c
  ./checker "-50 -400 -20 -1 -100"
```
```c
  ./checker "-22" "35" "40" "-15" "75"
```

The **push_swap** program is used in the same way
```c
  ./push_swap 5 2 3 1 4
```

You can run the two together using:
```c
  ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker -v $ARG
```
Note: the **-v (debug) flag** shows the stack status after each operation. 
![screen capture of checker and push_swap](./images/visualizer.gif)
<br />

To see push_swap in action, run ```make``` and then the following script:
```
python3 pyviz.py `ruby -e "puts (1..20).to_a.shuffle.join(' ')"`
```
![screen capture of checker and push_swap](./images/visualizer2.gif)
