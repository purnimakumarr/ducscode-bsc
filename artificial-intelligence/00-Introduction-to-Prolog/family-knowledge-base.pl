% KNOWLEDGE BASE
human(a).
human(b).
human(c).
sibling(a, b).
sibling(b, a).
sibling(b, c).
sibling(c, b).
male(a).
female(c).

% RULES
is_brother(X, Y) :- sibling(X, Y), male(X).
is_sister(X, Y) :- sibling(X, Y), female(X).