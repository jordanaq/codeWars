(ns kata.pyramid)

(defn pyramid [n]
  (take n (map #(into [] (take (inc %) (repeat 1))) (range))))
