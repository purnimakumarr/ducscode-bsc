% AIM:-

% WRITE A PROLOG PROGRAM TO IMPLEMENT reverse (L, R) WHERE LIST L IS ORIGINAL AND LIST R IS REVERSED LIST.

% CODE:-

reverse([], Z, Z).
reverse([L|T], Z, R) :- reverse(T, Z, [L|R]).