FROM ubuntu:18.04
MAINTAINER Albert Guo "1441250996@qq.com"

ENV REFRESHED_AT 2019-01-24

RUN apt-get update
run apt-get -yq install nginx
run mkdir -p /web/document
ADD nginx/global.conf /etc/nginx/conf.d/
ADD nginx/nginx.conf /etc/nginx/nginx.conf

EXPOSE 80
