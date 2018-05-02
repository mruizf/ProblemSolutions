# Coin change problem

This problem is a popular problem when introduce dynamic programming or recursive techniques algorithm topics. Here we see an explanation of the solution and two possible implementations, one recursive another non-recursive. 

# Problem description
 Given a quantity change ![img](http://latex.codecogs.com/svg.latex?n), we want to know how many combinations we can obtain to give this change using coins with ![img](http://latex.codecogs.com/svg.latex?%5C%7Bs_1%2Cs_2%2C%5Cldots%2Cs_m%5C%7D) values. 

 For example for n = 4 with coins ![img](http://latex.codecogs.com/svg.latex?%5C%7B1%2C2%2C3%5C%7D), we have ![img](http://latex.codecogs.com/svg.latex?4) combinations:

![img](http://latex.codecogs.com/svg.latex?%5C%7B1%2C1%2C1%2C1%5C%7D)

![img](http://latex.codecogs.com/svg.latex?%0D%0A%5C%7B1%2C1%2C2%5C%7D)

![img](http://latex.codecogs.com/svg.latex?%0D%0A%5C%7B1%2C3%5C%7D)

![img](http://latex.codecogs.com/svg.latex?%0D%0A%5C%7B2%2C2%5C%7D) 


 # Solution description
 The idea to resolve this problem is convert it in two smaller problems. For any coin we can form a partition, i.e. sets with intersection equal empty set, of the possible solution taking all of them that don't contain this coin, and the solution that use it.
 
 In out example, using coin with value ![img](http://latex.codecogs.com/svg.latex?2), the solutions that use this coin are: ![img](http://latex.codecogs.com/svg.latex?%5C%7B1%2C1%2C2%5C%7D%2C%5C%7B2%2C2%5C%7D%0D%0A) and the solutions dont use it are : ![img](http://latex.codecogs.com/svg.latex?%0D%0A%5C%7B1%2C1%2C1%2C1%5C%7D%2C%5C%7B1%2C3%5C%7D).
 
 Let's define some notation. Given a set ![img](http://latex.codecogs.com/svg.latex?%5C%7Bs_1%2Cs_2%2C%5Cldots%2Cs_m%5C%7D) of coins and a value ![img](http://latex.codecogs.com/svg.latex?n), then we define the total possible combinations to sum ![img](http://latex.codecogs.com/svg.latex?n) like ![img](http://latex.codecogs.com/svg.latex?C%28n%2C%5C%7Bs_1%2Cs_2%2C%5Cldots%2Cs_m%5C%7D%29). Then, based in the partition described in the last paragraph, we have:
 
![img](http://latex.codecogs.com/svg.latex?C%28n%2C%5C%7Bs_1%2Cs_2%2C%5Cldots%2Cs_m%5C%7D%29%3DC%28n%2C%5C%7Bs_1%2Cs_2%2C%5Cldots%2Cs_%7Bm-1%7D%5C%7D%29%2BC%28n-s_m%2C%5C%7Bs_1%2Cs_2%2C%5Cldots%2Cs_m%5C%7D%29)

The first term on the right is the combinations that don't use the ![img](http://latex.codecogs.com/svg.latex?s_m) coin, and the second term is the number of combinations that use at last 1 time the ![img](http://latex.codecogs.com/svg.latex?s_m) coin.

With this formula we obtain two smaller problems than the original.

# Recursive solution
Using the last formula we can obtain a direct implementation to resolve this problem, we need only consider the base cases:  when n=1 then ![img](http://latex.codecogs.com/svg.latex?C%28n%2C%5C%7Bs_1%2C%5Cldots%7D%29%3D1)  and when n < 0, then ![img](http://latex.codecogs.com/svg.latex?C%28n%2C%5C%7Bs_1%2C%5Cldots%7D%29%3D0). This is the pseudocode:

```
getWays(n,coins)
{
    //if we have only one coin we can easily check if it is possible form a combination
    if coins.size() = 1 
    {    
        if  n mod coins[0] = 0 
            return 1
        else
            return 0
    }
    if n < 0 
        return 0
     
     //Combination with no coins is a solution in this case   
    if n = 0
        return 1
    
    return getWays(n,coins[1..m-1]) + getWays(n-coins[m],coins[1..m])
}
```
The C++ solution is in file recursive.cpp .

# Non-recursive solution

The non-recursive solution for this problem is a common example of dynamic programming. Dynamic programming and recursive solutions are similar because resolve a complex problem by breaking it down into a collection of simpler subproblems, but the main difference is that in dynamic programming you avoid to resolve the same subproblem twice. For this it is used a cache to store the subproblems solved. We will use a table, with ![img](http://latex.codecogs.com/svg.latex?m) rows and ![img](http://latex.codecogs.com/svg.latex?n+1) columns, where ![img](http://latex.codecogs.com/svg.latex?m) is the number of coins and ![img](http://latex.codecogs.com/svg.latex?n) is the original quantity, cell in row ![img](http://latex.codecogs.com/svg.latex?s) and column ![img](http://latex.codecogs.com/svg.latex?t) contain the value `C(t,coins[1..s])`.

With this in mind we fill the table, filling each column from left to right, 

This is the pseudocode:

```
table[1..coins.size()][0..n]
getWays(n,coins)
{
    table[1][0] = 1
      
    for j = 0 to n   //quantity
    {
        for i = 1 to coins.size()  //coins
        {
            if i = 1 then
            {
                if j mod coins[i] = 0 then
                    table[i][j] = 1
                else
                    table[i][j] = 0
            }
            else
            {
                tmp = 0
                if j-coins[i] >= 0 then 
                    tmp =  table[i][j-coins[i]]
                table[i][j]=table[i][j-1]+tmp
            }
        }
    }
    return table[coins.size()][n]
}
```

The C++ solution is in file non-recursive.cpp .