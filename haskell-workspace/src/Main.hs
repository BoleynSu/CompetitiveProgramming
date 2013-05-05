
import Data.List

get::Int->[Int]->[Int]
get cases numbers
  | cases == 0 = []
  | otherwise  = solve a list:get (cases-1) restNumbers
  where
    (a:n:restNumbers') = numbers
    list = sort $ take n restNumbers'
    restNumbers = drop n restNumbers'
    solve _ [] = 0
    solve b (cur:lst)
      | b > cur   = solve (b+cur) lst
      | b == 1    = solve b lst +1
      | otherwise = min (solve b ((b-1):cur:lst) + 1) (length lst + 1)

output::[Int]->IO()
output ans = output' ans 1
  where
    output'::[Int]->Int->IO()
    output' an caseNumber
      | null an  = return()
      | otherwise =
          do
            putStr "Case #"
            putStr $ show caseNumber
            putStr ": "
            print $ head an
            output' (tail an) (caseNumber+1)

main::IO()
main =
 do
   input <- getContents
   let
     (cases:numbers) = map read $ words input::[Int]
     ans = get cases numbers
   output ans
