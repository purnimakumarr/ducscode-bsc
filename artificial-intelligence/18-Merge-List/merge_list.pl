% AIM:-

% WRITE A PROGRAM IN PROLOG TO IMPLEMENT merge (L1, L2, L3) WHERE L1 IS FIRST ORDERED LIST AND L2 IS SECOND ORDERED LIST AND L3 REPRESENTS THE MERGED LIST.

% CODE:-

merge(L1, [], L1).
merge([], L2, L2).
merge([L1|X], [L2|Y], [L1|L3]):- L1 < L2, !, merge(X, [L2|Y], L3).
merge([L1|X], [L2|Y], [L1,L2|L3]):- L1 = L2, !, merge(X, Y, L3).
merge([L1|X], [L2|Y], [L2|L3]):-L1 > L2, !, merge([L1|X], Y, L3).