defmodule FindOdd do
  def find(list) do
    Enum.reduce( list, %{}, &Map.update(&2, &1, 1, fn i -> i+1 end) )
    |> Map.filter( fn {_, v} -> rem(v, 2) == 1 end )
    |> Map.keys
    |> List.first
  end
end