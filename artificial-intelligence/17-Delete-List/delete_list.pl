% AIM:-

% WRITE A PROLOG PROGRAM TO IMPLEMENT delete_nth (N, L, R) THAT REMOVES THE ELEMENT ON Nth  POSITION FROM A LIST L TO GENERATE A LIST R.

% CODE:-

delete_nth(1, [_|L], L).
delete_nth(N, [H|L], [H|R]):- N1 is N - 1, delete_nth(N1, L, R).