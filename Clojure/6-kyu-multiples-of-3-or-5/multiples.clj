(ns multiples)

(defn solution [number]
  (apply + (filter #(or (= 0 (mod % 3)) (= 0 (mod % 5))) (range 3 number))))
