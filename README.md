# @coalpha/node-sleep

*Because there just **had** to be another one.*

```js
const sleep = require("@coalpha/node-sleep");
sleep.sleep_ms(1234);
sleep.sleep_s(4);
sleep.sleep_m(1);
sleep.sleep("20s");
```

You can't do this:
```
npm i --save-dev @coalpha/node-sleep
```
I haven't published it yet.

I was taking a look at native node modules and the first thing that came to mind
was pausing execution. I wanted to use C instead of C++ but `#include <thread>`
was so nice that I couldn't resist. The source code embodies *perfect* DRY
principals resulting in macro garbage. It's really terrible.
