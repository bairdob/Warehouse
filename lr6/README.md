## Лабораторная работа 6

- Поставить kafka
- Скомпилирует
- Создать топик послать сообщение из producer и принять в consumer
- Написать приложение producer, которое будет посылать сообщения с изменяющимися целыми числам
- Написать приложение comsumer, которое будет принимать сообщения и выдавать их на экран

## Создание топика
 ```
kafka-topics --create --bootstrap-server localhost:9092 --replication-factor 1 --partitions 1 --topic first_topic
 ```

## Компиляция
 ```
 mkdir build
 cd build
 cmake ..
 make examples
 ```

## Kafka result

<img src="/pic/kafkaResult.gif" width=50% height=50%>


