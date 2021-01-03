(ns kata.pyramid)

(defn pyramid [n]
  (take n (map #(vector (take % (repeat 1))) (range))))
