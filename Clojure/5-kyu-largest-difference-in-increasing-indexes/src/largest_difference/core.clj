(ns largest-difference.core)


(defn largestDifference [data]
  (apply max (for [start (range (count data))
                   end (reverse (range (count data)))
                   :let [diff (- end start)]
                   :when (>= (data end) (data start))]
               diff)))