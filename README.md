# Scoreboard

An application for keeping track of time and goals in matches, it's intended use
case is as a scoreboard in sport arenas.

## Building

The application is built and tested with Qt 6, though it might work with the
earlier Qt 5.15 version as well.

### Linux

Installing dependencies for Debian/Ubuntu distributions:

```shell
sudo apt install build-essential cmake git libgl1-mesa-dev qt6-base-dev
```

Clone repository:

```shell
git clone git@github.com:havardAasen/scoreboard.git
cd scoreboard
```

Configure and build application:

```shell
mkdir build
cmake -S . -B build
cmake --build build -j ${nproc}
```

## TODO

- Implement handling of time penalties, player number and remaining time for
  both teams.
- Add Norwegian translations.
- Update GitHub Actions to create package for macOS.
