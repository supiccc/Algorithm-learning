def valid(x)
	while x % 2 == 0
		x /= 2
	end
	while x % 3 == 0
		x /= 3
	end
	while x % 5 == 0
		x /= 5
	end
	if x == 1
		return true
	else
		return false
	end
end

def get(n)
	x = 1
	i = 0
	loop do 
		if valid(x)
			i += 1
			if i == n
				puts x
				break if i == n
			end
		end
		x += 1
	end
end

get(1500)