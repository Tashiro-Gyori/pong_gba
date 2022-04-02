FROM devkitpro/toolchain-base

WORKDIR /usr/src/app/
COPY ./* /usr/src/app/

RUN ln -s /proc/self/mounts /etc/mtab && dkp-pacman -S --noconfirm gba-dev && \
    yes | dkp-pacman -Scc

ENV DEVKITARM=${DEVKITPRO}/devkitARM

CMD ["make"]