$graph = File.read("input.txt").split("\n")
$h = $graph.length
$w = $graph[0].length
$dp = Array.new($h) { Array.new($w, 0) }
$split_n = 0

def down(h)
  (0..$w - 1).each do |idx|
    dp = $dp[h][idx]
    next if dp == 0

    next_visit = $graph[h + 1][idx]
    if next_visit == "."
      $dp[h + 1][idx] += dp
    else
      $dp[h + 1][idx - 1] += dp
      $dp[h + 1][idx + 1] += dp
    end
  end
end

$dp[0][$graph[0].index("S")] = 1
(0..$h - 2).each(&method(:down))
puts $dp[$h - 1].sum
