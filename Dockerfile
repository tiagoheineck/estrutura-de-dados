# Fonte: https://devblogs.microsoft.com/cppblog/c-development-with-docker-containers-in-visual-studio-code/
FROM alpine:3.14

RUN apk add --no-cache g++ musl-dev

ARG UID=1000
ARG GID=1000
ARG UNAME=dev
RUN addgroup -S devgroup && adduser -S dev -G devgroup -u ${UID} -h /home/dev

WORKDIR /home/dev

USER ${UID}

CMD ["/bin/sh"]


# Use o container assim
# docker run -it --rm -v `pwd`:/usr/src/codigos cpp