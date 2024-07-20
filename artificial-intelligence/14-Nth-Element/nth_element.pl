% AIM:-

% WRITE A PROLOG PROGAM TO IMPLEMENT nth_element (N, L, X) WHERE N IS THE DESIRED POSITION, L IS A LIST AND X REPRESENTS THE Nth ELEMENET OF L.

% CODE:-

nth_element(1, [H|T], H).
nth_element(N, [H|T], X):-
  N1 is N - 1,
  nth_element(N1, T, X).