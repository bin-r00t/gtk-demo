#!/bin/bash

gcc `pkg-config --cflags gtk+-3.0` -o output/a.out main.c `pkg-config --libs gtk+-3.0`