(ns kata)

(defn score [dice]
  (let [[[_ x] [_ y] & z] (map #(vector % (count (filter #{%} dice))) [1 5 2 3 4 6])]
    (+ (if (>= x 3) 1000 0)
       (* (mod x 3) 100)
       (if (>= y 3) 500 0)
       (* (mod y 3) 50)
       (apply + (map #(if (>= (second %) 3) (* (first %) 100) 0) z)))))
