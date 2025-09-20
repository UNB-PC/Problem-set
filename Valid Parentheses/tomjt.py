class Solution(object):
    def isValid(self, s):
        p = 0
        b = 0
        c = 0
        ans = []
        for i in s:
          if ((i == '(') or (i == '[') or (i == '{')):
            ans.append(i)
          if (i == ')'):
            if ((len(ans) < 1) or (ans.pop() != '(')):
              return False
          if (i == ']'):
            if ((len(ans) < 1) or (ans.pop() != '[')):
              return False
          if (i == '}'):
            if ((len(ans) < 1) or (ans.pop() != '{')):
              return False
        return (len(ans) == 0)
          
