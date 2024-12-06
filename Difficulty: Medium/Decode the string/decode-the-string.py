#User function Template for python3

class Solution:
    def decodedString(self, s):
        # code here
        curNum = 0
        stack = []
        curStr = ""
        for i in s:
            if i.isdigit():
                curNum = curNum*10 + int(i)
            elif i == '[' :
                stack.append(curStr) 
                stack.append(curNum)
                curStr = ""
                curNum=0
            elif i == ']' :
                num = stack.pop()
                prevS = stack.pop()
                curStr = prevS + num*curStr
            else : 
                curStr += i
        return curStr


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input()
        
        ob = Solution()
        print(ob.decodedString(s))
        print("~")
# } Driver Code Ends