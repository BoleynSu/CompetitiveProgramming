
toList::[Int]->[(Int,Int)]
toList [] = []
toList (a:b:c) = (a,b):(toList c)

getAns::[(Int,Int)]->(Int,Int)
getAns lst =
 let
  getAns'::[(Int,Int)]->Int->Int->Int->(Int,Int)
  getAns' [] unfinishedTask currentTime maxTask = (currentTime+unfinishedTask,maxTask)
  getAns' ((t,c):xs) unfinishedTask currentTime maxTask =
   if t==currentTime
    then getAns' xs (unfinishedTask+c) currentTime (max maxTask (unfinishedTask+c))
    else getAns' ((t,c):xs) (max (unfinishedTask-t+currentTime) 0) t maxTask
 in getAns' lst 0 0 0

main::IO()
main =
 do
 input <- getContents
 let
  numbers = map read (words input)::[Int]
  ans = getAns $ toList $ tail numbers
 putStr $ show $ fst ans
 putStr " "
 putStr $ show $ snd ans
 putStr "\n"

