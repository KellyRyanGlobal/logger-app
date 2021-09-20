FROM node:12-alpine AS Build
ENTRYPOINT ["tail", "-f", "/dev/null"]
RUN apk update && apk add doxygen docker 
RUN apk add g++ make
COPY . /app
WORKDIR /app
RUN make -C src/
RUN g++ test.cc -o test_app.exe