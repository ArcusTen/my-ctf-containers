# Reader (PrivEsc) Room:
##  Overview

Welcome to the Privilege Escalation room based on `CVE-2019-14287`! This room will guide you through exploiting a vulnerability in sudo version 1.8.27, which allows for privilege escalation.


## How to play it?

1. First build the container:
```bash
docker build -t reader .
```

2. To spin up a container:
```bash
docker run -d -p 2222:22 --name readerCon reader:latest
```

3. To SSH into the container:
```
ssh ctf-player@<container-IP>
```
