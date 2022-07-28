# Fonte: https://devblogs.microsoft.com/cppblog/c-development-with-docker-containers-in-visual-studio-code/
FROM gcc:11.2.0

RUN apt-get update && apt-get install gdb -y

ARG UID=1000
ARG GID=1000
ARG UNAME=dev
RUN groupadd -g ${GID} -o ${UNAME}
RUN useradd -m -u ${UID} -g ${GID} -o -s /bin/bash ${UNAME}

RUN mkdir /opt/codes

RUN chown ${UID} /opt/codes 

WORKDIR /opt/codes


USER ${UID}

CMD ["/bin/bash"]


# Use o container assim
# docker run -it --rm -v `pwd`:/usr/src/codigos cpp