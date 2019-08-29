const sleep = require("./build/Release/sleep.node");

const r = /^(\d+)(ms|s|m|h)$/;
sleep.sleep = function sleep_any(str) {
   const m = str.match(r);
   if (m == null) {
      throw new Error("Malformed sleep time string!");
   }
   sleep["sleep_" + m[2]](+m[1]);
}

module.exports = sleep;
