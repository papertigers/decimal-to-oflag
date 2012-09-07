fileflags
=========

Convert a decimal value into its respective oflag's.
To see a description of each oflag see `man -s2 open`.

Usage
-----

    fileflags <flag int>

Example
-------

    ~$ fileflags 8513
     8513: O_WRONLY|O_DSYNC|O_CREAT|O_LARGEFILE

Common Use Case
---------------
    dtrace -n 'syscall::write:entry / pid == <pid> / { trace(fds[arg0].fi_pathname); trace(fds[arg0].fi_oflags); }'
    dtrace: description 'syscall::write:entry ' matched 1 probe
     15  10130                      write:entry   /root/labs/data100m                   8513
     15  10130                      write:entry   /root/labs/data100m                   8513
     15  10130                      write:entry   /root/labs/data100m                   8513

Installation
------------

Tested on SmartOS

    make
    make install

Credits
-------

Taken from http://src.illumos.org/source/xref/illumos-gate/usr/src/cmd/ptools/pfiles/pfiles.c

See source for License
