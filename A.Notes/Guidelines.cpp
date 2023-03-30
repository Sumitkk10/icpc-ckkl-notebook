1. Common Mistakes:
  * Not initialising from INT_MIN, INT_MAX but instead initialising with 0.
  * Array size when using segtree (not creating enuf nodes). 
  * Clearing inefficiently when there are multiple testcases, especially when you are using segtree / fenwick.  
2. when you arrive at a conclusion, make sure its correct before just coding and submitting. five min taken more << 1 penalty.
3. If in a graph both the nodes and edges have weights, and we have to calculate some minimum amount to build the graph or something, 
  what we can do is that we can make a duplicate node (maybe 0 or n + 1) and connect it to every node with its edge weight as the node 
  weight of the node with which we are connecting it. By doing this we have actually removed all node weights and converted them to 
  edge weights. Now you can do MST/anything.
4. If calculating the original problem seems hard consider finding the complement, i.e, finding the total number of possible answer 
  and then subtracting invalid answers acc to problem.
5.  Work extensively on samples, sometimes answer is hidden there. Consider corner cases and make special cases. Sometimes the question is 
    handling just case based.
GOOD LUCK AND HAVE FUN!
