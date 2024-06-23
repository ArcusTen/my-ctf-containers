FROM ubuntu:latest

# Installing necessary packages
RUN apt-get update && \
    apt-get install -y build-essential openssh-server nano vim tmux sudo python3

RUN mkdir /var/run/sshd

# Create user "prisoner"
RUN useradd -ms /bin/bash prisoner
RUN echo "prisoner:prison_p@55_4_m3" | chpasswd
# Nulling bash history
RUN ln -sf /dev/null /home/prisoner/.bash_history

# Creating user "zoro"
RUN useradd -ms /bin/bash zoro
RUN echo "zoro:i_b3t_you_w0nt_Gu355_1t" | chpasswd
# Nulling bash history
RUN ln -sf /dev/null /home/zoro/.bash_history

# Copying necessary files
COPY main.cpp /home/prisoner/
COPY zoro.py /usr/share/zoro.py

# Compiling main.cpp
RUN g++ /home/prisoner/main.cpp -o /home/prisoner/main
RUN rm /home/prisoner/main.cpp

# Adjusting ownership and permissions
RUN echo "prisoner ALL=(zoro) NOPASSWD: /usr/share/zoro.py" >> /etc/sudoers
RUN chown zoro:zoro /usr/share/zoro.py
RUN chmod 756 /usr/share/zoro.py
RUN chown prisoner:zoro /usr/bin/python3

# Creating root's flag 
RUN echo "AUCSS{C0ngr4Ts_y0u_35c4p3d_7h3_j4il}" > /root/flag.txt && \
    chown root:root /root/flag.txt && \
    chmod 400 /root/flag.txt

# Setting the working directory to /home/prisoner
WORKDIR /home/prisoner

# Setting up SSH
RUN sed -i 's/PermitRootLogin prohibit-password/PermitRootLogin yes/' /etc/ssh/sshd_config
RUN sed -i 's/PasswordAuthentication no/PasswordAuthentication yes/' /etc/ssh/sshd_config
RUN sed 's@session\s*required\s*pam_loginuid.so@session optional pam_loginuid.so@g' -i /etc/pam.d/sshd


# Setting SUID permission for less command and restrict its execution
USER root
RUN chown root:zoro /usr/bin/find
RUN chmod 750 /usr/bin/find
RUN chmod u+s /usr/bin/find

# Changing the default shell for prisoner to the compiled main program
RUN chsh -s /home/prisoner/main prisoner

CMD ["/usr/sbin/sshd", "-D"]
