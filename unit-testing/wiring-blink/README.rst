..  Copyright (c) 2014-present PlatformIO <contact@platformio.org>
    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at
       http://www.apache.org/licenses/LICENSE-2.0
    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.

How to test PlatformIO based project
====================================

1. `Install PlatformIO Core <http://docs.platformio.org/page/core.html>`_
2. Download `examples source code <https://github.com/platformio/platformio-examples/archive/develop.zip>`_
3. Extract ZIP archive
4. Run these commands:

.. code-block:: bash

    # Change directory to example
    > cd platformio-examples/unit-testing/wiring-blink

    # Test project
    > platformio test

    # Test specific environment
    > platformio test -e uno
