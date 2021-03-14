FROM ubuntu 

LABEL description="Container for use with Fubini Example" 

# install build dependencies 
RUN apt-get update && apt-get install -y g++

RUN g++ main.cpp

CMD ["./a.out"]
