FROM ubuntu:latest
ENTRYPOINT ["tail", "-f", "/dev/null"]
RUN apt-get update 
RUN apt-get install doxygen make -y
RUN apt-get install g++
COPY . /app
WORKDIR /app