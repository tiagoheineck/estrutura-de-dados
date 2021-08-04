# Fonte: https://devblogs.microsoft.com/cppblog/c-development-with-docker-containers-in-visual-studio-code/
FROM gcc:11.2.0

RUN apt-get update && apt-get install gdb -y

COPY ./ /usr/src/codigos

WORKDIR /usr/src/codigos

RUN g++ -o build/HelloWorld src/HelloWorld.cpp

CMD ["/bin/bash"]

# Use o container assim
# docker run -it --rm -v `pwd`:/usr/src/codigos cpp