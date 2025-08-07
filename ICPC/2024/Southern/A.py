class BinaryIndexedTree3D:
    def __init__(self, n):
        self.n = n
        self.tree = [[[0 for _ in range(n+1)] for _ in range(n+1)] for _ in range(n+1)]
    
    def update(self, x, y, z, val):
        while x <= self.n:
            y1 = y
            while y1 <= self.n:
                z1 = z
                while z1 <= self.n:
                    self.tree[x][y1][z1] += val
                    z1 += z1 & (-z1)
                y1 += y1 & (-y1)
            x += x & (-x)
    
    def query(self, x, y, z):
        total = 0
        while x > 0:
            y1 = y
            while y1 > 0:
                z1 = z
                while z1 > 0:
                    total += self.tree[x][y1][z1]
                    z1 -= z1 & (-z1)
                y1 -= y1 & (-y1)
            x -= x & (-x)
        return total
    
    def range_query(self, x1, y1, z1, x2, y2, z2):
        return (self.query(x2, y2, z2) - self.query(x1-1, y2, z2) - 
                self.query(x2, y1-1, z2) - self.query(x2, y2, z1-1) + 
                self.query(x1-1, y1-1, z2) + self.query(x1-1, y2, z1-1) + 
                self.query(x2, y1-1, z1-1) - self.query(x1-1, y1-1, z1-1))

def solve_power_grid():
    T = int(input())
    for _ in range(T):
        n, m = map(int, input().split())
        bit = BinaryIndexedTree3D(n)
        
        for _ in range(m):
            operation = input().split()
            if operation[0] == 'UPDATE':
                x, y, z, W = map(int, operation[1:])
                old_val = bit.range_query(x, y, z, x, y, z)
                bit.update(x, y, z, W - old_val)
            elif operation[0] == 'QUERY':
                x1, y1, z1, x2, y2, z2 = map(int, operation[1:])
                result = bit.range_query(x1, y1, z1, x2, y2, z2)
                print(result)

if __name__ == "__main__":
    solve_power_grid()
