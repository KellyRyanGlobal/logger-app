# Introduction

This is a fork version of https://github.com/elanthis/easylogger. Modifications are made for simple testing purpose of running basic testing functionality within a jenkins environment.

Some of the modifications will not have to do with the logger itself, but test out things such as:
- System calls
- User input
- Opening applications

The logging will help provide information based on these events occurring.

Testing that will be performed include
- **Functional testing**- verifying the application is working as intended based predefined circumstance
   - Positive and negative- Testing based on assertions of input 
- **Acceptance testing**- Verifying the output of logic is what is expectec based on requirements
  - Verifying logic is correct

# Logger

All classes reside in the `easylogger` namespace.

There is only one primary class that the user must be aware of, which is
the `Logger` class.  Objects of `Logger` are used along with a set of
macros to perform all logging.

To create a new log, create a `Logger` object with a log name.

	easylogger::Logger NETWORK("NETWORK");

You can then write message to the `NETWORK` log using one of `LOG_TRACE`,
`LOG_DEBUG`, `LOG_INFO`, `LOG_WARNING`, `LOG_ERROR`, or `LOG_FATAL`.

	LOG_TRACE(NETWORK, "Trace message to NETWORK log");
	LOG_WARNING(NETWORK, "Warning message to NETWORK log");

You can inherit logs from each other, creating a hierarchy.  Pass the parent
log as the second argument to the `Logger` constructor.

	easylogger::Logger CONNECT("NETWORK.CONNECT", NETWORK);

	LOG_INFO(CONNECT, "Connection received");

Inherited logs will cause all messages to be sent to the parent log.  This
is useful for classification of logs, as well as allowing some logs to be
directed to alternative output streams.

A `Logger` instance with no parent by default will log all messages to
`std::cerr`.  `Logger` instances with a parent have no associated stream by
default.

You can set the associated stream on a `Logger` instance using the
`Logger::Stream(std::ostream&)` method.  Any `std::ostream` derivative is
acceptable.

	std::ofstream network_log("network.log");
	NETWORK.Stream(network_log);

	std::ofstream connect_log("connect.log");
	CONNECT.Stream(connect_log);

With the above example, all network log messages will be written to
`network.log`.  Additionally, any logs on the `CONNECT` log will also be
written to `connect.log`.

Each log has a minimum log level.  Only messages of that level or higher
will be processed.  The default log level is INFO.  This can be changed
by using the `Logger::Level(LogLevel)` method, giving it one of
`LEVEL_TRACE`, `LEVEL_DEBUG`, `LEVEL_INFO`, `LEVEL_WARNING`, `LEVEL_ERROR`,
or `LEVEL_FATAL`.

	NETWORK.Level(easylogger::LEVEL_DEBUG);

Logging any message with the level FATAL will cause the application to
abort immediately via `std::abort()`.

Finally, there is a set of assertion macros that can be used for checking
invariants.

	easylogger::Logger MAIN("MAIN");

	EASY_ASSERT(MAIN, param > 42, "param must be more than 42");
	ASSERT_EQ(MAIN, left, right, "left must be equal to right");
	ASSERT_NE(MAIN, left, right, "left must not equal right");
	ASSERT_TRUE(MAIN, param, "param must be true");
	ASSERT_FALSE(MAIN, param, "param must be false");
## Build logger
To build logger run the following command
1. `make`
2. Verify the test-bin is created
3. Run the following command
   1. g++ test.cc -o test.exe


# Jenkins Docker image setup
Reference https://www.jenkins.io/doc/book/installing/docker/ for more information

## Prerequisites
- Linux (centos prefered) OS VM
- docker

## Install Jenkins Docker container
The following will install a Jenkins docker container with persistent volume allowing for saved states based on the container being brought up and down.

It is recommended to deploy the jenkins docker container within a Linux VM. For this deployment we will deploy jenkins within a docker container within a Centos VM.


### Prerquisite
- Create a docker login at https://hub.docker.com

###installation
1. Add docker credentials for dockerhub to the environment by running the following
   ```
   export DOCKER_USER="<enter docker hub username>"
   export DOCKER_PASS="<enter docker hub password>"
   ```
      
2. Run the following in the terminal
   1. cd jenkins
   2. `script/jenkins.sh`
   3. Within about 2 minutes and jenkins should 
   4. **Browser**: navigate to http://localhost:8080
   5. IF first time, run the following command in a terminal
      1. **Terminal**:`docker exec -it jenkins-docker  cat /var/jenkins_home/secrets/initialAdminPassword`
   6. **Webpage**: Enter the `initialadminPassword` into the browser
   7. Install Suggested plugins 






