# Prerequisites

Install VirtualBox and Vagrant on your machine, in that order.

## VirtualBox Downloads

Windows: 
```
https://download.virtualbox.org/virtualbox/6.1.18/VirtualBox-6.1.18-142142-Win.exe
```

Mac OS: 
```
https://download.virtualbox.org/virtualbox/6.1.18/VirtualBox-6.1.18-142142-OSX.dmg
```

## Vagrant Downloads

Windows: 
```
https://releases.hashicorp.com/vagrant/2.2.14/vagrant_2.2.14_x86_64.msi
```

Mac OS: 
```
https://releases.hashicorp.com/vagrant/2.2.14/vagrant_2.2.14_x86_64.dmg
```

# Starting the VM

Clone the repository, and from the command line, navigate to the directory containing the Vagrantfile. Then, run the following command:

```
vagrant up
```

It will take some time for the virtual machine to be ready -- let it run until you are greeted with a login screen. You should log in as the user vagrant. The password for this user is also vagrant.

# Running helper.sh

Open the terminal in the virtual machine and execute the following command:

```
cd ~/Desktop && ./helper.sh
```

After running the script, log out and log back in.

You should now be ready to use the virtual machine for development purposes. Do not move the lab midterm directory!
