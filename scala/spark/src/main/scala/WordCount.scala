import org.apache.spark.sql.SparkSession

object WordCount {
  def main(args: Array[String]) {
    val spark = SparkSession.builder
      .appName("WordCount")
      .master("local[*]")
      .getOrCreate
    spark.sparkContext
      .textFile("D:/data/test.txt")
      .flatMap(_.split(" "))
      .filter(_ != " ")
      .map((_, 1))
      .reduceByKey(_ + _)
      .collect
      .foreach(println)
    spark.stop
  }
}
