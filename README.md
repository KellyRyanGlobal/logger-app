### Docker node sample project

1. Run the folllowing to build the docker container
   1. `docker build -t test-app .`

2. Run the command with the following command
   1. `docker run -dp 3000:3000 test-app`
3. To adjust the `port` make sure to alter the `package.json` along with the docker run command

# Jenkins in docker image setup
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
### PRerequisiute
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
