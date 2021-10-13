FROM ubuntu:latest
ENTRYPOINT ["tail", "-f", "/dev/null"]
RUN apt-get update 
RUN apt-get install doxygen -y
RUN apt-get install make -y
RUN apt-get install g++ -y
COPY . /app
WORKDIR /app