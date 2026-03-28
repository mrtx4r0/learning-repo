# Ubuntu 22.04
FROM ubuntu:22.04

# 対話を無効化（aptの質問を防ぐ）
# ENV DEBIAN_FRONTEND=noninteractive

# 基本ツール + 開発環境
RUN apt-get update && apt-get install -y \
    build-essential \
    gcc \
    g++ \
    make \
    gdb \
    vim \
    git \
    curl \
    wget \
    python3 \
    python3-pip \
    sudo \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

# 作業ディレクトリ
WORKDIR /home/tetsu 

# 一般ユーザ作成（rootを避ける）
RUN useradd -ms /bin/bash tetsu && \
    echo "tetsu ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

USER tetsu

# デフォルト起動シェル
CMD ["/bin/bash"]
