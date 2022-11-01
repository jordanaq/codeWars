defmodule Hashtag do
  defp valid_len(str), do: String.length(str) < 140
  defp gen(""), do: false
  defp gen(input) do
    input
    |> String.split
    |> Enum.map_join(&String.capitalize/1)
    |> (&(if valid_len(&1), do: "#" <> &1, else: false)).()
  end
  def generate(input), do: gen(String.trim input)
end
