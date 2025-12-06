import { readFileSync } from "fs";

const sum = (a: number, b: number) => a + b;
const prod = (a: number, b: number) => a * b;
const transpose = (d: string[]) => {
  const res: string[] = [];
  const len = d[0].length;
  for (let i = 0; i < len; i++) {
    res.push("");
    res[i] = d.map((row) => row[i]).join("");
    res[i] = res[i].trim();
  }
  return res;
};

const d = readFileSync("input.txt", "utf-8").split("\n").slice(0, -1);
const ops = d
  .at(-1)!
  .split(" ")
  .filter((s: string) => s.trim().length !== 0)
  .map((l: string) => l.trim());
const nums_d = d.slice(0, -1);
const nums_t = transpose(nums_d);
let idx = 0;
const nums: number[][] = [[]];
for (const str of nums_t)
  if (str === "") {
    idx++;
    nums.push([]);
  } else nums[idx].push(Number(str));

const res = ops.reduce((acc: number, op: string, i: number) => {
  const oper = op === "+" ? sum : prod;
  return (
    acc +
    nums[i].reduce((a: number, b: number) => oper(a, b), op === "+" ? 0 : 1)
  );
}, 0);
console.log(res);
