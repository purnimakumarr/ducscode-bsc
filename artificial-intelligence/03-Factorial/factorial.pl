% AIM:-

% WAP IN PROLOG TO IMPLEMENT factorial (N, F) WHERE F REPRESENTS FACTORIAL OF NUMBER N.

% CODE:-

% factorial of 0 is 1
factorial(0, 1).

factorial(N, F):- N > 0,
  N1 is N - 1, 
  factorial(N1, F1), F is F1 * N.

% Approach: Decrementing the number by 1, finding the factorial of number (N - 1) and then multiplying N with factorial of (N-1) 

% eg. N = 5
% iteration 1 -> N = 5, N1 = 4, factorial(4, F1), F = F1 * 5 (4! * 5)
% iteration 2 -> N = 4, N1 = 3, factorial(3, F1), F = F1 * 4 (3! * 4)
% iteration 3 -> N = 3, N1 = 2, factorial(2, F1), F = F1 * 3 (2! * 3)
% iteration 4 -> N = 2, N1 = 1, factorial(1, F1), F = F1 * 2 (1! * 2)
% iteration 5 -> N = 1, N1 = 0, factorial(0, F1), F = F1 * 1 (0! * 1)
% N = 0, F1 = 1