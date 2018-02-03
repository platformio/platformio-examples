README
======

This is the smallest-possible example program using libopencm3.

It's intended for the 1Bitsy STM32F415RGT eval board. It should blink
the LED on the board.

Board connections
=================

*none required*

How to build PlatformIO based project
=====================================

1. `Install PlatformIO Core <http://docs.platformio.org/page/core.html>`_
2. Download `examples source code <https://github.com/platformio/platformio-examples/archive/develop.zip>`_
3. Extract ZIP archive
4. Run these commands:

.. code-block:: bash

    # Change directory to example
    > cd platformio-examples/1bitsy/fancyblink

    # Build project
    > platformio run

    # Upload firmware
    > platformio run --target upload

    # Build specific environment
    > platformio run -e 1bitsy_stm32f415rgt

    # Upload firmware for the specific environment
    > platformio run -e 1bitsy_stm32f415rgt --target upload

    # Clean build files
    > platformio run --target clean
