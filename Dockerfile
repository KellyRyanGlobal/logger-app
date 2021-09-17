FROM node:12-alpine
RUN apk update && apk add doxygen
RUN apk add g++ make
COPY /src /app
# exclude
*.md
WORKDIR /app
RUN make
RUN g++ test.cc -o test_app.exe
CMD ./test_app.exe