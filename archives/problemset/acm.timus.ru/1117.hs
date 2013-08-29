module Main where

import Data.Int
import Data.Char
import Data.List
import Text.Printf

type Long=Int64

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
  if n == 0
    then return []
    else do
      x <- nextInt
      xs <- nextInts (n-1)
      return (x:xs)

makeTriple::[a]->[(a,a,a)]
makeTriple (a:b:c:d) = (a,b,c):makeTriple d
makeTriple [] = []
makeTriple _ = undefined

-- solution: --

f::Int->Long
f = f' []
  where
    f' table x = fst $  f'' table x
    f'' table x | length found /= 0 = (snd $ head found,table)
                | x <= 1 = (0::Long,(x,0::Long):table)
                | x == tk = 
                  let
                    (a,at) = f'' table (x-1)
                  in
                    (a + (fromIntegral(k-1)::Long),(x,a + (fromIntegral(k-1)::Long)):at)
                | otherwise = 
                  let
                    (a,at) = f'' table (tk)
                    (b,bt) = f'' at (x-tk)
                  in
                    (a + (fromIntegral(k-1)::Long) + b,(x,a + (fromIntegral(k-1)::Long) + b):bt)
      where
        found = filter (\(key,_)->key==x) table
        y = (1::Long):zipWith (+) y y
        z = takeWhile (<=(fromIntegral(x)::Long)) y
        k = length z - 1
        tk = (fromIntegral(last z)::Int)

main::IO()
main = do
  n <- nextInt
  m <- nextInt
  printf "%d\n" $ abs $ f n - f m
