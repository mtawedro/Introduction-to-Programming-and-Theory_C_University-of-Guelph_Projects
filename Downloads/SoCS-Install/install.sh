#!/bin/bash

echo "Welcome to the rapsberry pi install SoCS Software Installer!"
echo
echo "Retrieving installer files... please wait"
sudo apt-get update

echo "Installing installer ... please wait"
sudo apt-get -y install ansible

echo "Installing SoCS Software, this may take a few minutes"
sudo ansible-playbook -i "localhost," -c local raspi-ansible.xml

#Start Ownclould
owncloud&

