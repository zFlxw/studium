class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Stack:
    def __init__(self):
        self.top_of_stack: Node = None
        self.count = 0

    def push(self, data):
        node = Node(data)
        node.next = self.top_of_stack
        self.top_of_stack = node
        self.count += 1

    def pop(self):
        data = self.top_of_stack.data
        old_top = self.top_of_stack
        self.top_of_stack = self.top_of_stack.next
        del old_top
        self.count -= 1

        return data

    def size(self):
        return self.count

    def recalc_size(self):
        count = 0
        current = self.top_of_stack
        while current is not None:
            count += 1
            current = current.next

        return count


def main():
    stack = Stack()

    stack.push(1)
    stack.push(14)
    stack.push(22)

    print(f"Size (tracked): {stack.size()}")
    print(f"Size (calculated): {stack.recalc_size()}")
    print(f"Top Element: {stack.top_of_stack.data}")

    print(f"Popped Element: {stack.pop()}")

    print(f"Size (tracked): {stack.size()}")
    print(f"Size (calculated): {stack.recalc_size()}")
    print(f"Top Element: {stack.top_of_stack.data}")


if __name__ == "__main__":
    main()
