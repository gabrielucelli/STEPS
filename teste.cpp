for i=0 to n-1
  LS[i]=1
    for j=0 to i-1
      if (a[i] >  a[j] and LS[i]<LS[j])
        LS[i] = LS[j]+1

for i=0 to n-1
  if (largest < LS[i])
    largest = LS[i]
