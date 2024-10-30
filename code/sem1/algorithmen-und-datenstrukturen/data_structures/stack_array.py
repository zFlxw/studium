class FixedSizeStack:
    def __init__(self, size):
        self.stack = [None] * size
        self.length = size
        self.top = -1
        self.count = 0

    def push(self, data):
        self.top = (self.top + 1) % self.length
        self.stack[self.top % self.length] = data

    def pop(self):
        if self.top == 0:
            return None

        popped = self.stack[self.top]
        self.top -= 1

        return popped

    def size(self):
        return self.top


def main():
    stack = FixedSizeStack(10)

    stack.push(1)
    stack.push(14)
    stack.push(22)

    print(f"Size (tracked): {stack.size()}")

    print(f"Popped Element: {stack.pop()}")

    print(f"Size (tracked): {stack.size()}")


if __name__ == "__main__":
    main()
