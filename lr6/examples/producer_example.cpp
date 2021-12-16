#include <stdexcept>
#include <iostream>
#include <string>
#include <cstdlib>
#include <boost/program_options.hpp>
#include <chrono>
#include <thread>
#include "cppkafka/producer.h"
#include "cppkafka/configuration.h"

using std::string;
using std::exception;
using std::getline;
using std::cin;
using std::cout;
using std::endl;

using cppkafka::Producer;
using cppkafka::Configuration;
using cppkafka::Topic;
using cppkafka::MessageBuilder;

namespace po = boost::program_options;

int main(int argc, char* argv[]) {
    string brokers = "127.0.0.1:9092";
    string topic_name = "first_topic"; 
    int partition_value = -1;

    // Create a message builder for this topic
    MessageBuilder builder(topic_name);

    // Get the partition we want to write to. If no partition is provided, this will be
    // an unassigned one
    if (partition_value != -1) {
        builder.partition(partition_value);
    }

    // Construct the configuration
    Configuration config = {
        { "metadata.broker.list", brokers }
    };

    // Create the producer
    Producer producer(config);

    cout << "Producing messages into topic " << topic_name << endl;

    string line;
    int digit = 0;
    while (digit < 15) {
        // Set the payload on this builder
        digit++;
        line = boost::lexical_cast<string>(digit);
        std::chrono::duration<int, std::milli> timespan(1000);
        std::this_thread::sleep_for(timespan);
        builder.payload(line);
        cout << "sending: " << line << endl;
        // Actually produce the message we've built
        producer.produce(builder);
    }
    
    // Flush all produced messages
    producer.flush();
}
