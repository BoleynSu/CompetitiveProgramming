main =
  do
    contents <- getContents
    let 
      n:k:_ = map (read::String->Int) (words contents)
    print $ get (n-1) k 1
  where
    get n k d
      | n <= 0    = 0
      | d < k     = 1 + get (n-d) k (d*2)
      | otherwise = ceiling $ (toRational n)/(toRational k)
