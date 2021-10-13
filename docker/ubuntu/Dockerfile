FROM IMAGE AS Build
ENTRYPOINT ["tail", "-f", "/dev/null"]
RUN apt-get update 
RUN apt-get install doxygen g++ make -y
COPY . /app
WORKDIR /app