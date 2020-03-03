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

# Analysis
