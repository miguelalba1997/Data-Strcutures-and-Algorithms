class node:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data

    def insert(self, data):
        if data < self.data:
            if self.left is None:
                self.left = node(data)
            else:
                self.left.insert(data)
        elif data > self.data:
            if self.right is None:
                self.right = node(data)
            else:
                self.right.insert(data)
        else:
            self.data = data
    
    def findvalue(self, value):
        if value < self.data:
            if self.left is None:
                return "Value Not Found"
            else:
                self.left.findvalue(value)
        elif value > self.data:
            if self.right is None:
                return "Value Not Found"
            else:
                self.right.findvalue(value)
        else:
            print(value + "Found")

    def printtree(self):
        if self.left:
            self.left.printtree()
        print(self.data)
        if self.right:
            self.right.printtree()

root = node(12)
root.insert(3)
root.insert(13)
root.insert(20)
root.insert(6)

root.printtree()
