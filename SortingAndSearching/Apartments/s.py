# 4 3 5
# 60 45 80 60
# 30 60 75

n,m,k=list(map(int,input().split()))
desiredAppartmentSize=list(map(int,input().split()))
sizeAppartment=list(map(int,input().split()))
desiredAppartmentSize.sort()
sizeAppartment.sort()
print(sizeAppartment)
print(desiredAppartmentSize)
c = 0
for i in range(len(sizeAppartment)):
	for j in range(c, len(desiredAppartmentSize)):
		if sizeAppartment[i]-k <= desiredAppartmentSize[j] and desiredAppartmentSize[j] <= sizeAppartment[i]+k:
			print(i, j)
			print(desiredAppartmentSize[j])
			c += 1
			break
print(c)