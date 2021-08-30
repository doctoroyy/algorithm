// interface LinkNode {
//   val: number;
//   next?: LinkNode;
// }

// const node1: LinkNode = {
//   val: 1,
// };

// const node2: LinkNode = {
//   val: 2,
// }

// const node3: LinkNode = {
//   val: 3,
// }

// node1.next = node2;
// node2.next = node3;
// node3.next = node1;

// const vis = [0, 0, 0, 0];

// const dfs = (node: LinkNode) => {
//   vis[node.val] += 1;
//   if (vis[node.val] !== 1) {
//     return;
//   }
//   node.next && dfs(node.next);
// }
// dfs(node1)
// console.log(vis);

// 拓扑排序

// input: [[1,0],[2,0],[3,1],[3,2]]
// output: [0, 1, 2, 3] or [0, 2, 1, 3]

// const edges = [];

// const inDegree = [];

// // 求顶点的入度
// for (let i = 0; i < edges.length; i++) {
//   const [a, b] = edges[i];
//   inDegree[a]++;
// }

// let queue = [];

// inDegree.forEach((val, index) => {
//   if (val === 0) {
//     queue.push(index)
//   };
// });

// const res = [];

// while (queue.length) {
//   const cur = queue.shift();
//   res.push(cur);
//   edges.forEach(edge => {
//     const [target, source] = edge;
//     if (source === cur) {
//       inDegree[target]--;
//       if (inDegree[target] == 0) {
//         queue.push(target);
//       }
//     }
//   })
// }

// console.log(res)


// 搜索

// input: [[0,1],[1,2],[2,3],[3,1]]
// output: [1,2,3,1]

// const edges = [[0,1],[1,2],[2,3],[3,1]];

// const vis = [0, 0, 0, 0];

// const targets = [[], [], [], []];

// edges.forEach(edge => {
//   const [source, target] = edge;
//   targets[source].push(target);
// })

// // console.log(targets)

// const queue = [];

// const dfs = source => {
//   if (targets[source].length) {
//     vis[source]++;
//     queue.push(source);
//     if (vis[source] > 1) {
//       return queue;
//     }
//     targets[source].forEach(target => {
//       dfs(target);
//     })
//   }
// }

// dfs(0);

// console.log(queue);

// Example

// Input:
// 4 5
// 1 3
// 2 1
// 2 4
// 3 2
// 3 4

// Output:
// 4
// 2 1 3 2

// const v = 4, e = 5;
// const edges = [[1,3], [2,1], [2,4], [3,2], [3,4]];

// const n = 6, m = 7;
// const edges = [[1, 2], [2, 3], [3, 1], [1, 4], [4, 6], [6, 5], [5, 4]];

// const n = 4, m = 4;
// const edges = [[1, 2], [1, 3], [1, 4], [4, 3]];

// const n = 5, m = 8;
// const edges = [
//   [5, 8],
//   [0, 1],
//   [0, 2],
//   [1, 3],
//   [2, 1],
//   [2, 5],
//   [3, 2],
//   [4, 2],
//   [5, 4]
// ];

const n = 10, m = 20;

const edges = [
  [9, 8],
  [2, 9],
  [7, 5],
  [4, 5],
  [1, 5],
  [3, 8],
  [4, 2],
  [5, 4],
  [6, 5],
  [3, 6],
  [8, 10],
  [10, 9],
  [10, 7],
  [9, 3],
  [7, 6],
  [8, 7],
  [7, 3],
  [8, 9],
  [7, 10],
  [2, 1]
];


// const n = 10, m = 20;
// const edges = [[9,8], [2,9],[7,5], [4,5],[1,5],[3,8],[4,2],[5,4],[6,5],[3,6],[8,10],[10,9],[10,7],[9,3],[7,6],[8,7],[7,3],[8,9],[7,10],[2,1]]
const pre = Array(n + 1).fill(-1);

const color = Array(n + 1).fill(0);

// 建立邻接表
const adj = [[], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], []];
edges.forEach(edge => {
  const [source, target] = edge;
  adj[source].push(target);
});

const cycles = [];

const buildCycle = (start, end) => {
  const cycle = [start];
  for (let cur = end; cur !== start; cur = pre[cur]) {
    cycle.push(cur);
  }
  cycle.push(start);
  return cycle.reverse();
}

const dfs = source => {
  color[source] = 1;
  adj[source].forEach(target => {
    if (color[target] === 0) {
      pre[target] = source;
      dfs(target);
    } else if (color[target] === 1) {
      // console.log(target, source)
      cycles.push(buildCycle(target, source));
    }
  });
  color[source] = 2;
}


for (let v = 1; v <= n; v++) {
  if (color[v] === 0) {
    dfs(v);
  }
}

console.log(cycles)


