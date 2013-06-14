
import Data.Char(digitToInt)
import Data.List(sort)

toInt::[Char]->Int
toInt x =
 let 
     toInt'::[Char]->Int->Int
     toInt' y z =
      if null y
         then z
         else toInt' (tail y) (z*10+(digitToInt (head y)-digitToInt '0'))
 in toInt' x 0

split::[Char]->[Char]->[[Char]]
split x y =
 let
  split'::[Char]->[Char]->[Char]->[[Char]]
  split' _ [] [] = []
  split' _ [] c = [c]
  split' a (b:bs) c =
   if null [t|t<-a,t==b]
   then split' a bs (b:c)
   else (reverse c):(split' a bs [])
 in split' x y []

getAns::[Int]->Int
getAns x =
 let
 getAns'::[Int]->Int->Int->Int->Int
 getAns' [] _ lstCnt ans =
  if lstCnt>2
   then -1
  else if lstCnt==2
   then ans+1
  else
   ans
 getAns' (x:xs) lst lstCnt ans =
  if x/=lst&&lstCnt>2
   then -1
  else if x/=lst&&lstCnt==2
   then getAns' xs x 1 (ans+1)
  else if x==lst
   then getAns' xs lst (lstCnt+1) ans
  else
   getAns' xs x 1 ans
 in getAns' x 0 0 0

main::IO()
main =
 do
 input <- getContents
 let
  numbers = fmap toInt (split " \n" input)
  n = head numbers
  id = sort [x|x<-(tail numbers),x/=0]
 print $ getAns id

