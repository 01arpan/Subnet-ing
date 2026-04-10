# Subnet-ing
Are you stuck at subnetting? Use my tool!!!


# 🌐 Subnet Calculator Tool

A powerful and efficient networking tool designed to calculate and analyze subnet-related information, including:

- Subnet Details
- Fixed Length Subnet Masking (FLSM)
- Variable Length Subnet Masking (VLSM)

This tool is ideal for students, network engineers, and cybersecurity learners who want to understand IP addressing and subnetting deeply.

---

## 🚀 Features

- ✅ Calculate Network ID
- ✅ Find Broadcast Address
- ✅ Determine First and Last Host IP
- ✅ Calculate Next Network ID
- ✅ Subnet Mask & CIDR conversion
- ✅ Block Size calculation
- ✅ FLSM subnetting
- ✅ VLSM subnetting
- ✅ Input validation for IPv4 format

---

## Installation and Run

1. git clone https://github.com/01arpan/Subnet-ing/ 
2. cd Subnet-ing
3. g++ subnetting.cpp -o exicutable
4. ./exicutable



## Banner

+========================================+

| Auther     : Arpan Kanti Das           |

| Tool       : Subnet-ing               |

| Technology : C++                       |

| Github     : 01arpan                  |

| E-mail     : arpankantidas9@gmail.com  |

+=======================================+

## 📥 Input Format

Enter IP address in CIDR notation, like: 192.168.1.10/24

## Options

What You Wanna DO?

0. Change Target IP
1. Find Subnet Details
2. FLSM
3. VLSM
4. Exit

Choose your option.

## 📤 Output Example(Subnet details)

Target IP Loaded: 192.168.1.10/24

Subnet Details...
Network ID        : 192.168.1.0
Broadcast         : 192.168.1.255
First Host IP     : 192.168.1.1
Last Host IP      : 192.168.1.254
Next Network ID   : 192.168.1.0
Subnet Mask       : 255.255.255.0
Netorks Bits      : 0
Host Bits         : 8
CIDR              : 24
Block Size        : 256
Subnets           : 1
IP Addresses      : 256
Number of Hosts   : 254

## For exit the program

Just type "Exit" or "exit" or 4(in cmd)




## 
