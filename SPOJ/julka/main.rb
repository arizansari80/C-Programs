i=0;
c=[]
while i<20 do
	c[i]=gets;
	c[i+1]=gets;
	i+=2;
end
res1=0;
res2=0;
i=0;
while i<20 do
	c[i]=c[i].to_i;
	c[i+1]=c[i+1].to_i;
	res1=(c[i]+c[i+1])/2;
	res2=(c[i]-c[i+1])/2;
	i+=2;
	puts res1;
	puts res2;
end