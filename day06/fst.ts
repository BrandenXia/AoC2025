import { readFileSync } from "fs";

const sum = (a: number, b: number) => a + b;
const prod = (a: number, b: number) => a * b;

const d = readFileSync("input.txt", "utf-8").split("\n").slice(0, -1);
const nums = d.slice(0, -1).map((l: string) =>
  l
    .split(" ")
    .filter((s) => s.trim().length !== 0)
    .map(Number),
);
const ops = d
  .at(-1)!
  .split(" ")
  .filter((s: string) => s.trim().length !== 0)
  .map((l: string) => l.trim());

const res = ops.reduce((acc: number, op: string, i: number) => {
  const oper = op === "+" ? sum : prod;
  return (
    acc +
    nums.reduce((a: number, b: number) => oper(a, b[i]), op === "+" ? 0 : 1)
  );
}, 0);
console.log(res);
