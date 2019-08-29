/** Pause the NodeJS event loop! */
declare module node_sleep {
   /** Sleep for `ms` milliseconds */
   export function sleep_ms(ms: number): void;
   /** Sleep for `s` seconds */
   export function sleep_s(s: number): void;
   /** Sleep for `m` minutes */
   export function sleep_m(m: number): void;
   /** Sleep for `h` hours */
   export function sleep_h(h: number): void;
   /**
    * Pause the NodeJS event loop using a string formatted with the amount of units.
    * - `ms`: milliseconds
    * - `s`: seconds
    * - `m`: minutes
    * - `h`: hours
    * @example
    * sleep.sleep("10ms");
    * sleep.sleep(`${amount}${unit}`);
    */
   export function sleep(time: string): void;
}
export = node_sleep;
