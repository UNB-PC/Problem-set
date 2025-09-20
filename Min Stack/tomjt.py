class MinStack:

    def __init__(self):
        self.stack = []
        self.mins = []

        

    def push(self, val):
        if not self.mins or val < self.mins[-1]:
            self.mins.append(val)
        else:
            self.mins.append(self.mins[-1])
        self.stack.append(val)
        

    def pop(self):
        self.stack = self.stack[:-1]
        self.mins = self.mins[:-1]
        

    def top(self):
        return self.stack[len(self.stack)-1]
        
    
    def getMin(self):
        return self.mins[len(self.mins)-1]
