Names={'Lily','Lucy','Lilei','Hanmeimei','Mike','Nancy','Jack'};
Verbs={'loves','eats','buys','hates','wants'};
Nouns={'basketball','rice','rocks','apples','oranges'};
p1=randi(length(Names));
p2=randi(length(Verbs));
p3=randi(length(Nouns));
fprintf('%s %s %s.\n',Names{p1},Verbs{p2},Nouns{p3});
