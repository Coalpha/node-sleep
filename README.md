# @coalpha/node-sleep

*Because there just had to be another one.*

```js
const sleep = require("@coalpha/node-sleep");
sleep.sleep_ms(1234);
sleep.sleep_s(4);
sleep.sleep_m(1);
sleep.sleep("20s");
```

```
npm i git+https://github.com/coalpha/node-sleep.git
```

When I was learning about native node modules about a year and a half back, the
first thing that came to mind was being able to completely suspend the event
loop. Ya know, just to really stick it to the node people with their "aye sink"
and "kon curren see" nonsense. Previously, I had done it with a macro but I
think it's much prettier with a template.

