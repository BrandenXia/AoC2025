#!/usr/bin/env wolframscript

input = Import["input.txt", "Text"];
input = ToExpression /@ StringSplit[#, ","] & /@ StringSplit[input, "\n"];
CalcSize = Apply[Times, Abs[#] + 1 & /@ (#[[1]] - #[[2]])] &;
pair = MaximalBy[Subsets[input, {2}], CalcSize];
Print[CalcSize[pair[[1]]]];
