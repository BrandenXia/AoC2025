from operator import itemgetter, sub
from itertools import combinations
from networkx.utils.union_find import UnionFind

with open("input.txt") as f:
    cs = map(
        lambda line: tuple(map(int, line.split(","))), f.read().strip().split("\n")
    )
ds = lambda a, b: sum(map(lambda x: x**2, map(lambda z: sub(*z), zip(a, b))))
dists = {ds(a, b): (a, b) for a, b in combinations(cs, 2)}
uf = UnionFind()
last = (0, 0)
for d, (a, b) in sorted(dists.items(), key=itemgetter(0)):
    if uf[a] == uf[b]:
        continue
    uf.union(a, b)
    last = (a[0], b[0])
print(last[0] * last[1])
