% AIM:- 

%  WRITE A PORLOG PROGRAM TO IMPLEMENT memb(X, L): TO CHECK WHETHER X IS A MEMBER OF LIST L OR NOT

% CODE:-

memb(X, [X|_]):- !.
memb(X, [_|L]):- memb(X, L).