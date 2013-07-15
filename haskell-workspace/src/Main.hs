module Main where

import Data.Int

type Long=Int64
data SegmentTree = Null | Node SegmentTree SegmentTree Int Int Long

build::Int->Int->SegmentTree
build l r | l == r = Node Null Null l r 0
build l r = Node left right l r 0
  where left  = build l m
        right = build (m+1) r
        m     = (l+r) `div` 2

update::Int->Int->Long->SegmentTree->SegmentTree
update begin end x = update'
  where update' Null = Null
        update' t @ (Node _ _ l r _) | r < begin || end < l = t
        update' (Node left right l r _) | begin <= l && r <= end = Node newLeft newRight l r x
          where newLeft  = update' left
                newRight = update' right
        update' (Node left right l r _) = Node newLeft newRight l r newValue
          where newLeft  @ (Node _ _ _ _ newLeftValue)  = update' left
                newRight @ (Node _ _ _ _ newRightValue) = update' right
                newValue = max newLeftValue newRightValue

query::Int->Int->SegmentTree->Long
query begin end = query'
  where query' Null = 0
        query' (Node _ _ l r _) | r < begin || end < l = 0
        query' (Node _ _ l r value) | begin <= l && r <= end = value
        query' (Node left right _ _ _) = max (query' left) (query' right)

makeTuple::[Int]->[(Int,Int)]
makeTuple [ ] = []
makeTuple [_] = []
makeTuple (a:b:c) = (a,b) : makeTuple c

main::IO()
main = do
  input <- getContents
  let
    (n:number0) = map read (words input)::[Int]
    a = take n number0
    (m:number1) = drop n number0
    wh = take m (makeTuple number1)
    t = initTree 1 a $ build 1 n
  solve t wh
  where initTree::Int->[Int]->SegmentTree->SegmentTree
        initTree _ [] t = t
        initTree p (x:xs) t = initTree (p+1) xs $ update p p (fromIntegral x::Long) t

        solve::SegmentTree->[(Int,Int)]->IO()
        solve _ [] = return ()
        solve t ((w,h):xs) = do
          print ans
          solve nt xs
          where ans = query 1 w t
                nt  = update 1 w (ans+(fromIntegral h::Long)) t
