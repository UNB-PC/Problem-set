isValid :: String -> Bool
isValid =
  null . foldr helper []
  where
    helper :: Char -> [Char] -> [Char] 
    helper '(' (')' : xs) = xs
    helper '[' (']' : xs) = xs
    helper '{' ('}' : xs) = xs
    helper x xs = x : xs 
