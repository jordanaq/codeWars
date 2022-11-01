defmodule ParenthesesValidator do
  # An empty string has valid parenthesis
  defp vp("", acc),                         do: acc == 0
  
  # Catch when first char is opening brackets, increment acc
  defp vp("(" <> tail, acc),                do: vp tail, acc+1
  
  # Catch when first char is closing brackets and acc doesn't match
  defp vp(")" <> _tail, acc) when acc <= 0, do: false
  
  # Catch when head is ")" and it is valid
  defp vp(")" <> tail, acc),                do: vp tail, acc-1
  
  # Catches when head isn't parentheses, ignores head
  defp vp(<<_head, tail::binary>>, acc),    do: vp tail, acc
  
  # Entry point, determines if string contains valid parenthesis
  def valid_parentheses(string), do: vp(string, 0)
end
