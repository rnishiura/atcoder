FROM pypy:3

RUN apt-get -y update
RUN apt-get install -y gcc g++ locales git procps vim tmux
RUN locale-gen ja_JP.UTF-8
RUN localedef -f UTF-8 -i ja_JP ja_JP
ENV LANG=ja_JP.UTF-8
ENV TZ=Asia/Tokyo

RUN pip3 install online-judge-tools

ENV CPLUS_INCLUDE_PATH=/ac-library
WORKDIR $CPLUS_INCLUDE_PATH
RUN wget https://github.com/atcoder/ac-library/releases/download/v1.4/ac-library.zip 
RUN unzip ac-library.zip && rm ac-library.zip

WORKDIR /code


