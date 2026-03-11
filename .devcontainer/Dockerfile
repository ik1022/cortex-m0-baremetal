FROM alpine:3.22

RUN apk --update add git cmake ninja-build gcc-arm-none-eabi g++-arm-none-eabi binutils-arm-none-eabi gcc g++ gdb cpputest npm py3-pyocd; rm -rf /var/cache/apk/* ; cp /usr/lib/ninja-build/bin/ninja bin


# ADD index.html /var/www/html/index.html			# html파일 추가
# EXPOSE 80/tcp									    # 80포트 설정
# CMD ["/bin/sh", "-DFOREGROUND"]
