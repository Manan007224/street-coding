import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val N = nextInt()
    val claims = Array(N) { Pair(nextInt(), nextInt()) }
                      
    val truths = (0..N).map{ claims.filter{ (a, b) -> a <= it && it <= b }.count() }
    val max_truths = truths.filterIndexed{ i, t -> i == t }.max() ?: -1
    
    println(max_truths)
}
