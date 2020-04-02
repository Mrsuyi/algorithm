# templates

## bit
+ Get last "1" of n
```
n = k & -k;
```

+ Remove last "1" from n
```
n = k & (k - 1);
```

+ Traverse subsets of k (e.g. k=5 -> {101, 100, 001})
```
for (int i = k; i; i = (i - 1) & k) {}
```
