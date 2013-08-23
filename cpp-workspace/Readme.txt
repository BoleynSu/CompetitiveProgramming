This program is based on these assumptions:
1. Every given word is from a certain dictionary that is similar to other dictionaries.
2. If a word of length L is choosen, then every word of length L in this dictionary has the same probability to be choosen.
3. Words in my dictionary is very similar to the dictionary used to generate words to be guessed. 'Similar' means given any restriction, the frequency of a certain letter shows in words satisfying the restriction of both dictionary are similar.

Pseudocode:

Let dict[L]:=the list that contains words of length L in my dictionary for all possible length L;

Let frq[L][a]:=(number of words in dict[L] that contains letter a)/(size of dict[L]) for all possible length L and all possible letter a;

Function match(String s,Set TriedButFail,Set TriedAndSucceed,String word):Boolean;
begin
	match:=true;
	for i:=1 to length of s do
		if (s[i]<>'*' and t[i]<>s[i]) or (t[i]='*' and s[i] in TriedAndSucceed) or (s[i] in TriedButFail) then
			match:=false;
end;

Function bestStrategy(String s,Set TriedButFail,Set TriedAndSucceed):Character;
begin
	Let count[a]:=0 for all possible letter a;
	for each word in dict[length of s] and match(s,TriedButFail,TriedAndSucceed,word) do
		for each a in [A-Z] and word contains a 
			increase count[a] by one;
	if exists some letter a that count[a] is positive
		then bestStrategy:=letter x that count[x]>=count[y] for all possible letter y and x is not in TriedButFail or TriedAndSucceed;
		else bestStrategy:=letter x that frq[length of s][x]>=frq[length of s][y] for all possible letter y and x is not in TriedButFail or TriedAndSucceed;
end;

Procedure guessAWord(String s);
begin
	Let TriedButFail:=empty set;
	Let TriedAndSucceed:=empty set;
	do apply bestStrategy(s,TriedButFail,TriedAndSucceed) and update s,TriedButFail,TriedAndSucceed according to the response.
	until s is the word we want or there is no chance to try again;
end;

