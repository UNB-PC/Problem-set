class Solution:
    def carFleet(self, target, position, speed):
        tsPair = sorted(zip(position,speed))
        timeTaken = []
        for pos,speed in tsPair[::-1]:
            print('car info: (S,P):',speed,',',pos)
            x = (target - pos) / speed
            timeTaken.append(x)
            if (len(timeTaken) > 1 and timeTaken[-1] <= timeTaken[-2]):
                timeTaken.pop()
        return len(timeTaken)
