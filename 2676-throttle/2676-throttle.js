/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
let throttle = (fn, t) => {
  let locked = false;
  let lastArgs = null;

  const unlock = () => {
    if (!lastArgs) {
      locked = false;
      return;
    }

    fn(...lastArgs);
    lastArgs = null;

    setTimeout(unlock, t);
  };

  return (...args) => {
    if (locked) {
      lastArgs = args;
      return;
    }

    fn(...args);
    locked = true;
    setTimeout(unlock, t);
  };
};

/**
 * const throttled = throttle(console.log, 100);
 * throttled("log"); // logged immediately.
 * throttled("log"); // logged at t=100ms.
 */