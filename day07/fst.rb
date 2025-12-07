$graph = File.read("input.txt").split("\n")
$h = $graph.length
$w = $graph[0].length
$split_n = 0

def down(loc)
  next_loc = [loc[0] + 1, loc[1]]
  
  return [] if next_loc[0] == $h

  visit = $graph[next_loc[0]][next_loc[1]]
  if visit == "."
    [next_loc]
  else
    $split_n += 1
    [->(loc) { [loc[0], loc[1] - 1] }, ->(loc) { [loc[0], loc[1] + 1] }].map { |f| f.call(next_loc) }
  end
end

locs = [[0, $graph[0].index("S")]]
while locs.length != 0
  locs = locs.flat_map { |l| down(l) }.uniq
end
puts $split_n
