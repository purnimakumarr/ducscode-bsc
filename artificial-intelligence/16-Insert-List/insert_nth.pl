% AIM:-

% WRITE A PROLOG PROGRAM TO IMPLEMENT insert_nth (I, N, L, R) that inserts an item I into the Nth position of the list to generate a list R.

% CODE:-

insert_nth(I, 1, L, [I|L]).
insert_nth(I, N, [H|L], [H|R]):- N1 is N - 1, insert_nth(I, N1, L, R).

