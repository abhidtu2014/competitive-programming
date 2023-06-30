// https://leetcode.com/problems/last-day-where-you-can-still-cross

const getKey = (i, j) => `${i},${j}`;

function latestDayToCross(row: number, col: number, cells: number[][]): number {
  const dsu = new DSU(row, col);
  let i = 0;
  const visited = new Set<number>();
  const dir = [
    [0, 1],
    [0, -1],
    [1, 0],
    [-1, 0],
  ];

  let lastRowRepresentative = -1,
    firstRowRepresentative = -1;

  const updateRepresentative = (num: number) => {
    if (num <= col) {
      // Is first Row
      if (firstRowRepresentative === -1) {
        firstRowRepresentative = dsu.find(num);
      } else {
        dsu.union(firstRowRepresentative, num);
      }
    }

    if (num >= (row - 1) * col + 1) {
      // Is Last Row
      if (lastRowRepresentative === -1) {
        lastRowRepresentative = dsu.find(num);
      } else {
        dsu.union(lastRowRepresentative, num);
      }
    }
  };

  for (i = cells.length - 1; i >= 0; i--) {
    const [x, y] = cells[i];
    const numU = dsu.map.get(getKey(x, y));
    visited.add(numU);

    // Update Row representative
    updateRepresentative(numU);

    for (let d of dir) {
      const [dx, dy] = [x + d[0], y + d[1]];
      // Invalid cells
      if (dx < 0 || dy < 0) continue;
      if (dx > row || dy > col) continue;

      const numV = dsu.map.get(getKey(dx, dy));
      if (visited.has(numV)) {
        dsu.union(numU, numV);

        if (
          firstRowRepresentative !== -1 &&
          lastRowRepresentative !== -1 &&
          dsu.isConnected(firstRowRepresentative, lastRowRepresentative)
        ) {
          return i;
        }
      }
    }
  }
  return i;
}

class DSU {
  // map i,j to number
  map: Map<string, number>;
  size: number[];
  parent: number[];

  constructor(row, col) {
    const n = row * col;
    this.size = Array(n + 1).fill(0);
    this.parent = Array(n + 1)
      .fill(-1)
      .map((_, index) => index);
    let count = 1;
    this.map = new Map<string, number>();
    for (let i = 1; i <= row; i++) {
      for (let j = 1; j <= col; j++) {
        this.map.set(getKey(i, j), count++);
      }
    }
  }
  // find by path compression
  find(u: number) {
    while (this.parent[u] !== u) {
      this.parent[u] = this.parent[this.parent[u]];
      u = this.parent[u];
    }
    return u;
  }

  isConnected(u: number, v: number) {
    const pu = this.find(u);
    const pv = this.find(v);

    return pu === pv;
  }
  // union by size
  union(u: number, v: number) {
    const pu = this.find(u);
    const pv = this.find(v);

    if (pu === pv) return;

    if (this.size[pu] < this.size[pv]) {
      this.parent[pu] = this.parent[pv];
      this.size[pv] += this.size[pu];
    } else {
      this.parent[pv] = this.parent[pu];
      this.size[pu] += this.size[pv];
    }
  }
}
