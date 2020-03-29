# LSM Trasher

This is the fjsec LSM disabler for Fujitsu Arrows NX F-01F (Android 4.4.2, build # V10R22A, kernel version 3.4.0). Supposed to be used after you gain root w/ [CVE-2017-8890 exp](https://github.com/dadreamer/CVE-2017-8890 "CVE-2017-8890 exp") - just insmod-rmmod it and you're done.

The compilation is performed against the [ending KK kernel](https://spf.fmworld.net/oss/oss/f-01f/kk/data/dammy/OSV-KK_F01F_V10R22A.tar.gz "ending KK kernel") with *msm8974_defconfig* configuration. *Module.symvers* is generated with [extract-symvers](https://github.com/glandium/extract-symvers "extract-symvers") script and should be put into the kernel root directory.