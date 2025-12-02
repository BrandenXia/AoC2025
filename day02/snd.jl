open("input.txt") do f
  input = read(f, String) |> strip
  global rs = split(input, ",") .|> (x -> split(x, "-") .|> x -> parse(Int, x))
end

check = x -> occursin(r"^(\d+)\1+$", string(x))
checkr = (a, b) -> [i for i=a:b + 1 if check(i)]

println([e for r in rs for e in checkr(r[1], r[2])] |> sum)
