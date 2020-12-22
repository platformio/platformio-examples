## CI&CD example project setup

Project that contains: platformio setup, arduino framework, unit test, integration tests and pipeline for CI & CD (Github Actions)


## Requirements

 * [Arduino Uno Board](https://store.arduino.cc/usa/arduino-uno-rev3)
 * [Visual Studio Code IDE](https://code.visualstudio.com/download)
 * [PlatformIO IDE Extension](https://platformio.org/platformio-ide)
 * [PlatformIO Core (CLI)](https://docs.platformio.org/en/latest/core/installation.html#installation-methods)

## Platformio Agent setup (command line)

### Step 1

In order to run integration tests, you will need to login to your platformio account:

```shell
$ platformio account login
```

### Step 2

Connect your arduino board via USB and start the remote agent

```shell
$ platformio remote agent start
```

If everything is ok, you should get the following info on your terminal:

    2020-12-13 23:07:38 [info] Connecting to PlatformIO Remote Development Cloud
    2020-12-13 23:07:39 [info] Successfully connected
    2020-12-13 23:07:39 [info] Authenticating
    2020-12-13 23:07:40 [info] Successfully authorized

### Step 3

Generate an platformio account token:

```shell
$ platformio account token
```

You should see on your terminal the token generated, then as the final step to allow the pipeline (github actions) to connect with your arduino board you should save the token as a [secret on your github repository](https://docs.github.com/es/free-pro-team@latest/actions/reference/encrypted-secrets): On your repository > Settings > Secrets > New repository secret: Use next environment variable: **PLATFORMIOAGENT**


## Running tests

You can run your **unit** or **integration** tests using Platformio IDE or Platformio CLI (terminal)

### Unit tests

* Platformio IDE: Platformio option > env:native > Advanced > Test
* Platformio CLI: 

```shell
$ platformio test --environment native -f unit -v
```


### Integration tests

Be sure that you have connected your Arduino board before run integration tests:

* Platformio IDE: Platformio option > env:uno > Advanced > Test
* Platformio CLI:

```shell
$ platformio test --environment uno -f integration -v
```

## Pipeline (GitHub Actions)

The jobs that the pipeline will be executing after you do a **push** on your repository are on: `.github/workflows/main.yml` and those are:

* build-and-tests (unit and integration tests)
* deploy-firmware

Make sure that you have configured the secret variable and running the platformio agent before executing the pipeline.

## Platforms supported

* atmelavr (uno tested)
* native

## External Libraries

* ArduinoFake


