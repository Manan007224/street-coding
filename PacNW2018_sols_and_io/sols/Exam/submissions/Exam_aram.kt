import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val fr_score = nextInt()
    val my_ans = next()
    val fr_ans = next()
    val N = my_ans.length
    val agree = my_ans.zip(fr_ans).filter{ (my, fr) -> my == fr }.count()
    
    val my_score = minOf(fr_score, agree) + minOf(N - fr_score, N - agree)
    println(my_score)
}
