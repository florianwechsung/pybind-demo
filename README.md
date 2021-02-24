# pybind11 - eigen - xtensor demo

A minimal repository demonstrating how to setup bindings between Python and C++
code for seamless interaction of numpy vectors and matrices with eigen, and
higher dimensional tensors with xtensor.

## Installation

*IMPORTANT*: You need to clone the repository recursively in order to get all the required submodules.

    git clone --recursive https://github.com/florianwechsung/pybind-demo.git
    pip3 install -e .
    python3 examples/example.py
