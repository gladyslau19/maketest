# maketest



## TODO

- [ ] Add a reference for your blocks here
- [ ] Add "icon.png" image (300x200) in the root folder
- [ ] Add "- beta" to the GitHub project description if you are still iterating it.
- [ ] Turn on your automated build on https://travis-ci.org
- [ ] Use "pxt bump" to create a tagged release on GitHub
- [ ] Get your package reviewed and approved https://makecode.microbit.org/extensions/approval

Read more at https://makecode.microbit.org/extensions

## License



## Supported targets

* for PXT/microbit
(The metadata above is needed for package search.)

# gator:light Light Sensor

[![Community Discord](https://img.shields.io/discord/448979533891371018.svg)](https://aka.ms/makecodecommunity)

The gator:starter, which includes the gator:light and gator:temp can be purchased [here.](https://www.sparkfun.com/products/14891)
The gator:light, included on the gator:starter is an analog light sensor that can be alligator clipped to the micro:bit or gator:bit board.

![SparkFun gator:light](https://raw.githubusercontent.com/sparkfun/pxt-gator-light/master/icon.png)  

## ~ hint

To use this package, go to https://makecode.microbit.org, click ``Add package`` and search for **gator-light**. The package is located [here](https://makecode.microbit.org/pkg/sparkfun/pxt-gator-light)

## ~

## Basic usage

```blocks
//Sets the value of the light variable to the value read from the gator:light
let light = 0
light = gatorlight.light(AnalogPin.P0, gatorlightType.Lux)
```

Use ``||Get light on pin||`` to read the light value from a gator:light sensor attached to a given pin in lux or the straight ADC value.

## Example: Light Detector

```blocks
//Read light value and write it to the micro:bit screen as a bar graph.
let light = 0
basic.forever(function () {
    light = gatorlight.light(AnalogPin.P0, gatorlightType.Lux)
    led.plotBarGraph(
        light,
        1023
    )
})
```

## Supported targets

* for PXT/microbit

## License

MIT

```package
maketest=github:gladyslau19/maketest
```


