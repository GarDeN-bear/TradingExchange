CMAKE_MINIMUM_REQUIRED(VERSION 3.21)
PROJECT(ClienServerEcn)

ADD_SUBDIRECTORY(client)

ADD_SUBDIRECTORY(server)

ADD_CUSTOM_TARGET(copy_shared_resources
    COMMAND ${CMAKE_COMMAND} -E make_directory $ENV{HOME}/trading_exchange/resources/configs

    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/configs/config.json $ENV{HOME}/trading_exchange/resources/configs
)

ADD_CUSTOM_TARGET(run_project
    DEPENDS copy_shared_resources
    COMMAND bash ${CMAKE_SOURCE_DIR}/run.sh
        ${CMAKE_SOURCE_DIR} $<TARGET_FILE:server>
        ${CMAKE_SOURCE_DIR} $<TARGET_FILE:client>
)

ADD_CUSTOM_TARGET(run_client
    COMMAND bash ${CMAKE_SOURCE_DIR}/run.sh
        ${CMAKE_SOURCE_DIR} $<TARGET_FILE:client>
)

ADD_CUSTOM_TARGET(run_server
    DEPENDS copy_shared_resources
    COMMAND bash ${CMAKE_SOURCE_DIR}/run.sh
        ${CMAKE_SOURCE_DIR} $<TARGET_FILE:server>
)