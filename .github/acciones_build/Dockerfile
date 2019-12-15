FROM debian:9.5-slim

LABEL "com.github.actions.name"="Acciones de build"
LABEL "com.github.actions.description"="Generar archivos de compilacion"
LABEL "com.github.actions.icon"="mic"
LABEL "com.github.actions.color"="purple"

ADD / /acciones_build/
RUN pwd
RUN echo "Vamos a establecer los permisos de ejecución"
RUN ls
RUN chmod -R +x /acciones_build
ENTRYPOINT ["/entrypoint.sh"]
