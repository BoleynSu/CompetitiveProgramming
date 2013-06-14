
import Data.List

main::IO()
main =
 do
 input <- getContents
 let
  (n:_:lst) = map read (words input)::[Int]
  degree = map length (group $ sort $ lst)
  cnt x = length $ filter (==x) degree
  cnt1 = cnt 1
  cnt2 = cnt 2
 putStrLn $
  if cnt1==2&&cnt2==n-2
   then "bus topology"
  else if cnt2==n
   then "ring topology"
  else if cnt1==n-1
   then "star topology"
   else "unknown topology"
