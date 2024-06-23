FROM ubuntu:latest

RUN mkdir /var/run/sshd

# Copying sudo 1.8.27 source code into the container
COPY sudo-1.8.27.tar.gz /tmp/sudo-1.8.27.tar.gz

# Installing necessary packages
RUN apt-get update && \
    apt-get install -y build-essential openssh-server nano

# Installing vulnerable sudo
RUN tar -xzvf /tmp/sudo-1.8.27.tar.gz -C /tmp && \
    cd /tmp/sudo-1.8.27 && \
    ./configure && \
    make && \
    make install && \
    rm -rf /tmp/sudo-1.8.27 /tmp/sudo-1.8.27.tar.gz

# Creating user
RUN useradd -m ctf-player
RUN echo "ctf-player:my_v3ry_s3cur3_p@55_17" | chpasswd
RUN usermod -aG sudo ctf-player

# Setting sudo permissions 
RUN echo "ctf-player ALL=(ALL,!root) /bin/base64" >> /etc/sudoers

# Nulling bash history
RUN ln -sf /dev/null /home/ctf-player/.bash_history

# Creating flag.txt in root's directory
RUN echo "flag{REDACTED}" > /root/flag.txt && \
    chown root:root /root/flag.txt && \
    chmod 400 /root/flag.txt

# Setting up SSH
RUN sed -i 's/PermitRootLogin prohibit-password/PermitRootLogin yes/' /etc/ssh/sshd_config
RUN sed 's@session\s*required\s*pam_loginuid.so@session optional pam_loginuid.so@g' -i /etc/pam.d/sshd
EXPOSE 22

RUN chsh -s /bin/bash ctf-player

CMD ["/usr/sbin/sshd", "-D"]