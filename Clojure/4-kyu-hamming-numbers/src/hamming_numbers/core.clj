(ns hamming-numbers.core)

(defn prime? [n]
  (empty? (filter #(= 0 (mod n %)) (range 2 n))))

(defn hamming? [n]
  (if (and (not (zero? n)) (or (= 0 (mod n 2)) (= 0 (mod n 3)) (= 0 (mod n 5))))
    (loop [x 7] (if (and (prime? x) (= 0 (mod n x))) false (if (>= x (inc (quot n 2))) true (recur (inc x)))))
    (= n 1)))

(defn hamming [n]
  (nth (filter hamming? (range 1 Integer/MAX_VALUE)) n))