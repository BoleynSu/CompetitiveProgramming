
p1 = sum [x|x<-[0..1000-1],x `mod` 3==0 || x `mod` 5==0]

p2 = sum [x|x<-takeWhile (<=4000000) numbers,even x]
  where numbers = 1:2:zipWith (+) numbers (tail numbers)

p3 = last [x|x<-takeWhile (\x-> x*x <= 600851475143) primes,600851475143 `mod` x ==0]
  where primes = 2:[x|x<-[3..],null [z|z<-takeWhile (\y-> y*y <= x) primes,x `mod` z ==0]]

p4 = maximum [x*y|x<-[100..999],y<-[100..999],let z=show $ x*y in z == reverse z]

p5 = foldr1 lcm [1..20]

p6 = let y=sum [1..100] in y*y - sum [x*x|x<-[1..100]]

main = print p6
