% AIM:-

% WRITE A PROLOG PROGRAM TO IMPLEMENT MAXLIST (L, M) SO THAT M IS THE MAXIMUM NUMBER IN THE LIST.

% CODE:-

max(X, Y, Z):- X > Y, Z is X.
max(X, Y, Z):- X =< Y, Z is Y.
maxlist([], 0):- !.
maxlist([R], R):- !.
maxlist([H|T], R):- maxlist(T, R1),max(H, R1, R), !.