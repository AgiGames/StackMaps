# StackMaps
A HashMap, where each node contains a Stack.

A usecase of this would be the following:

Consider a hashmap, whose values are Stack objects, where each stack holds all occurances of a value in different indeces

* *Let number (n) be located at indeces (i, j)*
* *To store n(i, j) in the Hash Map:*

```bash
n => [hashingFunction] => HashMap array index (Hi)
                      |
                      v
-----------------------------------------------------
|        |        | stack[n(i,j)] |        |        |
-----------------------------------------------------
 (Hi-2)   (Hi-1)   (Hi)            (Hi+1)   (Hi+2)
```

 * *Storing a number n(k, l) in Hi*:

 ```bash
m => [hashingFunction] => HashMap array index (Hi)
                      |
                      v
--------------------------------------------------------------
|        |        | stack[n(i,j), m(k, l)] |        |        |
--------------------------------------------------------------
 (Hi-2)   (Hi-1)   (Hi)                     (Hi+1)   (Hi+2)
```

# Thus, it can be used to store numbers of same values and different indeces under 1 easily accessible index.
