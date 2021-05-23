# QMK firmware for my Kyria keyboard

## Installation

macOS:

```
brew install qmk/qmk/qmk
```

Ubuntu:

```
sudo apt install -y git python3-pip gcc-avr
python3 -m pip install --user qmk
```


## Setup

```
qmk setup -H ~/git/MarkusLohmayer/qmk_firmware MarkusLohmayer/qmk_firmware
```


## Configuration

Default keyboard and keymap:

```
qmk config user.keyboard=kyria
qmk config user.keymap=MarkusLohmayer
```


## First time only

Create own keymap with `qmk new-keymap`.


## Compile firmware

```
qmk compile
```

```
qmk compile -kb kyria -km default
```


## Flash firmware

```
qmk flash
```


## Edit keymap

```
vi ./keyboards/kyria/keymaps/MarkusLohmayer
```


## Git and GitHub

Pull latest state from upstream:

```
git fetch upstream
git rebase upstream/master
make git-submodule
```
