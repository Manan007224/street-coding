import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val MAX_N = 300000
    val N = nextInt()
    val C = nextInt()
    // It seems the map function is necessary here,
    // and Kotlin Pairs don't implement Comparable...
    var registers = TreeSet((1..N).map{it.toLong()})
    
    for (i in 1..C) {
        val t = registers.first()
        registers.remove(t)
        registers.add(t + nextLong() * MAX_N)
        if (i != 1)
           print(" ") ;
        print(t % MAX_N)
    }
    println() ;
}
