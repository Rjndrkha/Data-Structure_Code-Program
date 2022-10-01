import java.time.LocalDate
import java.time.format.DateTimeFormatter

fun main(args: Array<String>) {
    // Format y-M-d or yyyy-MM-d
    val string = "2017-07-25"
    val date = LocalDate.parse(string, DateTimeFormatter.ISO_DATE)

    println(date)
}
