% AIM:-

% WRITE A PROLOG PROGRAM TO IMPLEMEMTN power (Num, Pow, Ans) : WHERE Num IS RAISED TO THE POWER Pow TO GET Ans.

% CODE:-

power(_, 0, 1).
power(Num, Pow, Ans):- 
  X1 is Pow - 1, power(Num, X1, Ans1), Ans is Ans1 * Num.

