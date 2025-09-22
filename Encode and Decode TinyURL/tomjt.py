class Codec:

    def encode(self, longUrl: str) -> str:
        encoded = " "
        for c in longUrl:
            val = ord(c)
            encoded = encoded + str(val) + " "
        return encoded

    def decode(self, shortUrl: str) -> str:
        decoded = ""
        val = ""
        for c in str(shortUrl):
            if c == " ":
                if val:
                    decoded = decoded + chr(int(val))
                    val = ""
            else:
                val = val + c
        return decoded
        
codec = Codec()
print(codec.decode(codec.encode("https://leetcode.com/problems/design-tinyurl")))
