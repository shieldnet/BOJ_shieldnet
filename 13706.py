import decimal.Decimal

n = input()
n = int(n)
l=int(1)
r=''
for i in range(0,800):
    r+='9'
l=Decimal(0)
r=Decimal(r)

while l<r:
    m=(l+r)/2
    if m*m == n:
        print(m)
        exit(0)
    elif m*m<n:
        l=m+1
    else:
        r=m-1