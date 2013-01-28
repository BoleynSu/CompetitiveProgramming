program cao;
const
  maxn=200;
  bignum=maxlongint;
  eps=1e-10;
 
type
  Tpoint=record
    x,y:extended;
  end;
 
  Thalf_plane=record
    a,b,c:extended;
  end;
 
  THPI=object  //half plane intersection
    total,tot:longint;
    p,q:array[1..maxn] of Tpoint;
    procedure init;
    function intersect(u,v:Tpoint;tmp:Thalf_plane):Tpoint;
    procedure cut(tmp:Thalf_plane);
    function ok:boolean;
  end;
 
var
  t:THPI;
  a,b,c,d,e,f,g,h,i,j,k,l,n,m,p,q:longint;
  s1,s2,s3:array[0..maxn] of longint;
  tmp:Thalf_plane;
 
procedure THPI.init;
begin
  total:=4;
  p[1].x:=0;
  p[1].y:=0;
  p[2].x:=bignum;
  p[2].y:=0;
  p[3].x:=bignum;
  p[3].y:=bignum;
  p[4].x:=0;
  p[4].y:=bignum;
end;
 
function THPI.intersect(u,v:Tpoint;tmp:Thalf_plane):Tpoint;
var
  ans:Tpoint;
  t1,t2,delta:extended;
begin
  t1:=tmp.a*u.x+tmp.b*u.y+tmp.c;
  t2:=tmp.a*v.x+tmp.b*v.y+tmp.c;
  delta:=-t1/t2;
  ans.x:=(u.x+delta*v.x)/(1+delta);
  ans.y:=(u.y+delta*v.y)/(1+delta);
  exit(ans);
end;
 
procedure THPI.cut(tmp:Thalf_plane);
var
  i,j:longint;
begin
  tot:=0;
  if (abs(tmp.a)<eps)and(abs(tmp.b)<eps)and(tmp.c>=-eps) then
  begin
    total:=0;
    exit;
  end;
  for i:=1 to total do
  begin
    if tmp.a*p[i].x+tmp.b*p[i].y+tmp.c<eps then
    begin
      inc(tot);
      q[tot]:=p[i];
    end
    else
    begin
      j:=i-1;
      if j<=0 then j:=total;
      if tmp.a*p[j].x+tmp.b*p[j].y+tmp.c<-eps then
      begin
        inc(tot);
        q[tot]:=intersect(p[j],p[i],tmp);
      end;
      j:=i+1;
      if j>total then j:=1;
      if tmp.a*p[j].x+tmp.b*p[j].y+tmp.c<-eps then
      begin
        inc(tot);
        q[tot]:=intersect(p[i],p[j],tmp);
      end;
    end;
  end;
  total:=tot;
  move(q[1],p[1],sizeof(Tpoint)*tot);
end;
 
function THPI.ok:boolean;
begin
  exit(total>=3);
end;
 
procedure init;
begin
  read(n);
  for i:=1 to n do
    read(s1[i],s2[i],s3[i]);
end;
 
procedure main;
begin
  for i:=1 to n do
  begin
    t.init;
    for j:=1 to n do
      if i<>j then
      begin
        tmp.a:=1/s1[i]-1/s1[j];
        tmp.b:=1/s2[i]-1/s2[j];
        tmp.c:=1/s3[i]-1/s3[j];
        t.cut(tmp);
        if t.ok=false then break;
      end;
    if t.ok then writeln('Yes') else writeln('No');
  end;
end;
 
begin
  init;
  main;
end.