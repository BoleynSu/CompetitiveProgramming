
main =
  do
    input <- getContents
    let
      (x:y:m:_) = map (read::String->Int) (words input)
    putStr $ show $ get x y m
  where
    get x y m | max x y >= m = 0
              | otherwise    = 1