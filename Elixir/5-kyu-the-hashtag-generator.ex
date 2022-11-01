defmodule Hashtag do
  # Catch empty string
  defp return_str(""), do: false
  
  # Catch when there are more than 140 characters, assumed single byte chars
  defp return_str(str) when byte_size(str) >= 140, do: false
  
  # Retrun str prepended with a hashtag otherwise
  defp return_str(str), do: "#" <> str
  
  # Takes an input string and generates a proper capitalized hashtag
  def generate(input) do
    input
    |> String.split(" ", trim: true)
    |> Enum.map_join(&String.capitalize/1)
    |> return_str
  end
end
