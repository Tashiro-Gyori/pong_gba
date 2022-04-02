# pong_gba
[![CodeFactor](https://www.codefactor.io/repository/github/tbernis-code/pong_gba/badge)](https://www.codefactor.io/repository/github/tbernis-code/pong_gba)

A pong-style game for the GBA.
Currently learning how to do GBA programming using the Tonc tutorial : https://www.coranac.com/tonc/text/

The github page uses the GBA emulator from here : https://github.com/endrift/gbajs

---

Because installing the dependencies is a hassle, I found that Devkitpro provides a Docker image.
Thus, to compile the project, install Docker if you don't have it yet and run the following commands at the root of the project :

```
docker build -t <project-name-here> .

docker run <project-name-here>

docker cp <container-name-here>:/usr/src/app/pong.elf bin

docker cp <container-name-here>:/usr/src/app/pong.gba bin
```
