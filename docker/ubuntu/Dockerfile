FROM ubuntu:latest
ENTRYPOINT ["tail", "-f", "/dev/null"]
ENV HOSTNAME HELLO
RUN apt-get update 
RUN apt-get install -y doxygen 
RUN apt-get install -y make
RUN apt-get install -y g++
COPY . /app
WORKDIR /app
