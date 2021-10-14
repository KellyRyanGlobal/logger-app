FROM alpine:latest AS Build
ENTRYPOINT ["tail", "-f", "/dev/null"]
RUN apk update && apk add doxygen g++ make bash
RUN [ "hostname ubuntu"]
COPY . /app
WORKDIR /app
CMD /bin/bash -c ' ./build.sh; /bin/bash'
CMD ./server.exe &
CMD ./test_client.exe