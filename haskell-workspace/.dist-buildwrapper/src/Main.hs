module Main where

nextToken = nextToken' []
  where
    nextToken' s = do
      c<-getChar
      if isSpace c
        then return nextToken' (s++[c])
        else return s

main = do
  input<-nextToken
  putStrLn input