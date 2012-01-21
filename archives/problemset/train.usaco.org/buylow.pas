{
ID: sujiao1
TASK: buylow
LANG: PASCAL
}
program buylow;
const MAXN=5000+1;
const K=100000000;
const MAXLEN=100;
const oo=1024*1024*1024;
type bigNum=array[1..MAXLEN] of longint;
var n:longint;
    i,j,get:longint;
    maxday:longint;
    p,f:array[1..MAXN] of longint;
    g:array[1..MAXN] of bigNum;
function max(a,b:longint):longint;
begin
     if a>b then
       max:=a
     else
         max:=b;
end;
procedure big_set(var num:bigNum;value:longint);
var i:longint;
begin
     num[1]:=value;
end;
procedure big_inc(var a,b:bigNum);
var i:longint;
begin
     for i:=1 to MAXLEN-1 do
     begin
          inc(a[i+1],(a[i]+b[i]) div K);
          a[i]:=(a[i]+b[i]) mod K;
     end;
end;
procedure big_print(var num:bigNum);
var i,j,t:longint;
begin
     j:=1;
     for i:=MAXLEN downto 2 do
         if num[i]<>0 then
         begin
              j:=i;
              break;
         end;
     write(num[j]);
     for i:=j-1 downto 1 do
     begin
          t:=K div 10;
          while t>0 do
          begin
               write((num[i] div t) mod 10);
               t:=t div 10;
          end;
     end;
     writeln;
end;
begin
        assign(input,'buylow.in');
        assign(output,'buylow.out');
        reset(input);
        rewrite(output);
        readln(n);
        {writeln(n);}
        for i:=1 to n do
            read(p[i]);
        {for i:=1 to n do
            writeln(p[i]);}
        for i:=1 to n do f[i]:=1;
        for i:=1 to n do
            for j:=1 to i do
                if p[j]>p[i] then
                   f[i]:=max(f[i],f[j]+1);
        maxday:=0;
        for i:=1 to n do maxday:=max(maxday,f[i]);
        write(maxday,' ');
        inc(n);
        f[n]:=maxday+1;
        p[n]:=0;
        for i:=1 to n do
        begin
             if f[i]=1 then
                big_set(g[i],1)
             else
             begin
                  get:=oo;
                  for j:=i-1 downto 1 do
                      if (f[j]=f[i]-1) and (p[j]<get) and (p[j]>p[i]) then
                      begin
                           get:=p[j];
                           big_inc(g[i],g[j]);
                      end;
             end;
        end;
        big_print(g[n]);
        close(input);
        close(output);
end.
