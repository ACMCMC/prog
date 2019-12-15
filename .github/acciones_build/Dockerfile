FROM debian:9.5-slim

LABEL "com.github.actions.name"="Acciones de build"
LABEL "com.github.actions.description"="Generar archivos de compilacion"
LABEL "com.github.actions.icon"="zap"
LABEL "com.github.actions.color"="green"

ADD entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh
ENTRYPOINT ["/entrypoint.sh"]
