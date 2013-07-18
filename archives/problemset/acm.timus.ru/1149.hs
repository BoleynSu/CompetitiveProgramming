module Main where

-- begin template

sortBy::Ord a=>(a->a->Ordering)->[a]->[a]
sortBy cmp (x:xs) = (sort $ filter (\y->cmp y x == LT) xs) ++ [x] ++ (sort $ filter (\y->cmp y x /= LT) xs)
sortBy _ x = x

sort::Ord a=>[a]->[a]
sort = sortBy compare

uniqueBy::Ord a=>(a->a->Ordering)->[a]->[a]
uniqueBy cmp (x:y:xs) = if cmp x y == EQ then uniqueBy cmp (y:xs) else x:uniqueBy cmp (y:xs)
uniqueBy _ x = x

unique::Ord a=>[a]->[a]
unique = uniqueBy compare

-- end template

main::IO()
main = do
  input <- getContents
  let
    tokens = words input
    n = (read $ head tokens )::Int
  putStrLn $ s n
  where s n = getS 1 n
        getS i n | i==n = (a (n-i+1)) ++ "+" ++ (show i)
        getS i n = "(" ++ (getS (i+1) n) ++ ")" ++ (a (n-i+1)) ++ "+" ++ (show i)
        a n = getA 1 n
        getA i n | i==n = "sin(" ++ (show i) ++ ")"
        getA i n = "sin(" ++ (show i) ++ (if odd i then "-" else "+") ++ (getA (i+1) n) ++ ")"
