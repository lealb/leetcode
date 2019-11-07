import jaydebeapi


def get_connect():
    url = 'jdbc:hive2:/master:10000/default'
    user = 'hadoop'
    password = 'hadoop'
    driver = 'org.apache.hive.jdbc.HiveDriver'
    hive_version, hadoop_version = '3.1.2', '3.1.2'
    jar_files = [
        'lib/hive/hive-jdbc-'+hive_version+'.jar',
        'lib/hive/hive-exec-'+hive_version+'.jar',
        'lib/hive/hive-metastore-'+hive_version+'.jar',
        'lib/hive/hive-service-'+hive_version+'.jar',
        'lib/hive/libfb303-0.9.3.jar',
        'lib/hive/commons-logging-1.0.4.jar',
        'lib/hive/slf4j-api-1.7.25.jar',
        'lib/hive/httpclient-4.5.2.jar',
        'lib/hive/httpcore-4.4.4.jar',
        'lib/hive/hadoop-common-'+hadoop_version+'.jar'
        # 'D:/Maven/org/slf4j/slf4j-simple/1.7.25/slf4j-simple-1.7.25.jar'
    ]

    sql_str = 'show databases;'
    try:
        conn = jaydebeapi.connect(driver, url, [user, password], jar_files)
        curs = conn.cursor()
        curs.execute(sql_str)
        result = curs.fetchall()
        print(result)
        curs.close()
        conn.close()
    except Exception as ex:
        print(ex)


if __name__ == "__main__":
    get_connect()
