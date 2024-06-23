# myJail CTF Room
##  Overview

Welcome to the myJail Capture the Flag (CTF) room! This room is designed to challenge your skills in shell escaping and SUID exploitation. You will navigate a restricted environment, escalate privileges, and ultimately capture the flag. Good luck, and have fun!

## Description
### Dockerfile

The Dockerfile sets up an Ubuntu-based environment with two users: prisoner and zoro. Each user has unique credentials and specific configurations to enhance the challenge.
To build this container:

The main objectives include:

1. Escaping the restricted shell.
2. Exploiting SUID permissions to escalate privileges.
3. Capturing the flag located at `/root/flag.txt`.


## How to play it?

1. First build the container:
```bash
docker build -t myjail .
```

2. To spin up a container:
```bash
docker run -d -p 2222:22 --name myjailCon myjail:latest
```

3. To SSH into the container:
```
ssh prisoner@<container-IP>
```

 