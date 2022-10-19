defmodule FindOdd do
  def find(list) do
    list
    |> Enum.reduce( %{}, &Map.update(&2, &1, 1, fn i -> i+1 end) )
    |> Map.to_list
    |> Enum.find_value( fn {k, v} -> if( rem(v, 2) == 1, do: k) end )
  end
end