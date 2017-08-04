puts "Enter the string";
r=gets;
$arr=r.split("*");
a=$arr[0].to_i;
b=$arr[1].to_i;

c=$arr[1].split("");
r=a*b;
r=r.to_s;
$dash="";
$dashtemp="";
l0=$arr[0].length;
l1=$arr[1].length-1;
$lr=r.length;
if l0>=l1
	i=0;
	while i<l0 do
		$dash+="-";
		i+=1;
	end
	if l0==l1
		$dash+="-";
	end
else
	i=0;
	while i<l1 do
		$dash+="-";
		i+=1;
	end
	$dash+="-";
end
ld=$dash.length;
$temp0="";
$temp1="";
i=l0;
while i<$lr do
	$temp0+=" ";
	i+=1;
end
i=l1;
while i<$lr-1 do
	$temp1+=" ";
	i+=1;
end
ld=$dash.length;
i=ld;
while i<$lr do
	$dashtemp+=" ";
	i+=1;
end
$temp1+="*";
puts $temp0 + $arr[0];
puts $temp1 + $arr[1];
puts $dashtemp + $dash;
i=0;
while i<l1 do
	$temp0="";
	t=c[l1-i-1].to_i;
	k=t*a;
	k=k.to_s;
	lk=k.length;
	j=lk;
	while j<$lr-i do
		$temp0+=" ";
		j+=1;
	end
	puts $temp0 + k;
	i+=1;
end
$dash="";
i=0;
while i<$lr do
	$dash+="-"
	i+=1;
end
puts $dash;
puts r;