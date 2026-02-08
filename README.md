# Temperature Monitoring Demo

This repository contains a demonstration implementation of a bare-metal
temperature monitoring system with LED status indication.

## Features
- Temperature sampling via mocked ADC
- Support for two hardware revisions (Rev-A, Rev-B)
- LED indication for Normal / Warning / Critical ranges
- C implementation and object-oriented C++ implementation
- PC-based demo using mocked hardware interfaces

## Repository Structure
- c_version/   – C implementation
- cpp_version/ – C++ implementation (OOP-based)
- doc/         – Architecture diagrams

## Notes
This project is intended for architectural and design demonstration purposes.
No real hardware access or real-time guarantees are implemented.
