<?php
$line=explode(" ",fgets(STDIN));
$n=(int)$line[0];
$k=(int)$line[1];
$a=array();
$line=explode(" ",fgets(STDIN));
foreach ($line as $number) $a[count($a)]=(int)$number;
sort($a);
$j=0;
$ans=0;
$ansn=0;
$used=0;
for ($i=0;$i<$n;$i++)
{
	$used+=($i-$j)*($i?$a[$i]-$a[$i-1]:0);
	while ($used>$k)
	{
		$used-=$a[$i]-$a[$j];
		$j++;
	}
	if ($i-$j+1>$ans)
	{
		$ans=$i-$j+1;
		$ansn=$a[$i];
	}
}
echo "$ans $ansn";
?>
