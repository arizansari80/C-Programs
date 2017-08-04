c=gets;
tc=c.to_i;
res=[];
i=0;
while i<tc do
	c=gets;
	d=c.split(" ");
	a=d[0].to_i;
	b=d[1].to_i;
	res[i]=a*b;
	i+=1;
end
i=0;
l=res.length;
while i<tc do
	puts res[i];
	i+=1;
end