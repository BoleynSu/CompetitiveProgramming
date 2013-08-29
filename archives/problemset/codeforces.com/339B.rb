def get_i
  return gets.split(' ').map(&:to_i)
end
n,m=get_i
a=get_i.unshift(1)
ans=0
for i in 1..m do
  ans+=(a[i]-a[i-1]+n)%n
end
puts ans
