def factorial n
	if $save[n]!=0
		return $save[n]
	end
    if n==1
        return 1
    end
    return n*factorial(n-1)
end

$save=Array.new(100,0)
tcs=gets
tc=tcs.to_i
i=0
arr=[]
while i<tc do
    s=gets
    n=s.to_i
	m=n
    arr[i]=factorial(n)
	$save[m]=arr[i]
	i+=1
end
i=0
while i<tc do
    puts arr[i]
	i+=1
end
i=0
while i<100 do
	if $save[i]!=0
		k=i.to_s
		l=$save[i].to_s
		p=k+" "+l
		puts p
	end
	i+=1
end
