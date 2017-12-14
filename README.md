## EUDYPTULA CHALLENGE
---
### Task 1

Write a Linux kernel module, and stand-alone Makefile, that when loaded
prints to the kernel debug log level, "Hello World!"  Be sure to make
the module be able to be unloaded as well.

The Makefile should build the kernel module against the source for the
currently running kernel, or, use an environment variable to specify
what kernel tree to build it against.

---
### Task 2
  - download Linus's latest git tree from git.kernel.org (you have to
    figure out which one is his, it's not that hard, just remember what
    his last name is and you should be fine.)
  - build it, install it, and boot it.  You can use whatever kernel
    configuration options you wish to use, but you must enable
    CONFIG_LOCALVERSION_AUTO=y.

    Hints: look into the make localmodconfig option, and base your kernel configuration on a working distro kernel configuration; Write a simple to answer all the different kernel configuration options;

---
### Task 3
  - take the kernel git tree from Task 02 and modify the Makefile to
    and modify the EXTRAVERSION field.  Do this in a way that the
    running kernel (after modifying the Makefile, rebuilding, and
    rebooting) has the characters "ve482hobby" in the version string.
    
    Hint: refer to the file Documentation/SubmittingPatches.

---
### Task 4

Part of the job of being a kernel developer is recognizing the proper Linux kernel coding style. The full description of this coding style can be found in the kernel itself (Documentation/CodingStyle). There
is also a tool (checkpatch.pl in the scripts directory) available from the kernel source tree. The task for this round consists in refactoring the module from the first task such that it meets the
requirements of the Linux kernel coding style.

Note: it is important that everyone follow the same standard so that the patterns become consistent. In other words, you want to make it really easy for other people to find the bugs in your code, and not be
confused and distracted by other unimportant things (e.g. prefer spaces instead of tabs for indentation).

---
### Task 5

Take the kernel module from task 1, and modify it so that when a USB keyboard is plugged in, the module gets automatically loaded by the correct user-space hotplug tool (udev, now part of systemd).
Hint: refer to chapter 14 of Linux Device Drivers, 3rd edition.