module Main where

import Data.Int

type Long=Int64
data SegmentTree = Null | Node SegmentTree SegmentTree Int Int Long

build::Int->Int->SegmentTree
build l r | l==r = Node Null Null l r 0
build l r = Node left right l r 0
  where left  = build l m
        right = build (m+1) r
        m     = (l+r) `div` 2

update::SegmentTree->Int->Int->Long->SegmentTree
update Null _ _ _ = Null
update (Node left right l r value) begin end _ | r < begin || end < l = Node left right l r value
update (Node left right l r _) begin end x | begin <= l && r<=end = Node newLeft newRight l r x
  where newLeft  = update left begin end x
        newRight = update right begin end x
update (Node left right l r _) begin end x = Node newLeft newRight l r newValue
  where newLeft  = update left begin end x
        newRight = update right begin end x
        newValue = max newLeftValue newRightValue
        (Node _ _ _ _ newLeftValue)  =  newLeft
        (Node _ _ _ _ newRightValue) =  newRight

query::SegmentTree->Int->Int->Long
query Null _ _ = 0
query (Node _ _ l r _) begin end | r < begin || end < l = 0 
query (Node _ _ l r value) begin end | begin<=l && r<=end = value 
query (Node left right _ _ _) begin end = max (query left begin end) (query right begin end)

makeTuple::[Int]->[(Int,Int)]
makeTuple [ ] = []
makeTuple [_] = []
makeTuple (a:b:c) = (a,b) : makeTuple c

initTree::SegmentTree->Int->[Int]->SegmentTree
initTree t _ [] = t
initTree t p (x:xs) = initTree (update t p p (fromIntegral x::Long)) (p+1) xs

solveAQuery::SegmentTree->[(Int,Int)]->[Long]
solveAQuery _ [] = []
solveAQuery t ((w,h):xs) = ans:solveAQuery newT xs
  where ans  = query t 1 w
        newT = update t 1 w (ans+(fromIntegral h::Long))

solve::Int->[Int]->[(Int,Int)]->[Long]
solve n a = solveAQuery (initTree (build 1 n) 1 a)

main::IO()
main = do
  input <- getContents
  let
    (n:number0) = map read (words input)::[Int]
    a = take n number0
    (m:number1) = drop n number0
    wh = take m (makeTuple number1)
  putStr $ foldr (\x y->show x ++ "\n" ++ y) "" (solve n a wh)
