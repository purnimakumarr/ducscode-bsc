% AIM:-

% WRITE A PROGRAM IN PROLOG TO IMPLEMENT palindrome (L) WHICH CHECKS WHETHER A LIST IS PALINDROME OR NOT.

% CODE:-

reverse([], Z, Z).
reverse([L|T], Z, R) :- reverse(T, Z, [L|R]).

palindrome(L):- 
  reverse(L, X, []), X = L -> write("Palindrome"); write("Not Palindrome").