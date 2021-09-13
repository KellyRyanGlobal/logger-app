FROM node:12-alpine
RUN apk update && apk add doxygen
RUN apk add g++ make
COPY /src /app
WORKDIR /app
RUN make
RUN g++ test.cc -o test.exe
CMD ./test.exe