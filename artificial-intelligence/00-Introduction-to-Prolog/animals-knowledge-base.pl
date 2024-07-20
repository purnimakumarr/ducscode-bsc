% KNOWLEDGE BASE
dog(rottweiler). large(rottweiler).
cat(siamese). large(siamese).
dog(dobermann). 
dog(poodle).
dog(boxer). large(boxer).
cat(bengal).
dog(weimaraner). large(weimaraner).
dog(samoyed). small(samoyed).
cat(cheetoh). large(cheetoh).
cat(pomeranian). large(pomeranian).
large(mike).

% RULES
large_dog(A) :- dog(A), large(A).
large_cat(C) :- cat(C), large(C).