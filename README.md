# Testing Randomization Algorithms

For this project, our team created a series of different randomization algorithms and built a test suite to evaluate their effectiveness. When creating a shuffling algorithm, values within a vector must be swapped around in a fashion that lets every possible
arrangement (a.k.a. permutation) have an equal likelihood of appearing. We use this notion as the basis for determining 
the "effectiveness" of every randomizing function created. 

How we broke the problem down starts with finding all of the 
permutations of a given vector. 
- The number of permutations of a list is the factorial of the list's size. So, if a list 
  has 5 elements, then the number of permutations is equal to 5! = 120 possibilities. 

Each one of these possibilities should have an equal chance of happening after a shuffle. So, if the shuffle algorithm 
is run enough times, then the spread of resulting shuffles should be even.
- i.e. if a shuffle algorithm is ran 120 times on a vector of size 5, then every permutation should result once
    - expected count = (#test runs)/(#permutations)

A sign of an "ineffective" shuffle algorithm would be if it resulted certain permutations at a much higher/lower rate 
than the expected count. So, while testing the homemade shuffle algorithms we keep track of every permutation that 
resulted and compared it with the expected count. 
- Note: The vector is sorted before every shuffle so that the starting point is the same before every randomization

The differences between the expected and actual counts is tallied up at the end and then averaged. This average is what 
our scoring is rooted in. The lower the average the more "effective" an algorithm is. A higher average can indicate 
issues leading to permutations happening more/less frequently compared to what should statistically happen with a 
perfect shuffle.

# Tile Class

The inspiration for our Tile class comes from the board game Settler's of Catan. In this game, the board is made up of
hexagonal tiles that each represent a different resource; wheat, sheep, wood, brick, and stone. Each tile is then given
a number spanning from 2-12 (not including 7 which represents the robber on the desert tile). These numbers represent 
dice rolls that allows players built on that specific tile to collect the resource. In order to create variety, the 
resource tiles and dice roll numbers are randomized so that each board feels new and offers different strategies the 
players can work around. So for our Tile class, the resource type and dice roll number represent its two fields. The 
non-trivial functions included are two functions that will randomize a Tile's resource or number value, as well as one
function that calls both of these to randomize a completely new Tile. At the bottom of our Tile class, there are a few
overloaded operators to help us compare two Tile objects.

# Analysis

In our program, we created two vectors to test our randomization function against, one of integers and one of our Catan Tile objects. We added 3 random integers to our integer vector and 5 random tiles to our tile vector, giving us a maximum number of permutations of 3! = 6 for the random integers and 5! = 120 for the tiles. We chose to use vectors with a relatively low number of elements due to the exponential increase in permutation calculations as the vector size grows. We felt that the number of possible permutations for the vectors in combination with our large test sample size(1000) gave us solid quantifiable data to analyze our algorithms without hurting the runtime of our program.

Since it is possible to get duplicate values in these vectors, the number of possible permutations could vary each time the program is run. The following is data we collected for each of our randomization functions when all elements of the vectors were unique and an analysis of each of our algorithms:

**Test Count for each vector** - 1000

**Integer Vector Expected Count for each Permutation** - 166.667

**Tile Vector Expected Count for each Permutation** - 8.333


- GO
 
 **Integer Vector Average Difference Count** - 73.778
 
 **Tile Vector Average Difference Count** - 7.856
 
 For my function, I decided to use time to randomize the vector in our class. In my method, for each element in the vector I got a random index and swapped the element with the element at that index. To get this random index, I got the current time in nano seconds in each for loop iteration and hashed it to a index in our vector. To add another layer of randomization, I added this time with a random constant that was recalculated each loop using the previous value.


- ME

 **Integer Vector Average Difference Count** - 166.667
 
 **Tile Vector Average Difference Count** - 15.922
 
 My function uses time as well. By taking in the value of clock() with every iteration the value is constantly changing and thus can create a different swap with every iteration. The rand() function uses time as the basis for creating a pseudo random value, so by going to the source (time itself) I am able to circumvent using the rand() function. Every iteration also multiplies the value by a prime number to add another force of randomization.


- SC

**Integer Vector Average Difference Count** - 28
 
**Tile Vector Average Difference Count** - 3.739

In my function, I used the rand() function with two for loops that iterate through the vector so that it can compare each item at a time. If the two objects being compared are different, it will swap the two object's positions and will then swap the first object (now in the second one's previous position) with an object at a random index. If the two objects are the same, it will swap that object with the last index value before swapping with a random index.


- GF

**Integer Vector Average Difference Count** - 9.222

**Tile Vector Average Difference Count** - 2.04

