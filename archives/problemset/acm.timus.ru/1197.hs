module Main where

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

main::IO()
main = do
  input <- getContents
  let
    tokens = words input
    n = (read $ head tokens )::Int
    knight = get $ tail tokens
    attack = solve knight
  mapM print $ map length attack
  return ()
  where solve (x:xs) = (filter (\(x,y) -> 1<=x && x<=8 && 1<=y && y<=8) (solve' x)):(solve xs)
        solve _ = []
        solve' (x,y) = map (\(dx,dy)->(x+dx,y+dy)) [(-2,-1),(-2,1),(-1,-2),(-1,2),(1,-2),(1,2),(2,-1),(2,1)]
        get (x:xs) = (get' x):(get xs)
        get _ = []
        get' [a,b] = (toInt a,toInt b)
        get' _ = error "It should never happen!"
        toInt '1' = 1
        toInt '2' = 2
        toInt '3' = 3
        toInt '4' = 4
        toInt '5' = 5
        toInt '6' = 6
        toInt '7' = 7
        toInt '8' = 8
        toInt 'a' = 1
        toInt 'b' = 2
        toInt 'c' = 3
        toInt 'd' = 4
        toInt 'e' = 5
        toInt 'f' = 6
        toInt 'g' = 7
        toInt 'h' = 8
