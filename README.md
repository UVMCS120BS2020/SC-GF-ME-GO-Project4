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

// Discussion on Catan Tile class here

# Analysis

In our program, we created two vectors to test our randomization function against, one of integers and one of our Catan Tile objects. We added 3 random integers to our integer vector and 5 random tiles to our tile vector, giving us a maximum number of permutations of 3! = 6 for the random integers and 5! = 120 for the tiles. We chose to use vectors with a relatively low number of elements due to the exponential increase in permutation calculations as the vector size grows. We felt that the number of possible permutations for the vectors in combination with our large test sample size(1000) gave us solid quantifiable data to analyze our algorithms without hurting the runtime of our program.

Since it is possible to get duplicate values in these vectors, the number of possible permutations could vary each time the program is run. The following is data we collected for each of our randomization functions when all elements of the vectors were unique and an analysis of each of our algorithms:

Test Count for each vector - 1000
Integer Vector Expected Count for each Permutation - 166.667
Tile Vector Expected Count for each Permutation - 8.333

- GO


- ME


- SC


- GF
