#Introduction
This is a fork version of https://github.com/elanthis/easylogger. Modifications are made for simple testing purpose of running basic testing functionality within a jenkins environment.

Some of the modifications will not have to do with the logger itself, but test out things such as:
- System calls
- User input
- Opening applications

The logging will help provide information based on these events occuring.

Testing that will be performed include
- **Functional testing**- Test working as expected based on predefined cirtumstancs
   - Positive and negative- Testing based on assertions
- Acceptance testing

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
- pre install docker (`apt-get docker`)
- Preinstall docker compose (`apt-get docker-compose`)

## Install Jenkins
1. Run the following in the terminal
   1. `docker compose up`
   2. Within about 2 minutes and jenkins should be up at http://localhost:8080
   
   
## Create Persistance for jenkins
This will allow us to sae our configuration of the jenkins controller and our jobs when we reboot minikube for jenkins.
### Prerequisite
- Needs K8s (minikube, kubectl)
- Need Helm
## Deploy peristance yml
1. **Terminal**: Run the following commands
   1. `cd jenkins`
   2. `kubectl create namespace jenkins`
   3. ` minikube start`
   4. ` kubectl create namespace jenkins`
   5. `kubectl get namespaces`
2. Verify jenkins is in the list
   1. `helm repo add jenkinsci https://charts.jenkins.io`
   2. `helm repo update`

## Create docker slaves within jenkins
### Prerequisiute
1. **Windows(bash)**: run the following commands
   1. `curl -L https://github.com/docker/machine/releases/download/v0.16.2/docker-machine-Windows-x86_64.exe > "$HOME/bin/docker-machine.exe" && \
      chmod +x "$HOME/bin/docker-machine.exe"`
2. **Linux**: `curl -L https://github.com/docker/machine/releases/download/v0.16.2/docker-machine-`uname -s`-`uname -m >/tmp/docker-machine && chmod +x /tmp/docker-machine &&   sudo cp /tmp/docker-machine /usr/local/bin/docker-machine`

## Create Docker slave node for jenkins      
### CI/CD with Auto DevOps

This template is compatible with [Auto DevOps](https://docs.gitlab.com/ee/topics/autodevops/).

If Auto DevOps is not already enabled for this project, you can [turn it on](https://docs.gitlab.com/ee/topics/autodevops/#enabling-auto-devops) in the project settings.

### Developing with Gitpod

This template has a fully-automated dev setup for [Gitpod](https://docs.gitlab.com/ee/integration/gitpod.html).

If you open this project in Gitpod, you'll get all Node dependencies pre-installed and Express will open a web preview.
