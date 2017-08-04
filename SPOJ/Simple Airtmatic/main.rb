puts "Enter the string";
s=gets;
arr=[];
arr=s.split('+');
a=arr[0].to_i;
b=arr[1].to_i;
c=a+b;
s=c.to_s;
l0=arr[0].length;
l1=arr[1].length-1;
lr=s.length;
temp="";
dash="";
i=0;
while i<lr do
	dash+="-";
	i+=1;
end
if l0==l1
	if lr==l1
		puts " " + arr[0];
		puts "+" + arr[1];
		puts "-" + dash;
		puts " " + s;
		puts "-" + dash;
	else
		puts " " + arr[0];
		puts "+" + arr[1];
		puts dash;
		puts s;
		puts dash;
	end
elsif l0<l1
	i=l0;
	while i<l1 do
		temp+=" ";
		i+=1;
	end
	if lr==l1
		puts " " + temp + arr[0];
		puts "+" + arr[1];
		puts "-" + dash;
		puts " " + s;
		puts "-" + dash;
	else
		puts " " + temp + arr[0];
		puts "+" + arr[1];
		puts dash;
		puts s;
		puts dash;
	end
else
	i=l1;
	while i<l0 do
		temp+=" ";
		i+=1;
	end
	if lr==l0
		puts " " + arr[0];
		puts "+" + temp + arr[1];
		puts "-" + dash;
		puts " " + s;
		puts "-" + dash;
	else
		puts " " + arr[0];
		puts "+" + temp + arr[1];
		puts dash;
		puts s;
		puts dash;
	end
end