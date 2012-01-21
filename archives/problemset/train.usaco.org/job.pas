{
ID: sujiao1
TASK: job
LANG: PASCAL
}
//我用PASCAL过的第一题!
program job;
var N,M1,M2:integer;
    T1,T2:array[1..30] of integer;
    S1,S2:array[1..30] of integer;
    f,g:array[1..1000] of integer;
    i,j:integer;
    minid,mint:integer;
    answer:integer;
begin
        assign(input,'job.in');
        assign(output,'job.out');
        reset(input);
        rewrite(output);
        readln(N,M1,M2);
        for i:=1 to M1 do read(T1[i]);
        for i:=1 to M2 do read(T2[i]);
        
        for i:=1 to M1 do S1[i]:=0;
        for i:=1 to M2 do S2[i]:=0;
        for i:=1 to N do
        begin
             minid:=0;
             for j:=1 to M1 do
                 if (minid=0)or(mint>S1[j]+T1[j]) then
                 begin
                      minid:=j;
                      mint:=S1[j]+T1[j];
                 end;
             inc(S1[minid],T1[minid]);
             f[i]:=mint;
             
             minid:=0;
             for j:=1 to M2 do
                 if (minid=0)or(mint>S2[j]+T2[j]) then
                 begin
                      minid:=j;
                      mint:=S2[j]+T2[j];
                 end;
             inc(S2[minid],T2[minid]);
             g[i]:=mint;
        end;
        answer:=0;
        for i:=1 to N do
            if f[i]+g[N+1-i]>answer then
               answer:=f[i]+g[N+1-i];
        writeln(f[N],' ',answer);
        close(input);
        close(output);
end.
