module Main where
data SegmentTree = Null | Node SegmentTree SegmentTree Int Int Int

getValue::SegmentTree->Int
getValue Null = 0
getValue (Node _ _ _ _ value) = value
build::Int->Int->SegmentTree
build l r | l==r = Node Null Null l r 0
build l r = Node left right l r 0
  where left  = build l m
        right = build (m+1) r
        m     = (l+r) `div` 2

update::SegmentTree->Int->Int->SegmentTree
update Null _ _ = Null
update (Node Null Null l r value) p x | l <= p && p<=r = Node Null Null l r (value + x)
update (Node left right l r _) p x | l <= p && p<=r = Node newLeft newRight l r newValue
  where newLeft  = update left p x
        newRight = update right p x
        newValue = getValue newLeft + getValue newRight
update t _ _ = t

query::SegmentTree->Int->Int->Int
query Null _ _ = 0
query _ begin end | begin> end = 0
query (Node _ _ l r value) begin end | begin<=l && r<=end = value 
query (Node left right _ _ _) begin end = query left begin end + query right begin end

main::IO()
main =
  let
    t0 = build 1 10
    t1 = update t0 1 10
    t2 = update t1 2 4
 in putStrLn $ show $ query t2 1 10