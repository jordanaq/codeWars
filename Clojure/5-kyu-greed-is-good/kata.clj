(ns kata)

(defn score [dice]
  (let [[[_ x] [_ y] & z] (map #(vector % (count (filter #{%} dice))) [1 5 2 3 4 6])]
    (+ (* (quot x 3) 1000)
       (* (mod x 3) 100)
       (* (quot y 3) 500)
       (* (mod y 3) 50)
       (apply + (map #(if (>= (second %) 3) (* (first %) 100) 0) z)))))
