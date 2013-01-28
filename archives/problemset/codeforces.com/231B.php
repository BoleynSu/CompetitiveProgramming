<?php
fscanf(STDIN,"%d%d%d",$n,$d,$l);
$max=0;
$min=0;
for ($i=1;$i<=$n;$i++)
{
    if ($i&1)
    {
        $max+=$l;
        $min+=1;
    }
    else
    {
        $max-=1;
        $min-=$l;
    }
}
if ($d<$min||$d>$max) printf("%d\n",-1);
else
{
    for ($i=1;$i<=$n;$i++)
    {
        if ($i&1)
        {
            $max-=$l;
            $min-=1;
        }
        else
        {
            $max+=1;
            $min+=$l;
        }
        $out=0;
        for ($j=1;$j<=$l;$j++)
        {
            if ($i&1)
            {
                if ($min<=$d-$j&&$d-$j<=$max) $out=$j;
            }
            else
            {
                if ($min<=$d+$j&&$d+$j<=$max) $out=-$j;             
            }
        }
        $d-=$out;
        printf("%d%s",abs($out),$i==$n?"\n":" ");
    }
}
?>
