FROM devkitpro/toolchain-base

WORKDIR /usr/src/app/

RUN mkdir -p bin

COPY ./* /usr/src/app/

# Decomment this if you're on Mac
#RUN ln -s /proc/self/mounts /etc/mtab

RUN dkp-pacman -S --noconfirm gba-dev && \
    yes | dkp-pacman -Scc

ENV DEVKITARM=${DEVKITPRO}/devkitARM

CMD ["make"]