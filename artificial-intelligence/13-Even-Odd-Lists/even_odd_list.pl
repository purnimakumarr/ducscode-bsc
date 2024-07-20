% AIM:-

% WRITE A POLOG PROGRAM TO IMPLEMENT TWO PEDICATES evenlength(List) and oddlength(List) SO THAT THEY ARE TRUE IF THEIR ARGUMENT IS A LIST OF EVEEN OR ODD LENGTH RESPECTIVELY. 

% Write a Prolog program to implement two predicates evenlength(List) and oddlength(List) so that they are true if their argument is a list of even or odd length respectively.

% CODE:-

evenlength([]).
evenlength([Head|Tail]):- oddlength(Tail).

oddlength([_]).
oddlength([Head|Tail]):- evenlength(Tail). 