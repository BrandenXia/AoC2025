import java.io.File

val input = File("input.txt").readText().trim().split("\n\n")
val ranges =
    input[0]
        .lines()
        .map { it.split("-").map { it.toLong() } }
        .map { Pair(it[0], it[1]) }
val nums = input[1].lines().map { it.toLong() }
nums.count { n -> ranges.any { n in it.first..it.second } }
