module Main where

import Data.Char(isDigit,digitToInt)
import Data.List(sort)
import Text.Printf(printf)

oo::Int
oo = 2147483647

nextInt::IO Int
nextInt = do
  c <- getChar
  if isDigit c
    then nextPosInt $ digitToInt c
    else if c == '-'
      then nextNegInt 0
      else nextInt
  where
    nextPosInt = nextIntWithFlag 1
    nextNegInt = nextIntWithFlag (-1)
    nextIntWithFlag flag = nextIntWithFlag'
      where
        nextIntWithFlag' x = do
        c <- getChar
        if isDigit c
          then nextIntWithFlag' $ x*10 + digitToInt c
          else return (flag*x)

nextInts::Int->IO [Int]
nextInts n = 
  if n==0
    then return []
    else do
      x <- nextInt
      xs <- nextInts (n-1)
      return (x:xs)

makeTriple::[a]->[(a,a,a)]
makeTriple (a:b:c:d) = (a,b,c):makeTriple d
makeTriple [] = []
makeTriple _ = undefined

solveQuestion::[(Int,Int,Int)]->[(Int,Int,Int)]->[(Int,Int,Int)]
solveQuestion naby maby = solve naby $ trans (-oo) maby
  where
    trans beg ((a,b,_):aby) = (beg,a,undefined):trans b aby
    trans beg [] = [(beg,oo,undefined)]
    solve ((na,nb,ny):nabys) ((ma,mb,my):mabys) = 
      if max na ma < min nb mb
        then (max na ma,min nb mb,ny):next
        else next
      where
        next | nb < mb = solve nabys ((ma,mb,my):mabys)
             | mb < nb = solve ((na,nb,ny):nabys) mabys
             | otherwise = solve nabys mabys
    solve [] _ = []
    solve _ [] =[]

printAnswer::[(Int,Int,Int)]->IO()
printAnswer answer = do
  putStr $ printf "%d" (length answer)
  mapM_ (\(a,b,y)->putStr $ printf " %d %d %d" a b y) answer
  putStr $ printf "\n"

main::IO()
main = do
  n <- nextInt
  naby <- nextInts (n*3)
  m <- nextInt
  maby <- nextInts (m*3)
  printAnswer $ sort $ solveQuestion (sort $ makeTriple naby) (sort $ makeTriple maby)
