FROM ubuntu 

LABEL description="Container for use with Fubini Example" 

# install build dependencies 
RUN apt-get update && apt-get install -y g++

COPY main.cpp /

RUN g++ /main.cpp

COPY entrypoint.sh /

ENTRYPOINT ["/entrypoint.sh"]
