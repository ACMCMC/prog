#!/bin/sh -l

echo "Script ejecutado desde: ${PWD}"
BASEDIR=$(dirname $0)
echo "Ubicación: ${BASEDIR}"
ls
echo "Vamos a empezar la compilación"

chmod +x instrucciones.sh

CODIGO_COMPILACION="$(./instrucciones.sh)"

if ($CODIGO_COMPILACION = 1) ; then
  echo "Error de compilación: $CODIGO_COMPILACION"
  exit 0
else
  echo "Compilación exitosa"
fi
