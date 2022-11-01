defmodule Hashtag do
  defp return_str(""), do: false
  defp return_str(str) when byte_size(str) >= 140, do: false
  defp return_str(str), do: "#" <> str
  
  def generate(input) do
    input
    |> String.split(" ", trim: true)
    |> Enum.map_join(&String.capitalize/1)
    |> return_str
  end
end
