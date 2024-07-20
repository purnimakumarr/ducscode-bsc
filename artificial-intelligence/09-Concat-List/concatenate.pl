% AIM:- 

% WRITE A PROLOG PROGRAM TO IMPLEMENT sumList(L, S) SO THAT S IS THE SUM OF A GIVEN LIST L

% CODE:-

conc([],L, L).
conc([X|L1], L2, [X|L3]):- conc(L1, L2, L3).
