FROM alpine:3.14
RUN apk update && apk add build-base
WORKDIR /usr/local/share