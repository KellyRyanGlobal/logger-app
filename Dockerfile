FROM node:12-alpine
RUN addgroup -S app && -S -G app app
RUN apk update && apk add doxygen
RUN apk add g++ make
USER app
COPY /src /app
WORKDIR /app
RUN make
ENTRYPOINT ["scripts/entrypoint.sh"]
RUN g++ test.cc -o test.exe
CMD ./test.exe