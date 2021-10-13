FROM ubuntu:14.04.1
ENTRYPOINT ["tail", "-f", "/dev/null"]
RUN apt-get update 
RUN apt-get install doxygen g++ make bash -y
COPY . /app
WORKDIR /app