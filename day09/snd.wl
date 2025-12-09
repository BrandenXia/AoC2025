#!/usr/bin/env wolframscript

input = Import["input.txt", "Text"];
input = ToExpression /@ StringSplit[#, ","] & /@ StringSplit[input, "\n"];
calcSize = 
  Compile[{{p1, _Real, 1}, {p2, _Real, 
     1}}, (Abs[p1[[1]] - p2[[1]]] + 1)*(Abs[p1[[2]] - p2[[2]]] + 1), 
   RuntimeAttributes -> {Listable}, Parallelization -> True];
shape = BoundaryDiscretizeRegion[Polygon[input]];
pairs = Subsets[input, {2}];
sizes = calcSize[pairs[[All, 1]], pairs[[All, 2]]];
sorted = Ordering[sizes, All, Greater];
largestSize = Catch[Do[idx = sorted[[i]];
    candidateRect = Rectangle @@ pairs[[idx]];
    If[RegionWithin[shape, candidateRect], Throw[sizes[[idx]]]], {i, 
     Length[sortedIndices]}]];
Print[IntegerPart[largestSize]]
