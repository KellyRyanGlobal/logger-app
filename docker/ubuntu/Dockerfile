FROM ubuntu:20.04
ENTRYPOINT ["tail", "-f", "/dev/null"]
WORKDIR /app
RUN apt-get update 
RUN apt-get install -y doxygen 
RUN apt-get install -y make
RUN apt-get install -y g++
RUN adduser -u 5678 --disabled-password --getcos "" appuser && chown -R appuser /app"
USER appuser
EXPOSE 8050
CMD []
COPY . /app

