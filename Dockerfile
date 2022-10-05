FROM gcc

WORKDIR /app

COPY . /app/

RUN g++ -o mygrep Source.cpp Options.cpp

ENV options=NULL

ENV keyword=NULL

ENV filename=NULL

CMD ./mygrep ${options} ${keyword} ${filename}