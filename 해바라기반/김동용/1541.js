const filePath =
  process.platform === "linux" ? "dev/stdin" : "BOJ/Silver/1541/1541.txt";
let str = require("fs").readFileSync(filePath).toString().trim().split("-");

let sum = 0;
for (let i = 0; i < str.length; i++) {
  const num = str[i].split("+").reduce((acc, cur) => (acc += +cur), 0);
  if (!i) sum += num;
  else sum -= num;
}
console.log(sum);
