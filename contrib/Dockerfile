# syntax=docker/dockerfile:1
FROM alpine:latest AS builder
RUN apk update && apk --no-cache add git clang cmake make pkgconfig

ARG branch=fork
ADD ../ /source
WORKDIR /build
RUN cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=/usr/bin/clang -DCMAKE_EXE_LINKER_FLAGS=-static /source
RUN make

# We don't know what vulnerabilities are out there,
# so we compile a static binary with nothing else.
# As wise people say - naked man fears no pickpocket!
FROM scratch
COPY --from=builder /build/disasterserver/DisasterServer /
VOLUME /data
WORKDIR /data
EXPOSE 8606/udp
ENTRYPOINT ["/DisasterServer"]
