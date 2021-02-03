(ns largest-difference.core)


(defn largestDifference [data]
  "Finds the largest difference in indexes in a collection
  given that the value in the larger index is greater than
  or equal to the value in the smaller index."
  (apply max (for [start (range (count data))
                   end (reverse (range (count data)))
                   :let [diff (- end start)]
                   :when (>= (data end) (data start))]
               diff)))