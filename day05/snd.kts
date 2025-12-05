import java.io.File

val input = File("input.txt").readText().trim().split("\n\n")
var ranges =
    input[0]
        .lines()
        .map { it.split("-").map { it.toLong() } }
        .map { Pair(it[0], it[1]) }
        .sortedBy { it.first }

val merged = mutableListOf<Pair<Long, Long>>()
var prevEnd: Long = 0
for (i in 0 until ranges.size) {
    val (start, end) = ranges[i]
    if (start <= prevEnd) {
        val newEnd = maxOf(prevEnd, end)
        merged[merged.size - 1] = Pair(merged[merged.size - 1].first, newEnd)
        prevEnd = newEnd
    } else {
        merged.add(Pair(start, end))
        prevEnd = end
    }
}
merged.map { it.second - it.first + 1 }.sum()
