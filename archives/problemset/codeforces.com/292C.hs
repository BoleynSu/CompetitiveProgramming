
import Data.List

main::IO()
main =
 do
 input <- getContents
 let
  (n:an) = map read (words input)::[Int]
 if n>6
  then print (0::Int)
  else
   let
    string = [filter (\t->((length $ group $ sort t)==n)) [[x,y,z,u,v,w],[x,y,z,u,v],[x,y,z,u],[x,y,z],[x,y]] |x<-an,y<-an,z<-an,u<-an,v<-an,w<-an]
    
    getAns::[[[Int]]]->[(Int,Int,Int,Int)]->[(Int,Int,Int,Int)]
    getAns [] ans = ans
    getAns (x:xs) ans =
     getAns xs (getAns' x ans)
    
    getAns'::[[Int]]->[(Int,Int,Int,Int)]->[(Int,Int,Int,Int)]
    getAns' [] ans = ans
    getAns' (x:xs) ans =
     getAns' xs (getAns'' (x++(reverse x)) (getAns'' (x++(tail $ reverse x)) ans))
    
    getAns''::[Int]->[(Int,Int,Int,Int)]->[(Int,Int,Int,Int)]  
    getAns'' x ans =
     [get i j k|i<-[1..l-1],j<-[i+1..l-1],k<-[j+1..l-1],0+1==i||(x!!0)/=0,i+1==j||(x!!i)/=0,j+1==k||(x!!j)/=0,k+1==l||(x!!k)/=0,check i j k]++ans
     where
      l=length x
      get i j k =
       (a,b,c,d)
       where
        a = func (take i x) 0
        b = func (drop i (take j x)) 0
        c = func (drop j (take k x)) 0
        d = func (drop k x) 0
        func [] t = t
        func (y:ys) t = func ys (t*10+y)
      check i j k =
       a<256&&b<256&&c<256&&d<256
       where
        a = func (take i x) 0
        b = func (drop i (take j x)) 0
        c = func (drop j (take k x)) 0
        d = func (drop k x) 0
        func [] t = t
        func (y:ys) t = func ys (t*10+y)
    _ans = map head (group $ sort $ getAns string [])
    printAll::[(Int,Int,Int,Int)]->IO()
    printAll [] = return ()
    printAll ((a,b,c,d):xs) =
     do
      putStr $ show a
      putStr "."
      putStr $ show b
      putStr "."
      putStr $ show c
      putStr "."
      putStr $ show d
      putStr "\n"
      printAll xs
   in
    do
     print $ length _ans
     printAll _ans
  
