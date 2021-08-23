### Docker node sample project

1. Run the folllowing to build the docker container
   1. `docker build -t test-app .`

2. Run the command with the following command
   1. `docker run -dp 3000:3000 test-app`
3. To adjust the `port` make sur eto alrer the `package.json` along with the docker run command

## Jenkiins in docker image setup
Reference https://www.jenkins.io/doc/book/installing/docker/ for more information

1. Run the following in the terminal
   1. `docker network create jenkins`
   2. `docker run --name jenkins-docker --rm --detach --privileged --network jenkins --network-alias docker \
      --env DOCKER_TLS_CERTDIR=/certs \
      --volume jenkins-docker-certs:/certs/client \
      --volume jenkins-data:/var/jenkins_home \
      --publish 2376:2376 \
      docker:dind \
      --storage-driver overlay2`
   3. `cd jenkins`
   4. `docker build -t myjenkins-blueocean:1.1 .`
   5. `docker run \
      --name jenkins-blueocean \
      --rm \
      --detach \
      --network jenkins \
      --env DOCKER_HOST=tcp://docker:2376 \
      --env DOCKER_CERT_PATH=/certs/client \
      --env DOCKER_TLS_VERIFY=1 \
      --publish 8080:8080 \
      --publish 50000:50000 \
      --volume jenkins-data:/var/jenkins_home \
      --volume jenkins-docker-certs:/certs/client:ro
      myjenkins-blueocean:1.1 `
   6. Wit about 2 minutes and jenkins should be up at http://localhost:8080
   7. 
   
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
   3. 


### CI/CD with Auto DevOps

This template is compatible with [Auto DevOps](https://docs.gitlab.com/ee/topics/autodevops/).

If Auto DevOps is not already enabled for this project, you can [turn it on](https://docs.gitlab.com/ee/topics/autodevops/#enabling-auto-devops) in the project settings.

### Developing with Gitpod

This template has a fully-automated dev setup for [Gitpod](https://docs.gitlab.com/ee/integration/gitpod.html).

If you open this project in Gitpod, you'll get all Node dependencies pre-installed and Express will open a web preview.
