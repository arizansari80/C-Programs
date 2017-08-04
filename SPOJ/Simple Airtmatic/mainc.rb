def display l
	i=$lr;
	rp="";
	while i<$max do
		rp+=" ";
		i+=1;
	end
	puts $temp0 + $arr[0];
	puts $temp1 + $arr[1];
	puts $dash;
	puts rp + $s;
end

def displaym
	puts $temp0 + $arr[0];
	puts $temp1 + $arr[1];
	puts $dash;
	puts $tempr + $s;
end

def dash_builder l
	i=0;
	while i<l do
		$dash+="-";
		i+=1;
	end
end

def sum s1,a,b
	c=a+b;
	$s=c.to_s;
	$arr[1]="+" + $arr[1];
	l0=$arr[0].length;
	l1=$arr[1].length-1;
	$lr=$s.length;
	$max=0;
	if l0>l1
		if l0>$lr
			$max=l0
		else
			$max=$lr;
		end
	else
		if l1>$lr
			$max=l1;
		else
			$max=$lr;
		end
	end
	dash_builder($max);
	if l0==l1
		$temp0+=" ";
		display(l0);
	elsif l0<l1
		i=l0;
		while i<$max do
			$temp0+=" ";
			i+=1;
		end
		display(l1);
	else
		i=l1;
		while i<$max do
			$temp1+=" ";
			i+=1;
		end
		display(l0);
	end
end

def subt s1,a,b
	c=a-b;
	$s=c.to_s;
	$arr[1]="-" + $arr[1];
	l0=$arr[0].length;
	l1=$arr[1].length-1;
	$lr=$s.length;
	$max=0;
	if l0>l1
		$max=l0;
	else
		$max=l1;
	end
	dash_builder($max);
	$tempr="";
	i=l0;
	while i<$max do
		$temp0+=" ";
		i+=1;
	end
	i=l1;
	while i<$max do
		$temp1+=" ";
		i+=1;
	end
	i=$lr;
	while i<$max do
		$tempr+=" ";
		i+=1;
	end
	displaym();
end

def mult s1,a,b
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
	if l1!=1
		$dash="";
		i=0;
		while i<$lr do
			$dash+="-"
			i+=1;
		end
		puts $dash;
		puts r;
	end
end

tc=gets;
tc=tc.to_i;
z=0;
s1=[];
while z<tc do
	s1[z]=gets;
	z+=1;
end
z=0;
while z<tc do
	$arr=[];
	$temp0="";
	$temp1="";
	$dash="";
	if s1[z].index("+")!=nil
		$arr=s1[z].split('+');
		a=$arr[0].to_i;
		b=$arr[1].to_i;
		sum(s1[z],a,b);
	elsif s1[z].index("-")!=nil
		$arr=s1[z].split('-');
		a=$arr[0].to_i;
		b=$arr[1].to_i;
		subt(s1[z],a,b);
	else
		$arr=s1[z].split('*');
		a=$arr[0].to_i;
		b=$arr[1].to_i;
		mult(s1[z],a,b);
	end
	puts "";
	z+=1;
end