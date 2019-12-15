FROM gcc:4.9

LABEL "com.github.actions.name"="Acciones de build"
LABEL "com.github.actions.description"="Generar archivos de compilacion"
LABEL "com.github.actions.icon"="zap"
LABEL "com.github.actions.color"="green"

WORKDIR /usr/src/myapp
ADD entrypoint.sh /entrypoint.sh
RUN ls
RUN pwd
ENTRYPOINT ["/entrypoint.sh"]
