FROM archlinux/base
USER root
WORKDIR /hostroot

RUN pacman -Syyu --noconfirm && \
    pacman-db-upgrade && \
    pacman -S --noconfirm base-devel boost boost-libs

COPY src /build/src
RUN cd /build/src && \
    make && \
    mv main /usr/bin
