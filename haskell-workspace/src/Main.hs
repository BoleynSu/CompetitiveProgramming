{-#LANGUAGE BangPatterns#-}
module Main where

import qualified Data.ByteString.Lazy.Char8 as L
import Data.Char (isSpace)

-- begin template

import Data.List

uniqueBy::Ord a=>(a->a->Ordering)->[a]->[a]
uniqueBy cmp (x:y:xs) = if cmp x y == EQ then uniqueBy cmp (y:xs) else x:uniqueBy cmp (y:xs)
uniqueBy _ x = x

unique::Ord a=>[a]->[a]
unique = uniqueBy compare

{-
readInt::[String]->(Int,[String])
readInt (x:xs) = (read x,xs)

readInts::[String]->Int->([Int],[String])
readInts (x:xs) y | y/=0 = let (get,rest) = readInts xs (y-1) in (read x:get,rest)
readInts x _ = ([],x)
-}
-- end template

split :: [a] -> ([a],[a])
split xs = go xs xs where
  go (x:xs) (_:_:zs) = (x:us,vs) where (us,vs)=go xs zs
  go    xs   _       = ([],xs)
merge :: (a -> a -> Bool) -> [a] -> [a] -> [a]
merge pred xs []         = xs
merge pred [] ys         = ys
merge pred (x:xs) (y:ys) =
  case pred x y of
    True  -> x: merge pred xs (y:ys)
    False -> y: merge pred (x:xs) ys

mergesort :: (a -> a -> Bool) -> [a] -> [a]
mergesort pred []   = []
mergesort pred [x]  = [x]
mergesort pred xs = merge pred (mergesort pred xs1) (mergesort pred xs2)
  where
    (xs1,xs2) = split xs

parseInput :: Parser ([Int],[Int])
parseInput = do
    n <- readInt
    a <- readInts n
    m <- readInt
    b <- readInts m
    return (a,b)

-- Implementation of State monad, because Codeforces doesn't have
-- necessary libraries installed.
data Parser a = Parser {runParser :: L.ByteString -> (a, L.ByteString)}
instance Monad Parser where
  return x  = Parser (\c -> (x, c))
  mx >>= my = Parser f
    where f c = let (x, c')  = runParser mx c
                    (y, c'') = runParser (my x) c'
                in (y, c'')

get :: Parser L.ByteString
get = Parser (\c -> (c, c))

put :: L.ByteString -> Parser ()
put c = Parser (\_ -> ((), c))
-- End of State monad

skipSpace :: Parser ()
skipSpace = do
    c <- get
    let (space, next) = L.span isSpace c
    put next

readInt :: Parser Int
readInt = do
    skipSpace
    c <- get
    let Just (n, rest) = L.readInt c
    put rest
    return n

readInts :: Int -> Parser [Int]
readInts count = mapM (const readInt) [1..count]

main::IO()
main = do
  input <- L.getContents
  let
    ((a,b),_) = runParser parseInput input
  print $ solve (unique $ mergesort (<) a) (mergesort (<) b) 0
  where solve a@(!x:xs) (!y:ys) !ans | x==y = solve a ys (ans+1)
        solve (!x:xs) b@(!y:ys) !ans | x<y  = solve xs b ans
        solve a@(!x:xs) (!y:ys) !ans | x>y  = solve a ys ans
        solve _ _ !ans = ans::Int
