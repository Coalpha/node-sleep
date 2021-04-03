const sleep = require("./build/Release/lib.node");

const r = /^(\d+)(ns|ms|s|m|h)$/;
sleep.sleep = function sleep_any(str) {
   const m = str.match(r);
   if (m == null) {
      throw new Error("Malformed sleep time string!");
   }
   const [, units, time] = m;
   sleep[`sleep_${units}`](time|0);
}

module.exports = sleep;
