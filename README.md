# Energy price demand finder
## Author: Michael Feeney
## Date: 2026-02-20


input: 
1. array corresponding to each hour starting with the first hour of the year,
in which each value is the demand

2. array corresponding to each plant, in ascending order according to price
in which each value is the cumulative capacity

task:
for each demand value, get the index of the smallest cumulative capacity value
that is larger than the capacity

output: return an array the same size as the demand array, 
in which each value corresponds to the index of the matching cumulative capacity
that is, the cumulative capacity of the marginal plant

then we can use this index as an identifier to get the matching price and plant


