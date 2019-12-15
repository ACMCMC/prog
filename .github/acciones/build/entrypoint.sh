#!/bin/sh -l

pwd
ls
echo "Vamos a empezar la compilación"

chmod +x instrucciones.sh

if (./instrucciones.sh == 1) ; then
  echo "Game over!"
  exit 0
fi
