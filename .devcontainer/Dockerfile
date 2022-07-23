FROM ubuntu:22.04

RUN apt update && apt install -y tzdata && apt clean && rm -rf /var/lib/apt/lists/*
ENV TZ Asia/Tokyo

ENV LANG ja_JP.UTF-8
ENV LANGUAGE ja_JP:ja

RUN apt update
RUN apt upgrade -y
RUN apt install -y wget vim zsh software-properties-common git vim locales make cmake swig liborc-0.4-dev libspdlog-dev
RUN locale-gen ja_JP.UTF-8

RUN add-apt-repository ppa:gnuradio/gnuradio-releases -y
RUN apt update && apt install gnuradio -y