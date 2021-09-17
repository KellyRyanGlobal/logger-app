FROM node:12-alpine as node
USER root
RUN apk update && apk add doxygen
RUN apk add g++ make
COPY /src /app
WORKDIR /app
RUN make
EXPOSE 4200
ENTRYPOINT ["/app"]
RUN g++ test.cc -o test_app.exe
CMD ["./test_app.exe"]