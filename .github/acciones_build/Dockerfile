FROM debian:9.5-slim

LABEL "com.github.actions.name"="Acciones de build"
LABEL "com.github.actions.description"="Generar archivos de compilacion"
LABEL "com.github.actions.icon"="mic"
LABEL "com.github.actions.color"="purple"

ADD entrypoint.sh /entrypoint.sh
RUN pwd
RUN ls
RUN chmod -R +x ./progI
ENTRYPOINT ["/entrypoint.sh"]
