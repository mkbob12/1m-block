# netfilter
gcc -o 1m-block 1m-block.c -lnetfilter_queue


# packet to netfiler
sudo iptables -F
sudo iptables -A OUTPUT -j NFQUEUE --queue-num 0
sudo iptables -A INPUT -j NFQUEUE --queue-num 0

# RUN COMMAND 
* syntac : 1m-block <site list file>
* sampe : lm-block top-1m.txt 
