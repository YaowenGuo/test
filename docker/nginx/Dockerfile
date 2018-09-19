FROM ubuntu:18.04
MAINTAINER James Turnbull "james@example.com"

ENV REFRESHED_AT 2018-09-01

RUN apt-get update
run apt-get -yq install nginx
run mkdir -p /var/www/htlm
ADD nginx/global.conf /etc/nginx/conf.d/
ADD nginx/nginx.conf /etc/nginx/nginx.conf

EXPOSE 8080
