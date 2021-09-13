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

# About Logger

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


# Automated Testing Environment
The testing environment will use jenkins running in docker to deploy containers with logger running
The following instructions will guide the user/tester to build and deploy the application within a local environment or a container.

# Prerequisite

## Prerequisites Windows

The following needs to be pre installed on a Windows 10 workstation  before proceeding. How to install the services are outside of the scope of this README.

- Virtualbox (hypervisor)- See Virtualbox Prerequisite
- - Linux (CentOS prefered) OS VM image

### Virtualbox Prerequisite
The following need to be installed on the Linux OS VM that is installed on virtualbox. The installation of how to install the OS is outside of the scope of this readme.
- doxygen - for building logger
- Install g++ and gcc
- Install Make
- Create a docker login at https://hub.docker.com
- **sshkeygen**- for ssh connection
- **docker**- for building containers


## Jenkins Docker image setup
Reference https://www.jenkins.io/doc/book/installing/docker/ for more information

## Install Jenkins Docker container
The following will install a Jenkins docker container with persistent volume allowing for saved states based on the container being brought up and down.

It is recommended to deploy the jenkins docker container within a Linux VM. For this deployment we will deploy jenkins within a docker container within a Centos VM.

### Installation
1. Add docker credentials for dockerhub to the environment by running the following
   ```
   export DOCKER_USER="<enter docker hub username>"
   export DOCKER_PASS="<enter docker hub password>"
   ```

2. Run the following in the terminal
    1. **Localhost**: Open a terminal and SSH to the VM using the following command
        1. `ssh <username>@<IP of VM>`
    2. **VM TERMINAL**: Run the following command
        1. `git clone git@github.com:KellyRyanGlobal/testing-app.git`
    3. **VM TERMINAL**: Navigate to the cloned repo for `testing-app`
    4. **VM TERMINAL**: `cd jenkins`
    5. **VM TERMINAL**:`script/jenkins.sh`
    6. Within about 2 minutes and jenkins should
    7. **Local host**: Open a browaser
    8. **Browser**: navigate to http://<VM IP>:8080
    9. If it is the first time, run the following command in a terminal
        1. **Terminal**:`docker exec -it jenkins-docker  cat /var/jenkins_home/secrets/initialAdminPassword`
    10. **Webpage**: Enter the `initialadminPassword` into the browser
    11. Install Suggested plugins

## Build logger in localhost

To build logger locally in your workstation, run the following command
1. `make`
2. Verify the test-bin is created
3. Run the following command
    1. `g++ test.cc -o test.exe`
    

## Build logger in docker

To build logger in a docker container run the following
1. `docker build -t logger-test .`
2. `docker run  --rm --name logger logger-test > output.out`
3. `cat output.out`




