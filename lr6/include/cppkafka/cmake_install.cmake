# Install script for directory: /Users/bair/lr6/include/cppkafka

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Library/Developer/CommandLineTools/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xHeadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cppkafka" TYPE FILE FILES
    "/Users/bair/lr6/include/cppkafka/buffer.h"
    "/Users/bair/lr6/include/cppkafka/clonable_ptr.h"
    "/Users/bair/lr6/include/cppkafka/configuration.h"
    "/Users/bair/lr6/include/cppkafka/configuration_base.h"
    "/Users/bair/lr6/include/cppkafka/configuration_option.h"
    "/Users/bair/lr6/include/cppkafka/consumer.h"
    "/Users/bair/lr6/include/cppkafka/cppkafka.h"
    "/Users/bair/lr6/include/cppkafka/error.h"
    "/Users/bair/lr6/include/cppkafka/event.h"
    "/Users/bair/lr6/include/cppkafka/exceptions.h"
    "/Users/bair/lr6/include/cppkafka/group_information.h"
    "/Users/bair/lr6/include/cppkafka/header.h"
    "/Users/bair/lr6/include/cppkafka/header_list.h"
    "/Users/bair/lr6/include/cppkafka/header_list_iterator.h"
    "/Users/bair/lr6/include/cppkafka/kafka_handle_base.h"
    "/Users/bair/lr6/include/cppkafka/logging.h"
    "/Users/bair/lr6/include/cppkafka/macros.h"
    "/Users/bair/lr6/include/cppkafka/message.h"
    "/Users/bair/lr6/include/cppkafka/message_builder.h"
    "/Users/bair/lr6/include/cppkafka/message_internal.h"
    "/Users/bair/lr6/include/cppkafka/message_timestamp.h"
    "/Users/bair/lr6/include/cppkafka/metadata.h"
    "/Users/bair/lr6/include/cppkafka/producer.h"
    "/Users/bair/lr6/include/cppkafka/queue.h"
    "/Users/bair/lr6/include/cppkafka/topic.h"
    "/Users/bair/lr6/include/cppkafka/topic_configuration.h"
    "/Users/bair/lr6/include/cppkafka/topic_partition.h"
    "/Users/bair/lr6/include/cppkafka/topic_partition_list.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xHeadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cppkafka/utils" TYPE FILE FILES
    "/Users/bair/lr6/include/cppkafka/utils/backoff_committer.h"
    "/Users/bair/lr6/include/cppkafka/utils/backoff_performer.h"
    "/Users/bair/lr6/include/cppkafka/utils/buffered_producer.h"
    "/Users/bair/lr6/include/cppkafka/utils/compacted_topic_processor.h"
    "/Users/bair/lr6/include/cppkafka/utils/consumer_dispatcher.h"
    "/Users/bair/lr6/include/cppkafka/utils/poll_interface.h"
    "/Users/bair/lr6/include/cppkafka/utils/poll_strategy_base.h"
    "/Users/bair/lr6/include/cppkafka/utils/roundrobin_poll_strategy.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xHeadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cppkafka/detail" TYPE FILE FILES
    "/Users/bair/lr6/include/cppkafka/detail/callback_invoker.h"
    "/Users/bair/lr6/include/cppkafka/detail/endianness.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xHeadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cppkafka" TYPE FILE FILES "/Users/bair/lr6/include/cppkafka/cppkafka.h")
endif()

