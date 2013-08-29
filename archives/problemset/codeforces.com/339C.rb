@s = '0'+gets.strip
@m = gets.to_i
@calced = []
@f = []
for i in 0..10 do
  @calced[i]=[]
  @f[i]=[]
  for j in 0..@m do
    @calced[i][j]=[]
    @f[i][j] = []
  end
end

def dp(delta,step,last)
  if !@calced[delta][step][last]
    @calced[delta][step][last]=true
    @f[delta][step][last]=false
    if step==@m
      @f[delta][step][last]=true
    else
      for i in delta+1..10 do
        if i!=last && @s[i]=='1' && dp(i-delta,step+1,i)
          @f[delta][step][last]=true
          break
        end
      end
    end
  end
  return @f[delta][step][last]
end

def show(delta,step,last)
  if step==@m
    puts last
  else
    if step==0
      puts 'YES'
    else
      print last,' '
    end
    for i in delta+1..10 do
      if i!=last && @s[i]=='1' && dp(i-delta,step+1,i)
        show(i-delta,step+1,i)
        break
      end
    end
  end
end

if !dp(0,0,0)
  puts 'NO'
else
  show(0,0,0)
end
