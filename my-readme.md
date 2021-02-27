# QMK firmware for my Kyria keyboard

## Installation

macOS:
```
brew install qmk/qmk/qmk
```

```
qmk setup -H ~/git/MarkusLohmayer/qmk_firmware MarkusLohmayer/qmk_firmware
```


## Configuration

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
