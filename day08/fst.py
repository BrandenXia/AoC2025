from functools import reduce
from operator import itemgetter, sub, mul
from itertools import combinations
from networkx.utils.union_find import UnionFind

LIMIT = 1000
with open("input.txt") as f:
    cs = map(
        lambda line: tuple(map(int, line.split(","))), f.read().strip().split("\n")
    )
ds = lambda a, b: sum(map(lambda x: x**2, map(lambda z: sub(*z), zip(a, b))))
dists = {ds(a, b): (a, b) for a, b in combinations(cs, 2)}
uf = UnionFind()
for d, (a, b) in sorted(dists.items(), key=itemgetter(0))[:LIMIT]:
    uf.union(a, b)
print(reduce(mul, sorted(map(len, uf.to_sets()), reverse=True)[:3], 1))
