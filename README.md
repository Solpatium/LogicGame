# Logic Millionaires, but with virtual teddybears instead of money
# Build
In order to build this project run
```
make
```
in this folder. This will generate program "polscy_logicy" in dist/Debug/GNU-Linux/ path.
You can specify your logic by passing to program arguments:
```
./polscy_logicy --not not.txt --and and.txt --or or.txt --impl impl.txt
```
If you don't specify a logic a standard trinary logic (en.wikipedia.org/wiki/Three-valued_logic) is applied.

# Play
Your job is to answer correctly to 10 question. This is a VERY difficult task, if you win a game and win 10 teddybears you can be called Master of logic, Logic King\Queen or whatever you like.
Every level consists of logic sentences mixed with logic conjunctions. Every sentence and conjunction has 25% chance to be negated. You have to solve the logic puzzle.
For instance:
```
1: The moon is lighter than the Earth.
2: var x="false"; in JavieScript creates a string.

!( !1 v 2 ) in trinary logic is:
```
Both first and second sentence are correct. So we have to solve !( !true v true ).

If you don't anwer correctly, you'll get correct correct anwer and the path that leaded to correct anwer. For example above the path is:
```
!( !1 v 1 )
!1
0
```

# Good luck
Now, that you know everything you can test your logic skills. HLHF! :D
