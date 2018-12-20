import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val num_cards = 5
    val cards = Array(num_cards) { next()[0] }
    
    val counts = cards.groupingBy{ it }.eachCount()
    val strength = counts.map{ it.value }.max() ?: 0
    
    println(strength)
}
