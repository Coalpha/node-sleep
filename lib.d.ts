/** Pause the NodeJS event loop! */
declare module node_sleep {
   export function sleep_ns(ns: number): void;
   export function sleep_ms(ms: number): void;
   export function sleep_s (s:  number): void;
   export function sleep_m (m:  number): void;
   export function sleep_h (h:  number): void;
   /**
    * Pause the NodeJS event loop using a string formatted with the amount of units.
    * - `ns`: nanoseconds
    * - `ms`: milliseconds
    * - `s` : seconds
    * - `m` : minutes
    * - `h` : hours
    * @example
    * sleep.sleep("10ms");
    * sleep.sleep(`${amount}${unit}`);
    */
   export function sleep(time: string): void;
}
export = node_sleep;
