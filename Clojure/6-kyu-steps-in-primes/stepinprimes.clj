(ns stepinprimes)

(defn step [g m n]
  (def res nil)
  (def rng (filter prime? (range m n)))
  (loop [n1 (next rng)]
    (println (first n1))
    (def res (some #{(- (first n1) g)} rng))
    (if (and (second n1) (not res)) (recur (next n1))))
  (vector res (+ res g))
)

(defn prime? [x]
  (def res false)
  (if (> x 2)
    (loop [n 2]
      (if (<= n (Math/sqrt x))
             (if (not= (mod x n) 0)
               (recur (inc n)))
             (def res true))))
  res
) 
