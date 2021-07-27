# Fonte: https://devblogs.microsoft.com/cppblog/c-development-with-docker-containers-in-visual-studio-code/
FROM gcc:4.9

COPY ./ /usr/src/codigos

WORKDIR /usr/src/codigos

RUN g++ -o build/HelloWorld src/HelloWorld.cpp

CMD ["/bin/bash"]

# Use o container assim
# docker run -it --rm -v `pwd`:/usr/src/codigos cpp