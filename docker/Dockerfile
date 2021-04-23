FROM ubuntu:16.04

RUN apt update && apt install -y bison flex clang-8 clang-format-8 wget make &&\
    update-alternatives --install /usr/bin/clang clang /usr/bin/clang-8 1 &&\
    update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-8 1 &&\
    update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-8 1

RUN wget https://github.com/Kitware/CMake/releases/download/v3.20.1/cmake-3.20.1-linux-x86_64.sh &&\
    chmod +x cmake-3.20.1-linux-x86_64.sh &&\
    ./cmake-3.20.1-linux-x86_64.sh --skip-license --prefix=/usr/local &&\
    rm cmake-3.20.1-linux-x86_64.sh

ARG UID
ARG GID
RUN groupadd -g $GID dummy && useradd -m -r --uid $UID -g dummy --groups "0" dummy

USER dummy
