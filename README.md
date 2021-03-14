# Relax Days Hackathon - Fubini

This project was created in the Relaxdays Code Challenge Vol. 1. See https://sites.google.com/relaxdays.de/hackathon-relaxdays/startseite for more information.

My participant ID in the challenge was: CC-Vol1-22

## How to run this project

Demo Video: TODO

You can get a running version of this code by using:

```bash
git clone https://github.com/Ossitech/fubini
cd fubini
docker build -t fubini .
```
To get all the fubini numbers up to the 11th one use: 

```bash
docker run fubini 11

```
It prints a list containing the numbers. For the example input of 11:
```bash
[1, 1, 3, 13, 75, 541, 4683, 47293, 545835, 7087261, 102247563, 1622632573]
```
