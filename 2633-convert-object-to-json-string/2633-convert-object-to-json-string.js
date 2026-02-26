/**
 * @param {null|boolean|number|string|Array|Object} object
 * @return {string}
 */

const stringifyPrimitive = (value) => {
  if (value === null) return "null";

  const valueType = typeof value;

  if (valueType === "number") return String(value);
  if (valueType === "string") return '"' + value + '"';
  if (valueType === "boolean") return value ? "true" : "false";
};

const stringifyArray = (array) => {
  let parts = "[";

  let first = true;

  for (let i = 0; i < array.length; i++) {
    if (!first) parts += `,`;
    else first = false;
    parts += jsonStringify(array[i]);
  }

  return parts + "]";
};

const stringifyObject = (object) => {
  let parts = "{";

  let first = true;

  for (const key in object) {
    if (!first) parts += `,`;
    else first = false;

    parts += '"' + key + '":' + jsonStringify(object[key]);
  }

  return parts + "}";
};

const jsonStringify = (object) => {
  if (object === null || typeof object !== "object")
    return stringifyPrimitive(object);

  if (Array.isArray(object)) return stringifyArray(object);

  return stringifyObject(object);
};