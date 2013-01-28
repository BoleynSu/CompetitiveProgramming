<?php
fscanf(STDIN,"%d",$n);
$a=array();
$ans=0;
foreach (range(1,$n) as $i)
{
    fscanf(STDIN,"%d%d%d",$x,$y,$z);
    if ($x+$y+$z>=2) $ans++;
}
fprintf(STDOUT,"%d\n",$ans);
?>
